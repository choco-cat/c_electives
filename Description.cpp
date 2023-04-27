
#include "Prototypes and Classes.h"

const int SIZE_OF_ELECTIVE = 4;
static int stud = 0;
FILE* data;
errno_t err;
static int count_of_student = 0;
Student buffer;

int file_open(int countBytes = 0, int offset = SEEK_SET)
{
    err = fopen_s(&data, "DataOfStudent.bin", " rb+");

    if (!data)
    {
        printf("Ошибка при работе с файлом (его создании или открытии) .\n");
        return 0;
    }
    fseek(data, countBytes, offset);
  return 1;
}

int editStudent()
{
    FILE* pFile;
    system("cls");

        char vibor = '0';
        char viborField = '0';
        int quantity = 0;
        int number = 0;

        while (true) {
            system("cls");

            puts("\tРедактирование данных\n");
            int quantity = tableStudent();
            printf("1 - Ввести номер записи для редактирования\n2 - Вернуться в меню\n");
            do {
                vibor = _getch();
            } while (vibor < '1' || vibor > '2');

            if (vibor == '2') {
                return 0;
            }

            printf("Введите номер записи, которую необходимо отредактировать: ");
            do {
                scanf_s("%d", &number);
                fflush(stdin);
                if (number < 1 || number > quantity) {
                    printf("Записи с таким номером нет. Повторите ввод: ");
                }
                else
                    break;
            } while (true);


            printf("Введено %d\n", number);
            if (!file_open(sizeof(Student) * (number - 1), SEEK_SET)) {
                return 0;
            }
           
            fread(&buffer, sizeof(Student), 1, data);
            puts("--- Выбранная запись: ---\n");
            printf("| Фамилия студента |  Номер группы |  Средний балл  | Физика | Программирование |  Математика  | Английский язык |  Базы данных  |\n");
            printf("|   %15s|   %12d| %15.3f|    %4d|             %5d|    %10d|   %14d|        %7d|\n", buffer.name, buffer.group_number, buffer.average_mark, buffer.electives[0], buffer.electives[1], buffer.electives[2], buffer.electives[3], buffer.electives[4]);
            fclose(data);

            vibor = menuEditStudent();

            if (vibor == '3') {
                fclose(data);
                return 0;
            }

            if (!file_open(sizeof(Student) * (number - 1), SEEK_SET)) {
                return 0;
            }
          
            // запись целиком
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
    printf("1 - Изменить сразу всю запись\n2 - Изменить отдельный элемент\n3 - Вернуться\n");
    do {
        vibor = _getch();
    } while (vibor < '1' || vibor > '3');
    return vibor;
}

char menuEditStudentFields()
{
    char element;
    printf("\nВыберите поле, который нужно изменить:\n1 - Фамилия\n2 - Номер группы\n3 - Средний балл\n4 - Физика");
    printf("\n5 - Программирование\n6 - Математика\n7 - Английский язык\n8 - Базы данных\n");
    do {
        element = _getch();
    } 
    while (element < '1' || element > '8');
    return element;
}

int addStudent()
{
    int n;
    if (!file_open(0, SEEK_END)) {
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
        insertStudentData();
        printf("\nДанные %d-ой информации были записаны в бинарный файл.\n", count + 1);
        fwrite(&buffer, sizeof(buffer), 1, data);//запись целиком
        count++;
        stud++;
    }
    fclose(data);
    printf("\nБинарный файл, состоящий из элементов структуры был успешно сформирован.\n");
    stud++;
    return 0;
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
    puts("Введите фамилию студента : \n");
    fflush(stdin);
    getchar();
    gets_s(buffer.name);
}

void insertStudentDataGroup()
{
    puts("Введите номер группы студента :\n");
    scanf_s("%d", &buffer.group_number);
}

void insertStudentDataAverage()
{
    puts("\nВведите средний балл студента.\n");
    scanf_s("%f", &buffer.average_mark);
}

void insertStudentDataElective_0()
{
    printf("\nФизика? ");
    scanf_s("%d", &buffer.electives[0]);
}

void insertStudentDataElective_1()
{
    printf("\nПрограммирование? ");
    scanf_s("%d", &buffer.electives[1]);
}

void insertStudentDataElective_2()
{
    printf("\nМатематика? ");
    scanf_s("%d", &buffer.electives[2]);
}

void insertStudentDataElective_3()
{
    printf("\nАнглийский язык? ");
    scanf_s("%d", &buffer.electives[3]);
}

void insertStudentDataElective_4()
{
    printf("\nБазы данных? ");
    scanf_s("%d", &buffer.electives[4]);
}

int tableStudent()
{
    bool flag = false;
    int quantity = 0;

    if (!file_open()) {
        return 0;
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
            quantity++;
            printf("|   %15s|   %12d| %15.3f|    %4d|             %5d|    %10d|   %14d|        %7d|\n", buffer.name, buffer.group_number, buffer.average_mark, buffer.electives[0], buffer.electives[1], buffer.electives[2], buffer.electives[3], buffer.electives[4]);
            printf("----------------------------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(data);
    return quantity;
}

void sortStudent()
{
    printf("--------------------------------------\n");
    printf("| СОРТИРОВКА ЗАПИСЕЙ                 |");
    printf("\n--------------------------------------");
    while (true)
    {
        /*switch ()
        {

        }*/
    }
}