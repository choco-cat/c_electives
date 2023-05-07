#include "Prototypes and Classes.h"
#define MAX_COUNT_STUDENTS 1000

const int SIZE_OF_ELECTIVE = 4;
static int stud = 0;
FILE* data;
errno_t err;
static int count_of_student = 0;
Student buffer;

FILE* phisic, * math, * english, * database, * programming;


int file_open(int countBytes = 0, int offset = SEEK_SET)
{
    err = fopen_s(&data, "DataOfStudent.bin", " rb+");

    if (!data)
    {
        printf("������ ��� ������ � ������ (��� �������� ��� ��������) .\n");
        return 0;
    }
    fseek(data, countBytes, offset);
    return 1;
}

int editStudent()
{
    system("cls");

    char vibor = '0';
    char viborField = '0';
    int quantity = 0;
    int number = 0;

    while (true) {
        system("cls");

        puts("\t�������������� ������\n");
        int quantity = tableStudents();
        printf("1 - ������ ����� ������ ��� ��������������\n2 - ��������� � ����\n");
        do {
            vibor = _getch();
        } while (vibor < '1' || vibor > '2');

        if (vibor == '2') {
            return 0;
        }

        printf("������� ����� ������, ������� ���������� ���������������: ");
        do {
            scanf_s("%d", &number);
            fflush(stdin);
            if (number < 1 || number > quantity) {
                printf("������ � ����� ������� ���. ��������� ����: ");
            }
            else
                break;
        } while (true);


        printf("������� %d\n", number);
        if (!file_open(sizeof(Student) * (number - 1), SEEK_SET)) {
            return 0;
        }

        fread(&buffer, sizeof(Student), 1, data);
        puts("--- ��������� ������: ---\n");
        printStudentTableHeader();
        printStudentTableRow(number, buffer);
        fclose(data);

        vibor = menuEditStudent();

        if (vibor == '3') {
            fclose(data);
            return 0;
        }

        if (!file_open(sizeof(Student) * (number - 1), SEEK_SET)) {
            return 0;
        }

        // ������ �������
        if (vibor == '1') {
            insertStudentData();
        }
        else {
            viborField = menuEditStudentFields();
            insertStudentDataField(viborField);
        }

        fclose(data);

        return 1;

    }
    return 1;
}

char menuEditStudent()
{
    char vibor;
    printf("1 - �������� ����� ��� ������\n2 - �������� ��������� �������\n3 - ���������\n");
    do {
        vibor = _getch();
    } while (vibor < '1' || vibor > '3');
    return vibor;
}

char menuEditStudentFields()
{
    char element;
    printf("\n�������� ����, ������� ����� ��������:\n1 - �������\n2 - ����� ������\n3 - ������� ����\n4 - ������");
    printf("\n5 - ����������������\n6 - ����������\n7 - ���������� ����\n8 - ���� ������\n");
    do {
        element = _getch();
    } while (element < '1' || element > '8');
    return element;
}

int addStudent()
{
    int n;
    if (!file_open(0, SEEK_END)) {
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
        insertStudentData();
        printf("\n������ %d-�� ���������� ���� �������� � �������� ����.\n", count + 1);
        count++;
    }
    fclose(data);
    printf("\n�������� ����, ��������� �� ��������� ��������� ��� ������� �����������.\n");
    return 1;
}

void insertStudentData()
{
    insertStudentDataName();
    insertStudentDataGroup();
    insertStudentDataAverage();
    insertStudentDataElective_0();
    insertStudentDataElective_1();
    insertStudentDataElective_2();
    insertStudentDataElective_3();
    insertStudentDataElective_4();
    fwrite(&buffer, sizeof(buffer), 1, data);
}

void insertStudentDataField(char symbol)
{
    switch (symbol) {
    case '1':
        insertStudentDataName();
        break;

    case '2':
        insertStudentDataGroup();
        break;

    case '3':
        insertStudentDataAverage();
        break;
    case '4':
        insertStudentDataElective_0();
        break;
  
    case '5':
        insertStudentDataElective_1();
        break;

    case '6':
        insertStudentDataElective_2();
        break;

    case '7':
        insertStudentDataElective_3();
        break;

    case '8':
        insertStudentDataElective_4();
        break;
    }
    fwrite(&buffer, sizeof(buffer), 1, data);
}

void insertStudentDataName()
{
    puts("������� ������� �������� : \n");
    fflush(stdin);
    getchar();
    gets_s(buffer.name);
}

void insertStudentDataGroup()
{
    puts("������� ����� ������ �������� :\n");
    scanf_s("%d", &buffer.group_number);
}

void insertStudentDataAverage()
{
    puts("\n������� ������� ���� ��������.\n");
    scanf_s("%f", &buffer.average_mark);
}

void insertStudentDataElective_0()
{
    printf("\n������? ");
    scanf_s("%d", &buffer.electives[0]);
    if (buffer.electives[0] == 1) {
        pushStudentToElective(buffer, 0);
    }
}

void insertStudentDataElective_1()
{
    printf("\n����������������? ");
    scanf_s("%d", &buffer.electives[1]);
    if (buffer.electives[1] == 1) {
        pushStudentToElective(buffer, 1);
    }
}

void insertStudentDataElective_2()
{
    printf("\n����������? ");
    scanf_s("%d", &buffer.electives[2]);
    if (buffer.electives[2] == 1) {
        pushStudentToElective(buffer, 2);
    }
}

void insertStudentDataElective_3()
{
    printf("\n���������� ����? ");
    scanf_s("%d", &buffer.electives[3]);
    if (buffer.electives[3] == 1) {
        pushStudentToElective(buffer, 3);
    }
}

void insertStudentDataElective_4()
{
    printf("\n���� ������? ");
    scanf_s("%d", &buffer.electives[4]);
    if (buffer.electives[4] == 1) {
        pushStudentToElective(buffer, 4);
    }
}

int tableStudents()
{
    int quantity = 0;

    if (!file_open()) {
        return 0;
    }

    if (false) //��������� �� ������� ����
    {
        printf("\n\n--------------------------------------------------------------\n");
        printf("| � ������� �� ���� ������� �����-���� �������� � ���������. |\n");
        printf("--------------------------------------------------------------\n");
    }
    else
    {
        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|                                        � ������� ���������� ��������� �������� � ���������  :                                        |");
        printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");

        printStudentTableHeader();

        while (fread(&buffer, sizeof(buffer), 1, data) > 0)
        {
            printStudentTableRow(++quantity, buffer);
        }
    }
    fclose(data);
    return quantity;
}

void printStudentTableHeader()
{
    printf("\n\n+------------------------------------------------------------------------------------------------------------------------------------+\n");
    printf("| � | ������� �������� |  ����� ������ |  ������� ����  | ������ | ���������������� |  ����������  | ���������� ���� |  ���� ������  |\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
}

void printStudentTableRow(int number, Student student)
{
    printf("|%3d|   %15s|   %12d| %15.3f|    %4d|             %5d|    %10d|   %14d|        %7d|\n", number, student.name, student.group_number, student.average_mark, student.electives[0], student.electives[1], student.electives[2], student.electives[3], student.electives[4]);
    printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
}

int sortStudents()
{
    Student studentsData[MAX_COUNT_STUDENTS];
    int i, j;
    int quantity = 0;

    if (!file_open()) {
        return 0;
    }

    if (false) //��������� �� ������� ����
    {
        printf("\n\n--------------------------------------------------------------\n");
        printf("| � ������� �� ���� ������� �����-���� �������� � ���������. |\n");
        printf("--------------------------------------------------------------\n");
    }
    else
    {
        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|                                         ��������������� �� �������� ����� ������� ��������� :                                        |");
        printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");

        printStudentTableHeader();

        while (fread(&studentsData[quantity], sizeof(buffer), 1, data) > 0)
        {
            quantity++;
        }

        fclose(data);

        for (i = 0; i < quantity - 1; i++) {
            for (j = 0; j < quantity - i - 1; j++) {
                if (studentsData[j].average_mark < studentsData[j + 1].average_mark) {
                    buffer = studentsData[j];
                    studentsData[j] = studentsData[j + 1];
                    studentsData[j + 1] = buffer;
                }
            }
        }

        for (i = 0; i < quantity; i++) {
            printStudentTableRow(i + 1, studentsData[i]);
        }
    }

    return 1;
}