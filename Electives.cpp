#include "Prototypes and Classes.h"
char ALLDATA[6][2][30] = { {"DataOfPhisic.bin", "Физика"}, {"DataOfProgramming.bin", "Программирование"},  {"DataOfMath.bin", "Математика"} , {"DataOfEnglish.bin", "Английский язык"}, {"DataOfDatabase.bin", "Базы данных"}};
Student buff;
FILE* file;
Teacher teacher_ph, teacher_ma, teacher_en, teacher_da, teacher_pr;

int file_open_e(char *NameOfFile)
{
    fopen_s(&file, NameOfFile, "a+");
    if (!file)
    {
        printf("Ошибка при работе с файлом (его создании или открытии) .\n");
        return -1;
    }
    return 1;
}

int file_open(char* NameOfFile)
{
    fopen_s(&file, NameOfFile, "r+b");
    if (!file)
    {
        printf("Ошибка при работе с файлом (его создании или открытии) .\n");
        return -1;
    }
    return 1;
}

int look()
{
    int keyOfElective = 0;
    printf("--------------------------------------------------------------\n");
    printf("| Выберите факультатив, чьих студентов желаете просмотреть : |");
    printf("\n--------------------------------------------------------------");

    do {
        int keyOfElective = list();
        if (keyOfElective > 0 && keyOfElective <= SIZE_OF_ELECTIVE) {
            char* electiveFile = ALLDATA[keyOfElective - 1][0];
            char* electiveName = ALLDATA[keyOfElective - 1][1];
            if (!file_open_e(electiveFile))
            {
                return 0;
            }
            TableStudentOfElective(file, electiveName);
            fclose(file);
        }
    } while (keyOfElective != 0);
}

int pushStudentToElective( Student student, int indexElective)
{
    if (!file_open_e(ALLDATA[indexElective][0]))
    {
        return 0;
    }
    fwrite(&student, sizeof(student), 1, file);
    fclose(file);
    return 1;
}

int deleteStudentFromElective(char* name_to_delete, int indexElective)
{
    if (!file_open(ALLDATA[indexElective][0]))
    {
        return 0;
    }
    int struct_size = sizeof(buff);
    int deleted = 0; // флаг, который будет установлен в 1, если найдена и удалена запись
    int position_to_delete = 0;
    // читаем записи из файла
    int count = 0;

    while (fread(&buff, struct_size, 1, file)) {
        count++;
        // если имя совпадает, помечаем запись на удаление
        if (strcmp(buff.name, name_to_delete) == 0) {
            position_to_delete = ftell(file) - struct_size; // запоминаем позицию записи
            printf("позиция для удаления %d\n", position_to_delete);
            deleted = 1;
            break;
        }
    }
    
    fseek(file, position_to_delete + struct_size, SEEK_SET);

    // считываем все записи структур, начиная со следующей за удаляемой записью, на одну позицию назад
    while (fread(&buff, struct_size, 1, file) == 1) {
        fseek(file, (count - 1) * struct_size, SEEK_SET); // перемещаем указатель текущей позиции на одну позицию назад
        fwrite(&buff, struct_size, 1, file); // записываем считанную запись на одну позицию раньше
        fseek(file, (count + 1) * struct_size, SEEK_SET); // перемещаем указатель текущей позиции на следующую запись
        count++;
    }

    // устанавливаем конец файла на место последней записи, которую нужно удалить
    if (deleted) {
        _chsize(_fileno(file), (count - 1) * struct_size);
    }

    fclose(file);
    return 0;
}

void TableStudentOfElective(FILE* file, char* Elective)
{
    bool flag = false;
   
    if (false) //проверить на пустоту файл
    {
        printf("\n\n-----------------------------------------------------------------------------------\n");
        printf("| В системе не были найдены какие-либо сведения о студентах ДАННОГО факультатива. |\n");
        printf("-----------------------------------------------------------------------------------\n");
    }
    else
    {
        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|                                        Факультатив *%15s* ( Преподаватель : %15s )  :                                                |\n", Elective, teacher_ph.name);
        printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\n\n+--------------------------------------------------------------------------------------------------------------------------------+\n");
        printf("| Фамилия студента |  Номер группы |  Средний балл  | Физика | Программирование |  Математика  | Английский язык |  Базы данных  |\n");
        printf("----------------------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&buff, sizeof(buff), 1, file) > 0)
        {
            printf("|   %15s|   %12d| %15.3f|    %4d|             %5d|    %10d|   %14d|        %7d|\n", buff.name, buff.group_number, buff.average_mark, buff.electives[0], buff.electives[1], buff.electives[2], buff.electives[3], buff.electives[4]);
            printf("----------------------------------------------------------------------------------------------------------------------------------\n");
        }
    }
    system("pause");
}

int list()
{
    int yourChoice;
    printf("\n**********************************************************************************\n");
    for (int i = 0; i < SIZE_OF_ELECTIVE; i++) {
        printf("*   %d - %s. \n", i + 1,  ALLDATA[i][1]);
    }
    printf("*   0 - выход из меню. \n*");
    printf("\n**********************************************************************************\n");
    scanf_s("%d", &yourChoice);
    return yourChoice;
}

void topOfElective()
{
    int num_records[SIZE_OF_ELECTIVE][2];
    int buffer[2];
    printf("| Список ФАКУЛЬТАТИТОВ в порядке их популярности... |\n");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < SIZE_OF_ELECTIVE; i++) {
        if (!file_open_e(ALLDATA[i][0]))
        {
            continue;
        }
        fseek(file, 0, SEEK_END); // перейти в конец файла
        long file_size = ftell(file); // получить размер файла в байтах
        num_records[i][0] = i;
        num_records[i][1] = file_size / sizeof(buff); // вычислить количество записей
        fclose(file);
    }

    for (int i = 0; i < SIZE_OF_ELECTIVE - 1; i++) {
        for (int j = 0; j < SIZE_OF_ELECTIVE - i - 1; j++) {
            if (num_records[j][1] < num_records[j + 1][1]) {
                buffer[0] = num_records[j][0];
                buffer[1] = num_records[j][1];
                num_records[j][0] = num_records[j + 1][0];
                num_records[j][1] = num_records[j + 1][1];
                num_records[j + 1][0] = buffer[0];
                num_records[j + 1][1] = buffer[1];
            }
        }
    }

    for (int i = 0; i < SIZE_OF_ELECTIVE; i++) {
        printf("\n %d. %s (Количество желающих - %d).\n", i + 1, ALLDATA[num_records[i][0]][1], num_records[i][1]);
    }
}
