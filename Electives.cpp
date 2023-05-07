#include "Prototypes and Classes.h"

char ALLDATA[6][2][30] = { {"DataOfPhisic.bin", "������"}, {"DataOfProgramming.bin", "����������������"},  {"DataOfMath.bin", "����������"} , {"DataOfEnglish.bin", "���������� ����"},  "DataOfDatabase.bin", "DataOfStudent.bin" };

//char ELECTIVENAMES[5][20] = { "������", "����������������", "����������", "���������� ����", "���� ������" };

const int SIZE_OF_ELECTIVE = 4;
static int stud = 0;
errno_t err1;
static int count_of_student = 0;
Student buff;

FILE* file;
Teacher teacher_ph, teacher_ma, teacher_en, teacher_da, teacher_pr;

int file_open_e(char *NameOfFile)
{
    fopen_s(&file, NameOfFile, "a+");
    if (!file)
    {
        printf("������ ��� ������ � ������ (��� �������� ��� ��������) .\n");
        return -2;
    }
    return 0;
}


int look()
{
    int keyOfElective = 0;
    printf("--------------------------------------------------------------\n");
    printf("| �������� �����������, ���� ��������� ������� ����������� : |");
    printf("\n--------------------------------------------------------------");
    do {
    int keyOfElective = list();
    char* electiveFile = ALLDATA[keyOfElective - 1][0];
    char* electiveName = ALLDATA[keyOfElective - 1][1];

        if (file_open_e(electiveFile) == -2)
        {
            return 0;
        }  
        TableStudentOfElective(file, electiveName);
    } while (keyOfElective != '0');
}

int pushStudentToElective( Student student, int indexElective)
{
    char* firstString = ALLDATA[indexElective][0];
    if (file_open_e(firstString) == -2)
    {
        return 0;
    }
    fwrite(&student, sizeof(student), 1, file);
    fclose(file);
}

void TableStudentOfElective(FILE* file, char* Elective)
{
    bool flag = false;
   
    if (false) //��������� �� ������� ����
    {
        printf("\n\n-----------------------------------------------------------------------------------\n");
        printf("| � ������� �� ���� ������� �����-���� �������� � ��������� ������� ������������. |\n");
        printf("-----------------------------------------------------------------------------------\n");
    }
    else
    {
        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|                                        ����������� *%15s* ( ������������� : %15s )  :                                                |\n", Elective, teacher_ph.name);
        printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\n\n+--------------------------------------------------------------------------------------------------------------------------------+\n");
        printf("| ������� �������� |  ����� ������ |  ������� ����  | ������ | ���������������� |  ����������  | ���������� ���� |  ���� ������  |\n");
        printf("----------------------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&buff, sizeof(buff), 1, file) > 0)
        {
            printf("|   %15s|   %12d| %15.3f|    %4d|             %5d|    %10d|   %14d|        %7d|\n", buff.name, buff.group_number, buff.average_mark, buff.electives[0], buff.electives[1], buff.electives[2], buff.electives[3], buff.electives[4]);
            printf("----------------------------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(file);
    system("pause");
}

int list()
{
    int yourChoice;
    printf("\n**********************************************************************************\n");
    printf("*   1 - ������. \n");
    printf("*   2 - ����������������. \n");
    printf("*   3 - ����������. \n");
    printf("*   4 - ���������� ����. \n");
    printf("*   5 - ���� ������. \n");
    printf("*   0 - ����� �� ����. \n*");
    printf("\n**********************************************************************************\n");
    scanf_s("%d", &yourChoice);
    return yourChoice;
}

void topOfElective()
{
    bool flag; // ���� ������ ������������ �� ������ �� ����������
    char* String = ALLDATA[0][0];
    char* String1 = ALLDATA[1][0];
    char* String2 = ALLDATA[2][0];
    char* String3 = ALLDATA[3][0];
    char* String4 = ALLDATA[4][0];
    int buffer;
    char pointer[35];
    int top[] = {0,0,0,0,0};
    char names[5][35] = { "������", "����������", "���� ������", "����������", "����������������" };
    int counter_p = 0,  counter_m = 0,  counter_d = 0,  counter_e = 0,  counter_pr = 0;
    printf("\n\n-----------------------------------------------------\n");
    printf("| ������ ������������� � ������� �� ������������... |\n");
    printf("-----------------------------------------------------\n");
    file_open_e(String); 
    while (fread(&buffer, sizeof(buffer), 1, file) > 0)
    {
        top[0] = top[0] + 1;
    }
    fclose(file);
    file_open_e(String1); 
    while (fread(&buffer, sizeof(buffer), 1, file) > 0)
    {
        top[1] = top[1] + 1;
    }
    fclose(file);
    file_open_e(String2);
    while (fread(&buffer, sizeof(buffer), 1, file) > 0)
    {
        top[2] = top[2] + 1;
    }
    fclose(file);
    file_open_e(String3);
    while (fread(&buffer, sizeof(buffer), 1, file) > 0)
    {
        if (buffer)
        {
            top[3] = top[3] + 1;
        }
    }
    fclose(file);
    file_open_e(String4);
    while (fread(&buffer, sizeof(buffer), 1, file) > 0)
    {
        top[4] = top[4] + 1;
    }
    fclose(file);
    for (register int i = 0; i < 5; i++)
    {
        for (register int j = 1; j < 5; j++)
        {
            if (top[j] > top[j - 1])
            {
                buffer = top[j - 1];
                top[j - 1] = top[j];
                top[j] = buffer;
                pointer[30] = names[j - 1][30];
                names[j - 1][30] = names[j][30];
                names[j][30] = pointer[30];
            }
        }
    }
    for (register int g = 0; g < 5; g++)
    {
        printf("\n %d. %s (���������� �������� - %d) .\n", g + 1, names[g], top[g]);
    }
}