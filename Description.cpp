
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
    if (file_open() == -2)
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