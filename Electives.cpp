#include "Prototypes and Classes.h"
char ALLDATA[6][2][30] = { {"DataOfPhisic.bin", "������"}, {"DataOfProgramming.bin", "����������������"},  {"DataOfMath.bin", "����������"} , {"DataOfEnglish.bin", "���������� ����"}, {"DataOfDatabase.bin", "���� ������"}};
Student buff;
FILE* file;
Teacher teacher_ph, teacher_ma, teacher_en, teacher_da, teacher_pr;

int file_open_e(char *NameOfFile)
{
    fopen_s(&file, NameOfFile, "a+");
    if (!file)
    {
        printf("������ ��� ������ � ������ (��� �������� ��� ��������) .\n");
        return -1;
    }
    return 1;
}

int look()
{
    int keyOfElective = 0;
    printf("--------------------------------------------------------------\n");
    printf("| �������� �����������, ���� ��������� ������� ����������� : |");
    printf("\n--------------------------------------------------------------");

    do {
        int keyOfElective = list();
        if (keyOfElective > 0 && keyOfElective <= SIZE_OF_ELECTIVE) {
            char* electiveFile = ALLDATA[keyOfElective - 1][0];
            char* electiveName = ALLDATA[keyOfElective - 1][1];
            if (!file_open_e(electiveFile))
            {
                return 0;
            }
            TableStudentOfElective(file, electiveName);
            fclose(file);
        }
    } while (keyOfElective != 0);
}

int pushStudentToElective( Student student, int indexElective)
{
    char* firstString = ALLDATA[indexElective][0];
    if (!file_open_e(firstString))
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
    system("pause");
}

int list()
{
    int yourChoice;
    printf("\n**********************************************************************************\n");
    for (int i = 0; i < SIZE_OF_ELECTIVE; i++) {
        printf("*   %d - %s. \n", i + 1,  ALLDATA[i][1]);
    }
    printf("*   0 - ����� �� ����. \n*");
    printf("\n**********************************************************************************\n");
    scanf_s("%d", &yourChoice);
    return yourChoice;
}

void topOfElective()
{
    int num_records[SIZE_OF_ELECTIVE][2];
    int buffer[2];
    printf("| ������ ������������� � ������� �� ������������... |\n");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < SIZE_OF_ELECTIVE; i++) {
        if (!file_open_e(ALLDATA[i][0]))
        {
            continue;
        }
        fseek(file, 0, SEEK_END); // ������� � ����� �����
        long file_size = ftell(file); // �������� ������ ����� � ������
        num_records[i][0] = i;
        num_records[i][1] = file_size / sizeof(buff); // ��������� ���������� �������
        fclose(file);
    }

    for (int i = 0; i < SIZE_OF_ELECTIVE - 1; i++) {
        for (int j = 0; j < SIZE_OF_ELECTIVE - i - 1; j++) {
            if (num_records[j][1] < num_records[j + 1][1]) {
                buffer[0] = num_records[j][0];
                buffer[1] = num_records[j][1];
                num_records[j][0] = num_records[j + 1][0];
                num_records[j][1] = num_records[j + 1][1];
                num_records[j + 1][0] = buffer[0];
                num_records[j + 1][1] = buffer[1];
            }
        }
    }

    for (int i = 0; i < SIZE_OF_ELECTIVE; i++) {
        printf("\n %d. %s (���������� �������� - %d).\n", i + 1, ALLDATA[num_records[i][0]][1], num_records[i][1]);
    }
}
