
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
    char names[][] = { "������", "����������", "���� ������", "����������", "����������������" };
    int counter_p = 0, int counter_m = 0, int counter_d = 0, int counter_e = 0, int counter_pr = 0;
    printf("\n\n-----------------------------------------------------\n");
    printf("| ������ ������������� � ������� �� ������������... |\n");
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
        printf("\n %d. %s (���������� �������� - %d) .\n", g + 1, names[g], top[g]);
    }
}

int file_open(FILE * file, char* NameOfFile)
{
    err = fopen_s(&file, NameOfFile, "a+");
    if (!file)
    {
        printf("������ ��� ������ � ������ (��� �������� ��� ��������) .\n");
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
    printf("| ������������ ���������� �������� � ��������... |\n");
    printf("--------------------------------------------------\n");
    printf("����� ���������� �������� �� ������� ��������?");
    scanf_s("%d", &n);
    int count = 0;
    while (count < n)
    {
        printf("������ ������ %d-��� ��������...\n", count + 1);
        puts("������� ������� �������� : \n");
        fflush(stdin);
        getchar();
        gets_s(buffer.name);
        puts("������� ����� ������ �������� :\n");
        //fflush(stdin);
        //getchar();
        scanf_s("%d", &buffer.group_number);
        puts("\n������� ������� ���� ��������.\n");
        scanf_s("%f", &buffer.average_mark);
        //faculties(buffer);
        printf("\n������? ");
        scanf_s("%d", &buffer.electives[0]);
        if (buffer.electives[0])
        {
           pushStudentToElective(phisic, buffer, PHISIC);
        }
        printf("\n����������������? ");
        scanf_s("%d", &buffer.electives[1]);
        if (buffer.electives[1])
        {
            pushStudentToElective(programming, buffer, PROGRAMMING);
        }
        printf("\n����������? ");
        scanf_s("%d", &buffer.electives[2]);
        if (buffer.electives[2])
        {
            pushStudentToElective(math, buffer, MATH);
        }
        printf("\n���������� ����? ");
        scanf_s("%d", &buffer.electives[3]);
        if (buffer.electives[3])
        {
            pushStudentToElective(english, buffer, ENGLISH);
        }
        printf("\n���� ������? ");
        scanf_s("%d", &buffer.electives[4]);
        if (buffer.electives[4])
        {
            pushStudentToElective(database, buffer, DATABASE);
        }
        printf("\n������ %d-�� ���������� ���� �������� � �������� ����.\n", count + 1);
        fwrite(&buffer, sizeof(buffer), 1, data); //������ �������
        count++;
        stud++;
    }
    fclose(data);
    printf("\n�������� ����, ��������� �� ��������� ��������� ��� ������� �����������.\n");
    stud++;
    return 0;
}

void TableStudent()
{
    bool flag = false;
    if (file_open(data, ALLDATA) == -2)
    {
        printf("���� �� ��� �����������. �������� ��� ��� ������������.\n");
    }
    if (false) //��������� �� ������� ����
    {
        printf("\n\n--------------------------------------------------------------\n");
        printf(    "| � ������� �� ���� ������� �����-���� �������� � ���������. |\n");
        printf(    "--------------------------------------------------------------\n");
    }
    else
    {
        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf(    "|                                        � ������� ���������� ��������� �������� � ���������  :                                        |");
        printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\n\n+--------------------------------------------------------------------------------------------------------------------------------+\n");
        printf("| ������� �������� |  ����� ������ |  ������� ����  | ������ | ���������������� |  ����������  | ���������� ���� |  ���� ������  |\n");
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
    char string[] = "������";
    char string1[] = "����������������";
    char string2[] = "����������";
    char string3[] = "����������";
    char string4[] = "���� ������";
    printf(  "--------------------------------------------------------------\n");
    printf(  "| �������� �����������, ���� ��������� ������� ����������� : |");
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
        printf("���� �� ��� �����������. �������� ��� ��� ������������.\n");
        flag = true;
    }
    if (false) //��������� �� ������� ����
    {
        printf("\n\n-----------------------------------------------------------------------------------\n");
        printf("| � ������� �� ���� ������� �����-���� �������� � ��������� ������� ������������. |\n");
        printf("-----------------------------------------------------------------------------------\n");
    }
    else
    {
        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf(    "|                                        ����������� *%15s* ( ������������� : %15s )  :                                                |\n", Elective, teacher_ph.name);
        printf(  "\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\n\n+--------------------------------------------------------------------------------------------------------------------------------+\n");
        printf("| ������� �������� |  ����� ������ |  ������� ����  | ������ | ���������������� |  ����������  | ���������� ���� |  ���� ������  |\n");
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
    printf("*   1 - ������. \n");
    printf("*   2 - ����������������. \n");
    printf("*   3 - ����������. \n");
    printf("*   4 - ���������� ����. \n");
    printf("*   5 - ���� ������. \n*");
    printf("\n**********************************************************************************\n");
    yourChoice = _getch();
    return yourChoice;
}

