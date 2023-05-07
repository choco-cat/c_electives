
#include "Prototypes and Classes.h"

 char ALLDATA[] = "DataOfStudent.bin";
 char PHISIC[] = "DataOfPhisic.bin";
 char PROGRAMMING[] = "DataOfProgramming.bin";
 char MATH[] = "DataOfMath.bin";
 char ENGLISH[] = "DataOfEnglish.bin";
 char DATABASE[] = "DataOfDatabase.bin";

const int SIZE_OF_ELECTIVE = 4;
static int stud = 0;
FILE* data;
errno_t err;
static int count_of_student = 0;
Student buffer;

FILE* phisic, * math, * english, * database, * programming;

Teacher teacher_ph, teacher_ma, teacher_en, teacher_da, teacher_pr;

void topOfElective()
{
    int buffer;
    char pointer[30];
    int top = { 0,0,0,0,0 };
    char names[][] = { "Физика", "Математика", "Базы данных", "Английский", "Программирование" };
    int counter_p = 0, int counter_m = 0, int counter_d = 0, int counter_e = 0, int counter_pr = 0;
    printf("\n\n-----------------------------------------------------\n");
    printf("| Список ФАКУЛЬТАТИТОВ в порядке их популярности... |\n");
    printf("-----------------------------------------------------\n");
    file_open(phisic, "DataOfPhisic.bin");
    file_open(math, "DataOfMath.bin");
    file_open(database, "DataOfDatabase.bin");
    file_open(english, "DataOfEnglish.bin");
    file_open(programming, "DataOfProgramming.bin");
    while (fread(&buffer, sizeof(buffer), 1, phisic) > 0)
    {
        top[0]++;
    }
    while (fread(&buffer, sizeof(buffer), 1, math) > 0)
    {
        top[1]++;
    }
    while (fread(&buffer, sizeof(buffer), 1, database) > 0)
    {
        top[2]++;
    }
    while (fread(&buffer, sizeof(buffer), 1, english) > 0)
    {
        top[3]++;
    }
    while (fread(&buffer, sizeof(buffer), 1, programming) > 0)
    {
        top[4]++;
    }
    fclose(phisic);
    fclose(math);
    fclose(database);
    fclose(english);
    fclose(programming);
    for (register int i = 0; i < 5; i++)
    {
        for (register int j = 1; j < 5; j++)
        {
            if (top[j] > top[j - 1])
            {
                buffer = top[j - 1];
                top[j - 1] = top[j];
                top[j] = buffer;
                pointer = names[j - 1];
                names[j - 1] = names[j];
                names[j] = pointer;
            }
        }
    }
    for (register int g = 0; g < 5; g++)
    {
        printf("\n %d. %s (Количество желающих - %d) .\n", g + 1, names[g], top[g]);
    }
}

int file_open(FILE * file, char* NameOfFile)
{
    err = fopen_s(&file, NameOfFile, "a+");
    if (!file)
    {
        printf("Ошибка при работе с файлом (его создании или открытии) .\n");
        return -2;
    }
    return 0;
}

int AddStudent()
{
    int n;
    if (file_open(data, ALLDATA) == -2)
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
        if (buffer.electives[0])
        {
           pushStudentToElective(phisic, buffer, PHISIC);
        }
        printf("\nПрограммирование? ");
        scanf_s("%d", &buffer.electives[1]);
        if (buffer.electives[1])
        {
            pushStudentToElective(programming, buffer, PROGRAMMING);
        }
        printf("\nМатематика? ");
        scanf_s("%d", &buffer.electives[2]);
        if (buffer.electives[2])
        {
            pushStudentToElective(math, buffer, MATH);
        }
        printf("\nАнглийский язык? ");
        scanf_s("%d", &buffer.electives[3]);
        if (buffer.electives[3])
        {
            pushStudentToElective(english, buffer, ENGLISH);
        }
        printf("\nБазы данных? ");
        scanf_s("%d", &buffer.electives[4]);
        if (buffer.electives[4])
        {
            pushStudentToElective(database, buffer, DATABASE);
        }
        printf("\nДанные %d-ой информации были записаны в бинарный файл.\n", count + 1);
        fwrite(&buffer, sizeof(buffer), 1, data); //запись целиком
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
    if (file_open(data, ALLDATA) == -2)
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

int look()
{
    char string[] = "Физика";
    char string1[] = "Программирование";
    char string2[] = "Математика";
    char string3[] = "Английский";
    char string4[] = "Базы данных";
    printf(  "--------------------------------------------------------------\n");
    printf(  "| Выберите факультатив, чьих студентов желаете просмотреть : |");
    printf("\n--------------------------------------------------------------");
    while (true)
    {
        switch (list())

        {
        case '1':
            
            TableStudentOfElective(phisic,PHISIC, string);
            break;
        case '2':
            
            TableStudentOfElective(programming, PROGRAMMING, string1);
            break;
        case '3':
            
            TableStudentOfElective(math, MATH, string2);
            break;
        case '4':
            
            TableStudentOfElective(english, ENGLISH, string3);
            break;
        case '5':
           
            TableStudentOfElective(database, DATABASE, string4);
            break;
        }
    }
}

int pushStudentToElective(FILE * file, Student student, char* NameOfFile)
{
    if (file_open(file, NameOfFile) == -2)
    {
    return 0;
    }
    fwrite(&student, sizeof(student), 1, file);
    fclose(file);
}

void TableStudentOfElective(FILE* file, char* NameOfFile, char* Elective)
{
    bool flag = false;
    if (file_open(file, NameOfFile) == -2)
    {
        printf("Файл не был сформирован. Попросим вас его сформировать.\n");
        flag = true;
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
        printf(    "|                                        Факультатив *%15s* ( Преподаватель : %15s )  :                                                |\n", Elective, teacher_ph.name);
        printf(  "\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\n\n+--------------------------------------------------------------------------------------------------------------------------------+\n");
        printf("| Фамилия студента |  Номер группы |  Средний балл  | Физика | Программирование |  Математика  | Английский язык |  Базы данных  |\n");
        printf("----------------------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&buffer, sizeof(buffer), 1, file) > 0)
        {
            printf("|   %15s|   %12d| %15.3f|    %4d|             %5d|    %10d|   %14d|        %7d|\n", buffer.name, buffer.group_number, buffer.average_mark, buffer.electives[0], buffer.electives[1], buffer.electives[2], buffer.electives[3], buffer.electives[4]);
            printf("----------------------------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(file);
    system("pause");
}

int list()
{
    char yourChoice;
    printf("\n**********************************************************************************\n");
    printf("*   1 - физика. \n");
    printf("*   2 - программирование. \n");
    printf("*   3 - математика. \n");
    printf("*   4 - английский язык. \n");
    printf("*   5 - базы данных. \n*");
    printf("\n**********************************************************************************\n");
    yourChoice = _getch();
    return yourChoice;
}

