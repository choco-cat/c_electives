#include "Prototypes and Classes.h"

char ALLDATA[6][2][30] = { {"DataOfPhisic.bin", "������"}, 
                           {"DataOfProgramming.bin", "����������������"},
                           {"DataOfMath.bin", "����������"} , 
                           {"DataOfEnglish.bin", "���������� ����"}, 
                           {"DataOfDatabase.bin", "���� ������"}};

Student buff;
FILE* file;

HANDLE hConsole2 = GetStdHandle(STD_OUTPUT_HANDLE);

int file_opens(char* NameOfFile, int countBytes = 0, int offset = SEEK_SET)
{
   fopen_s(&file, NameOfFile, "rb+");

    if (!file)
    {
        if (!file) 
        {
            printf("������ ��� ������ � ������ %s (��� �������� ��� ��������) .\n", NameOfFile);
        }
        return 0;
    }

    fseek(file, countBytes, offset);
    return 1;
}

int lookElective()
{
    system("cls");
    int keyOfElective = 0;
    int n; // ���������� ��������� �����
    int id;
    int* arrIds = (int*)malloc(1000 * sizeof(int)); 
    SetConsoleTextAttribute(hConsole2, FOREGROUND_BLUE);
    printf("--------------------------------------------------------------\n");
    printf("| �������� �����������, ���� ��������� ������� ����������� : |");
    printf("\n--------------------------------------------------------------");
    SetConsoleTextAttribute(hConsole2, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    do 
    {
        int keyOfElective = list();
        n = 0;
        memset(arrIds, 0, sizeof(arrIds)); // ���������� ������� ������
        char* electiveFile = ALLDATA[keyOfElective - 1][0];
        char* electiveName = ALLDATA[keyOfElective - 1][1];
        if (keyOfElective > 0 && keyOfElective <= SIZE_OF_ELECTIVE) 
        {
            if (!file_opens(electiveFile))
            {
                continue;
            }
            if (fgetc(file) == EOF)
            {
                return 0;
            }
            else
            {
                rewind(file);
            }
            while (fscanf_s(file, "%d", &arrIds[n]) == 1 && n < 1000) 
            {
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
    if (!file_opens(ALLDATA[indexElective][0]))
    {
        return 0;
    }
    while (fscanf_s(file, "%d", &id) != EOF) 
    {
        if (id == studentId) 
        {
            // ����� id, ������� ��� ������� �� �����������
            fclose(file);
            return 0;
        }
    }

    fprintf(file, "%d\n", studentId); // ���������� ����� � ����
    fclose(file);
    return 1;
}

int deleteStudentFromElective(int studentId, int indexElective)
{
    FILE* temp_file;
    fopen_s(&temp_file, "temp.bin", "w");
    if (!file_opens(ALLDATA[indexElective][0]))
    {
        return 0;
    }
    int struct_size = sizeof(buff);
    int num_deleted = 0; // ����, ������� ����� ���������� � 1, ���� ������� � ������� ������
    int id;
    // ������ ������ �� �����
    int count = 0;
    // ������ �� ������ ����� �� �������� �����
    while (fscanf_s(file, "%d", &id) != EOF) 
    {
        if (id == studentId) {
            // ����� �����, ������� ����� �������
            num_deleted++;
            continue;  // ���������� ������ ����� �� ��������� ����
        }
        // ���������� �����, ������� �� ����� �������, �� ��������� ����
        fprintf(temp_file, "%d\n", id);
    }
    fclose(file);
    fclose(temp_file);
    // �������� ������� ���� ���������
    if (num_deleted > 0) 
    {
        if (remove(ALLDATA[indexElective][0]) != 0) 
        {
            perror("�� ������� ������� ������� ����");
            return -1;
        }
        if (rename("temp.bin", ALLDATA[indexElective][0]) != 0) 
        {
            perror("�� ������� ������������� ��������� ����");
            return -1;
        }
    }
    else 
    {
        remove("temp.bin");
    }
    return 0;
}

void TableStudentOfElective(int* arrIds, char* electiveName, int size)
{
    SetConsoleTextAttribute(hConsole2, FOREGROUND_MAGENTA);
    if (!file_opens(STUDENTS_DATA))
    {
        return;
    }
    if (fgetc(file) == EOF) 
    {
        printf("\n\n-----------------------------------------------------------------------------------\n");
        printf("| � ������� �� ���� ������� �����-���� �������� � ��������� ������� ������������. |\n");
        printf("-----------------------------------------------------------------------------------\n");
    }
    else
    {
        rewind(file);
        printf("\n\n--------------------------------------------------------------------------------------------------------------------------------------\n");
        printf(    "|                                        ����������� -- %17s  --                                                        |", electiveName);
        printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");
        printStudentTableHeader();
        SetConsoleTextAttribute(hConsole2, FOREGROUND_CYAN);
        int couner = 0;
        while (fread(&buff, sizeof(buff), 1, file) > 0)
        {
            if (contains(arrIds, size, buff.id)) 
            {
                couner++;
                printStudentTableRow(couner, buff);
            }
        }
    }
    fclose(file);
    system("pause");
}

int contains(int arr[], int size, int x) 
{
    for (int i = 0; i <= size; i++) 
    {
        if (arr[i] == x) 
        {
            return 1; // ������ �������� ����� x
        }
    }
    return 0; // ������ �� �������� ����� x
}

int list()
{
    SetConsoleTextAttribute(hConsole2, FOREGROUND_MAGENTA);
    int yourChoice;
    printf("\n\n\n********************************\n*\n");
    for (int i = 0; i < SIZE_OF_ELECTIVE; i++) 
    {
        printf("*   %d - %s.                                \n", i + 1,  ALLDATA[i][1]);
    }
    printf("*   0 - ����� � �������� ����.                   \n*");
    printf(    "\n********************************\n");
    SetConsoleTextAttribute(hConsole2, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    scanf_s("%d", &yourChoice);
    return yourChoice;
}

void topOfElective()
{
    int num_records[SIZE_OF_ELECTIVE][2];
    int buffer[2];
    char line[5];
    int num_lines;
    system("cls");
    SetConsoleTextAttribute(hConsole2, FOREGROUND_BLUE);
    printf("\n\n-----------------------------------------------------\n");
    printf("| ������ ������������� � ������� �� ������������... |\n");
    printf("-----------------------------------------------------\n");
    SetConsoleTextAttribute(hConsole2, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    for (int i = 0; i < SIZE_OF_ELECTIVE; i++) 
    {
        num_lines = 0;
        if (!file_opens(ALLDATA[i][0]))
        {
            continue;
        }
        while (fgets(line, sizeof(line), file) != NULL) 
        {
            num_lines++;
        }
        num_records[i][0] = i;
        num_records[i][1] = num_lines; // ��������� ���������� �������
        fclose(file);
    }
    for (int i = 0; i < SIZE_OF_ELECTIVE - 1; i++) 
    {
        for (int j = 0; j < SIZE_OF_ELECTIVE - i - 1; j++)
        {
            if (num_records[j][1] < num_records[j + 1][1]) 
            {
                buffer[0] = num_records[j][0];
                buffer[1] = num_records[j][1];
                num_records[j][0] = num_records[j + 1][0];
                num_records[j][1] = num_records[j + 1][1];
                num_records[j + 1][0] = buffer[0];
                num_records[j + 1][1] = buffer[1];
            }
        }
    }
    SetConsoleTextAttribute(hConsole2, FOREGROUND_RED);
    for (int i = 0; i < SIZE_OF_ELECTIVE; i++) 
    {
        if (i == 1) SetConsoleTextAttribute(hConsole2, FOREGROUND_GREEN);
        if (i == 2) SetConsoleTextAttribute(hConsole2, FOREGROUND_CYAN);
        if (i > 2)  SetConsoleTextAttribute(hConsole2, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("\n %d. %s (���������� �������� - %d).\n", i + 1, ALLDATA[num_records[i][0]][1], num_records[i][1]);
    }
    printf("\n\n");
    system("pause");
}

int sortStudentsOfElective()
{
    int* arrIds = (int*)malloc(1000 * sizeof(int));
    Student studentsData[MAX_COUNT_STUDENTS];
    Student stud;
    int i, j;
    int quantity = 0, n = 0;
    int keyOfElective = list();
    char* electiveFile = ALLDATA[keyOfElective - 1][0];
    char* electiveName = ALLDATA[keyOfElective - 1][1];
    if (!file_opens(electiveFile)) 
    {
        return 0;
    }
    SetConsoleTextAttribute(hConsole2, FOREGROUND_MAGENTA);
    if (fgetc(file) == EOF)
    {
        printf("\n\n--------------------------------------------------------------\n");
        printf("| � ������� �� ���� ������� �����-���� �������� � ���������. |\n");
        printf("--------------------------------------------------------------\n");
    }
    else
    {
        rewind(file);
        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf(    "|                            ���������� �������� �� �������� ����� (10 �������)   ����������� : -- %17s --                |", electiveName);
        printf(  "\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        printStudentTableHeader();
        SetConsoleTextAttribute(hConsole2, FOREGROUND_CYAN);
        while (fscanf_s(file, "%d", &arrIds[n]) && n < 1000) 
        {
            n++;
        }
        fclose(file);
        if (!file_opens(STUDENTS_DATA))
        {
            return 0;
        }
        while (fread(&buff, sizeof(buff), 1, file) > 0)
        {
            if (contains(arrIds, n, buff.id)) 
            {

                studentsData[quantity] = buff;
                quantity++;
            }
        }
        fclose(file);
        for (i = 0; i < quantity - 1; i++) 
        {
            for (j = 0; j < quantity - i - 1; j++) 
            {
                if (studentsData[j].average_mark < studentsData[j + 1].average_mark) 
                {
                    buff = studentsData[j];
                    studentsData[j] = studentsData[j + 1];
                    studentsData[j + 1] = buff;
                }
            }
        }
        if (quantity > 10) quantity = 10;
        for (i = 0; i < quantity; i++) 
        {
            printStudentTableRow(i + 1, studentsData[i]);
        }
        system("pause");
    }
    SetConsoleTextAttribute(hConsole2, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return 1;
}

