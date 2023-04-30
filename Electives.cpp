#include "Prototypes and Classes.h"

char ALLDATA[6][2][30] = { {"DataOfPhisic.bin", "ФИЗИКА"}, {"DataOfProgramming.bin", "ПРОГРАММИРОВАНИЕ"},  {"DataOfMath.bin", "МАТЕМАТИКА"} , {"DataOfEnglish.bin", "АНГЛИЙСКИЙ ЯЗЫК"},  "DataOfDatabase.bin", "DataOfStudent.bin" };

//char ELECTIVENAMES[5][20] = { "ФИЗИКА", "ПРОГРАММИРОВАНИЕ", "МАТЕМАТИКА", "АНГЛИЙСКИЙ ЯЗЫК", "БАЗЫ ДАННЫХ" };

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
        printf("Ошибка при работе с файлом (его создании или открытии) .\n");
        return -2;
    }
    return 0;
}


int look()
{
    int keyOfElective = 0;
    printf("--------------------------------------------------------------\n");
    printf("| Выберите факультатив, чьих студентов желаете просмотреть : |");
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
   
    if (false) //проверить на пустоту файл
    {
        printf("\n\n-----------------------------------------------------------------------------------\n");
        printf("| В системе не были найдены какие-либо сведения о студентах ДАННОГО факультатива. |\n");
        printf("-----------------------------------------------------------------------------------\n");
    }
    else
    {
        printf("\n\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|                                        Факультатив *%15s* ( Преподаватель : %15s )  :                                                |\n", Elective, teacher_ph.name);
        printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\n\n+--------------------------------------------------------------------------------------------------------------------------------+\n");
        printf("| Фамилия студента |  Номер группы |  Средний балл  | Физика | Программирование |  Математика  | Английский язык |  Базы данных  |\n");
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
    printf("*   1 - физика. \n");
    printf("*   2 - программирование. \n");
    printf("*   3 - математика. \n");
    printf("*   4 - английский язык. \n");
    printf("*   5 - базы данных. \n");
    printf("*   0 - выход из меню. \n*");
    printf("\n**********************************************************************************\n");
    scanf_s("%d", &yourChoice);
    return yourChoice;
}