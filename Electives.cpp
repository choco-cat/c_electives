#include "Prototypes and Classes.h"
char ALLDATA[6][2][30] = { {"DataOfPhisic.bin", "Физика"}, {"DataOfProgramming.bin", "Программирование"},  {"DataOfMath.bin", "Математика"} , {"DataOfEnglish.bin", "Английский язык"}, {"DataOfDatabase.bin", "Базы данных"}};
Student buff;
FILE* file;
Teacher teacher_ph, teacher_ma, teacher_en, teacher_da, teacher_pr;

int file_open(char* NameOfFile, int countBytes = 0, int offset = SEEK_SET)
{
   fopen_s(&file, NameOfFile, "rb+");

    if (!file)
    {
        fopen_s(&file, NameOfFile, "a+");
        if (!file) {
            printf("Ошибка при работе с файлом %s (его создании или открытии) .\n", NameOfFile);
        }
        return 0;
    }
    fseek(file, countBytes, offset);
    return 1;
}

int lookElecive()
{
    int keyOfElective = 0;
    int n; // количество считанных чисел
    int id;
    int* arrIds = (int*)malloc(1000 * sizeof(int)); // выделение памяти под массив размером 1000 элементов
     
    printf("--------------------------------------------------------------\n");
    printf("| Выберите факультатив, чьих студентов желаете просмотреть : |");
    printf("\n--------------------------------------------------------------");

    do {
        int keyOfElective = list();
        n = 0;
        memset(arrIds, 0, sizeof(arrIds)); // заполнение массива нулями
        char* electiveFile = ALLDATA[keyOfElective - 1][0];
        char* electiveName = ALLDATA[keyOfElective - 1][1];
        if (keyOfElective > 0 && keyOfElective <= SIZE_OF_ELECTIVE) {
            if (!file_open(electiveFile))
            {
                continue;
            }

            while (fscanf_s(file, "%d", &arrIds[n]) && n < 1000) {
                n++;
            }
            fclose(file);

            TableStudentOfElective(arrIds, electiveName, n);
        }
    } while (keyOfElective != 0);
    return 1;
}

int pushStudentToElective(int studentId, int indexElective)
{
    int id;
    if (!file_open(ALLDATA[indexElective][0]))
    {
        return 0;
    }

    while (fscanf_s(file, "%d", &id) != EOF) {
        if (id == studentId) {
            // Нашли id, студент уже записан на факультатив
            fclose(file);
            return 0;
        }
    }

    fprintf(file, "%d\n", studentId); // Записываем число в файл
    fclose(file);
    return 1;
}

int deleteStudentFromElective(int studentId, int indexElective)
{
    FILE* temp_file;
    fopen_s(&temp_file, "temp.bin", "w");

    if (!file_open(ALLDATA[indexElective][0]))
    {
        return 0;
    }
    int struct_size = sizeof(buff);
    int num_deleted = 0; // флаг, который будет установлен в 1, если найдена и удалена запись
    int id;
    // читаем записи из файла
    int count = 0;

    // Читаем по одному числу из входного файла
    while (fscanf_s(file, "%d", &id) != EOF) {
        if (id == studentId) {
            // Нашли число, которое нужно удалить
            num_deleted++;
            continue;  // Пропускаем запись числа во временный файл
        }

        // Записываем числа, которые не нужно удалять, во временный файл
        fprintf(temp_file, "%d\n", id);
    }

    fclose(file);
    fclose(temp_file);

    // Заменяем входной файл временным
    if (num_deleted > 0) {
        if (remove(ALLDATA[indexElective][0]) != 0) {
            perror("Не удалось удалить входной файл");
            return -1;
        }
        if (rename("temp.bin", ALLDATA[indexElective][0]) != 0) {
            perror("Не удалось переименовать временный файл");
            return -1;
        }
    }
    else {
        // Если ни одно число не было удалено, удаляем временный файл
        remove("temp.bin");
    }

     return 0;
}

void TableStudentOfElective(int* arrIds, char* electiveName, int size)
{
    if (!file_open(STUDENTS_DATA))
    {
        return;
    }

    if (false) //проверить на пустоту файл
    {
        printf("\n\n-----------------------------------------------------------------------------------\n");
        printf("| В системе не были найдены какие-либо сведения о студентах ДАННОГО факультатива. |\n");
        printf("-----------------------------------------------------------------------------------\n");
    }
    else
    {
        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|                                        Факультатив *%15s* ( Преподаватель : %15s )  :                                                |\n", electiveName, teacher_ph.name);
        printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        
        printStudentTableHeader();
        int couner = 0;
        while (fread(&buff, sizeof(buff), 1, file) > 0)
        {
            if (contains(arrIds, size, buff.id)) {
                couner++;
                printStudentTableRow(couner, buff);
            }
        }
    }
    fclose(file);
    system("pause");
}

int contains(int arr[], int size, int x) {
    for (int i = 0; i <= size; i++) {
        if (arr[i] == x) {
            return 1; // массив содержит число x
        }
    }
    return 0; // массив не содержит число x
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
    char line[5];
    int num_lines;
    printf("| Список ФАКУЛЬТАТИТОВ в порядке их популярности... |\n");
    printf("-----------------------------------------------------\n");

   
    for (int i = 0; i < SIZE_OF_ELECTIVE; i++) {
        num_lines = 0;
        if (!file_open(ALLDATA[i][0]))
        {
            continue;
        }
        
        while (fgets(line, sizeof(line), file) != NULL) {
            num_lines++;
        }
        num_records[i][0] = i;
        num_records[i][1] = num_lines; // вычислить количество записей
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
