
#include "Prototypes and Classes.h"

const int SIZE_OF_ELECTIVE = 4;
static int stud = 0;
FILE* data;
errno_t err;
static int count_of_student = 0;
Student buffer;

void faculties(Student buffer)
{
    int number;
    int count_of_faculties;
    printf("\n\n----------------------------------\n");
    printf(    "| Список доступных факультативов |\n");
    printf(    "----------------------------------\n");
    printf("\n***********************************************\n*\n");
    printf("*   1 -  дисциплина 'физика'.\n");
    printf("*   2 -  дисциплина 'программирование'.\n");
    printf("*   3 -  дисциплина 'математика'.\n");
    printf("*   4 -  дисциплина 'английский язык'.\n");
    printf("*   5 -  дисциплина 'базы данных'.\n");
    printf("\n***********************************************\n");
    printf("\nНа какое количество факультативов вы желаете записаться? ");
    scanf_s("%d", &count_of_faculties);
    printf("\nУкажите их номера в привиденной таблице.");
    for (register int i = 0; i < count_of_faculties; i++)
    {
        scanf_s("%d", &number);
        //buffer.electives[number - 1] = 1;
        printf("\nДисциплина под номером %d была успешно добавлена в список желаемых.", number );
    }
}

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
    }
    fclose(data);
    printf("\nБинарный файл, состоящий из элементов структуры был успешно сформирован.\n");
    stud++;
    return 0;
}

int PrintStudent()
{
    if (file_open() == -2)
    {
        printf("Файл не был сформирован. Попросим вас его сформировать.\n");
    }
    int i = 1;
    while (fread(&buffer, sizeof(buffer), 1, data) > 0)
    {
        printf("Запись данных %d-ого студента...\n", i);
        printf("\n Имя студента : ");
        printf("%s", buffer.name);
        printf("\n Номер группы студента : ");
        printf("%d", buffer.group_number);
        printf("\n Средний балл студента : ");
        printf("%f", buffer.average_mark);
        printf("\n%d - дисциплина 'физика'.", buffer.electives[0]);
        printf("\n%d - дисциплина 'программирование'.", buffer.electives[1]);
        printf("\n%d - дисциплина 'математика'.", buffer.electives[2]);
        printf("\n%d - дисциплина 'английский язык'.", buffer.electives[3]);
        printf("\n%d - дисциплина 'базы данных'.", buffer.electives[4]);
        i++;
    }
    if (i == 1)
    {
        printf("Файл не существует или не содержит данных.\n");
    }
    fclose(data);
    return 0;
}

void TableStudent()
{
   
    printf("----------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| Фамилия студента |  Номер группы |  Средний балл  | Физика | Программирование |  Математика  | Английский язык | | Базы данных |\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------\n");
    while (fread(&buffer, sizeof(buffer), 1, data) > 0)
    {
        printf("| %s |    %15s|    %15f|%12d|  %15d|%15d|   %15d|%15d|\n", buffer.name, buffer.group_number, buffer.average_mark, buffer.electives[0], buffer.electives[1], buffer.electives[2], buffer.electives[3], buffer.electives[4]);
        printf("----------------------------------------------------------------------------------------------------------------------------------\n");
    }
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