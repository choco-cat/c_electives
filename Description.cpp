
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