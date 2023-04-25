
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
    printf(    "| ������ ��������� ������������� |\n");
    printf(    "----------------------------------\n");
    printf("\n***********************************************\n*\n");
    printf("*   1 -  ���������� '������'.\n");
    printf("*   2 -  ���������� '����������������'.\n");
    printf("*   3 -  ���������� '����������'.\n");
    printf("*   4 -  ���������� '���������� ����'.\n");
    printf("*   5 -  ���������� '���� ������'.\n");
    printf("\n***********************************************\n");
    printf("\n�� ����� ���������� ������������� �� ������� ����������? ");
    scanf_s("%d", &count_of_faculties);
    printf("\n������� �� ������ � ����������� �������.");
    for (register int i = 0; i < count_of_faculties; i++)
    {
        scanf_s("%d", &number);
        //buffer.electives[number - 1] = 1;
        printf("\n���������� ��� ������� %d ���� ������� ��������� � ������ ��������.", number );
    }
}

int file_open()
{
    err = fopen_s(&data, "DataOfStudent.bin", "a+");
    if (!data)
    {
        printf("������ ��� ������ � ������ (��� �������� ��� ��������) .\n");
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

        printf("\n����������������? ");
        scanf_s("%d", &buffer.electives[1]);
        printf("\n����������? ");
        scanf_s("%d", &buffer.electives[2]);
        printf("\n���������� ����? ");
        scanf_s("%d", &buffer.electives[3]);
        printf("\n���� ������? ");
        scanf_s("%d", &buffer.electives[4]);
        printf("\n������ %d-�� ���������� ���� �������� � �������� ����.\n", count + 1);
        fwrite(&buffer, sizeof(buffer), 1, data);//������ �������
        count++;
    }
    fclose(data);
    printf("\n�������� ����, ��������� �� ��������� ��������� ��� ������� �����������.\n");
    stud++;
    return 0;
}

int PrintStudent()
{
    if (file_open() == -2)
    {
        printf("���� �� ��� �����������. �������� ��� ��� ������������.\n");
    }
    int i = 1;
    while (fread(&buffer, sizeof(buffer), 1, data) > 0)
    {
        printf("������ ������ %d-��� ��������...\n", i);
        printf("\n ��� �������� : ");
        printf("%s", buffer.name);
        printf("\n ����� ������ �������� : ");
        printf("%d", buffer.group_number);
        printf("\n ������� ���� �������� : ");
        printf("%f", buffer.average_mark);
        printf("\n%d - ���������� '������'.", buffer.electives[0]);
        printf("\n%d - ���������� '����������������'.", buffer.electives[1]);
        printf("\n%d - ���������� '����������'.", buffer.electives[2]);
        printf("\n%d - ���������� '���������� ����'.", buffer.electives[3]);
        printf("\n%d - ���������� '���� ������'.", buffer.electives[4]);
        i++;
    }
    if (i == 1)
    {
        printf("���� �� ���������� ��� �� �������� ������.\n");
    }
    fclose(data);
    return 0;
}

void TableStudent()
{
   
    printf("----------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| ������� �������� |  ����� ������ |  ������� ����  | ������ | ���������������� |  ����������  | ���������� ���� | | ���� ������ |\n");
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
    printf("| ���������� �������                 |");
    printf("\n--------------------------------------");
    while (true)
    {
        /*switch ()
        {

        }*/
    }
}