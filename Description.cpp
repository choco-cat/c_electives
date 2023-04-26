
#include "Prototypes and Classes.h"

const int SIZE_OF_ELECTIVE = 4;
static int stud = 0;
FILE* data;
errno_t err;
static int count_of_student = 0;
Student buffer;

int file_open()
{
    err = fopen_s(&data, "DataOfStudent.bin", "a+");
    if (!data)
    {
        printf("Ошибка при работе с файлом (его создании или открытии) .\n");
        return -2;
    }
    return 0;
}

int AddStudent()
{
    int n;
    if (file_open() == -2)
    {
        return 0;
    }
    printf("\n\n--------------------------------------------------\n");
    printf("| Осуществляем добавление сведений о студенте... |\n");
    printf("--------------------------------------------------\n");
    printf("Какое количество сведений вы желаете добавить?");
    scanf_s("%d", &n);
    int count = 0;
    while (count < n)
    {
        printf("Запись данных %d-ого студента...\n", count + 1);
        puts("Введите фамилию студента : \n");
        fflush(stdin);
        getchar();
        gets_s(buffer.name);
        puts("Введите номер группы студента :\n");
        //fflush(stdin);
        //getchar();
        scanf_s("%d", &buffer.group_number);
        puts("\nВведите средний балл студента.\n");
        scanf_s("%f", &buffer.average_mark);
        //faculties(buffer);
        printf("\nФизика? ");
        scanf_s("%d", &buffer.electives[0]);
        printf("\nПрограммирование? ");
        scanf_s("%d", &buffer.electives[1]);
        printf("\nМатематика? ");
        scanf_s("%d", &buffer.electives[2]);
        printf("\nАнглийский язык? ");
        scanf_s("%d", &buffer.electives[3]);
        printf("\nБазы данных? ");
        scanf_s("%d", &buffer.electives[4]);
        printf("\nДанные %d-ой информации были записаны в бинарный файл.\n", count + 1);
        fwrite(&buffer, sizeof(buffer), 1, data);//запись целиком
        count++;
        stud++;
    }
    fclose(data);
    printf("\nБинарный файл, состоящий из элементов структуры был успешно сформирован.\n");
    stud++;
    return 0;
}

void TableStudent()
{
    bool flag = false;
    if (file_open() == -2)
    {
        printf("Файл не был сформирован. Попросим вас его сформировать.\n");
    }
    if (false) //проверить на пустоту файл
    {
        printf("\n\n--------------------------------------------------------------\n");
        printf(    "| В системе не были найдены какие-либо сведения о студентах. |\n");
        printf(    "--------------------------------------------------------------\n");
    }
    else
    {
        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf(    "|                                        В системе существуют следующие сведения о студентах  :                                        |");
        printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\n\n+--------------------------------------------------------------------------------------------------------------------------------+\n");
        printf("| Фамилия студента |  Номер группы |  Средний балл  | Физика | Программирование |  Математика  | Английский язык |  Базы данных  |\n");
        printf("----------------------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&buffer, sizeof(buffer), 1, data) > 0)
        {
            printf("|   %15s|   %12d| %15.3f|    %4d|             %5d|    %10d|   %14d|        %7d|\n", buffer.name, buffer.group_number, buffer.average_mark, buffer.electives[0], buffer.electives[1], buffer.electives[2], buffer.electives[3], buffer.electives[4]);
            printf("----------------------------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(data);
    system("pause");
}

void SortStudent()
{
    printf("--------------------------------------\n");
    printf("| СОРТИРОВКА ЗАПИСЕЙ                 |");
    printf("\n--------------------------------------");
    while (true)
    {
        /*switch ()
        {

        }*/
    }
}