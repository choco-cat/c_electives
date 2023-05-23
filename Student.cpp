#include "Prototypes and Classes.h"

FILE* data, elect;
errno_t err;
Student buffer;
Student temp;
char STUDENTS_DATA[30] = "DataOfStudent.bin";

HANDLE hConsole3 = GetStdHandle(STD_OUTPUT_HANDLE);

int file_open(int countBytes = 0, int offset = SEEK_SET)
{
    err = fopen_s(&data, STUDENTS_DATA, "rb+");
    if (!data)
    {
        printf("Ошибка при работе с файлом (его создании или открытии) .\n");
        return 0;
    }
    fseek(data, countBytes, offset);
    return 1;
}

int deleteStudents()
{
    system("cls");
    char vibor = '0';
    char viborField = '0';
    int quantity = 0;
    int number = 0;
    while (true)
    {
        system("cls");
        puts("\tУдаление данных\n");
        int quantity = tableStudents();
        if (quantity == 0)
        {
            return 0;
        }
        printf("Введите номер записи, которую необходимо удалить: ");
        do
        {
            scanf_s("%d", &number);
            fflush(stdin);
            if (number < 1 || number > quantity)
            {
                printf("Записи с таким номером нет. Повторите ввод: ");
            }
            else
            {
                break;
            }
        } while (true);
        return deleteStudent(number);
    }
}

int editStudent()
{
    system("cls");
    char vibor = '0';
    char viborField = '0';
    int quantity = 0;
    int number = 0;
    while (true) 
    {
        system("cls");
        puts("\tРедактирование данных\n");
        int quantity = tableStudents();
        if (quantity == 0)
        {
            return 0;
        }
        printf("1 - Ввести номер записи для редактирования\n2 - Вернуться в меню\n");
        do 
        {
            vibor = _getch();
        } while (vibor < '1' || vibor > '2');
        if (vibor == '2') 
        {
            return 0;
        }
        printf("Введите номер записи, которую необходимо отредактировать: ");
        do {
            scanf_s("%d", &number);
            fflush(stdin);
            if (number < 1 || number > quantity) 
            {
                printf("Записи с таким номером нет. Повторите ввод: ");
            }
            else
            {
                break;
            }
        } while (true);
        printf("Введено %d\n", number);
        if (!file_open(sizeof(Student) * (number - 1), SEEK_SET))
        {
            return 0;
        }
        fread(&buffer, sizeof(Student), 1, data);
        SetConsoleTextAttribute(hConsole3, FOREGROUND_MAGENTA);
        puts("--- Выбранная запись: ---\n");
        printStudentTableHeader();
        SetConsoleTextAttribute(hConsole3, FOREGROUND_CYAN);
        printStudentTableRow(number, buffer);
        SetConsoleTextAttribute(hConsole3, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        fclose(data);
        vibor = menuEditStudent();
        if (vibor == '3') 
        {
            fclose(data);
            return 0;
        }
        if (!file_open(sizeof(Student) * (number - 1), SEEK_SET)) 
        {
            return 0;
        }
        // запись целиком
        if (vibor == '1') 
        {
            insertStudentData(false);
        }
        else 
        {
            viborField = menuEditStudentFields();
            insertStudentDataField(viborField);
        }
        fclose(data);
        return 1;
    }
    return 1;
}

int deleteStudent(int number)
{
    int position_to_delete;
    int struct_size = sizeof(Student);
    int deleted = 0;
    int idToDelete;
    printf("Введено %d\n", number);
    if (!file_open(struct_size * (number - 1), SEEK_SET)) 
    {
        return 0;
    }
    fread(&buffer, sizeof(Student), 1, data);
    idToDelete = buffer.id;
    position_to_delete = ftell(data) - struct_size; // запоминаем позицию записи
    fseek(data, position_to_delete + struct_size, SEEK_SET);
    // считываем все записи структур, начиная со следующей за удаляемой записью, на одну позицию назад
    while (fread(&buffer, struct_size, 1, data) == 1) 
    {
        fseek(data, (number - 1) * struct_size, SEEK_SET); // перемещаем указатель текущей позиции на одну позицию назад
        fwrite(&buffer, struct_size, 1, data); // записываем считанную запись на одну позицию раньше
        fseek(data, (number + 1) * struct_size, SEEK_SET); // перемещаем указатель текущей позиции на следующую запись
        number++;
    }
    // обрезаем файл по байтам
    _chsize(_fileno(data), (number - 1) * struct_size);
    //удаляем факультативы у удаляемого студента
    for (int i = 0; i < SIZE_OF_ELECTIVE; i++) 
    {
        deleteStudentFromElective(idToDelete, i);
    }
    fclose(data);
    return 1;
}

char menuEditStudent()
{
    char vibor;
    printf("1 - Изменить сразу всю запись\n2 - Изменить отдельный элемент\n3 - Вернуться\n");
    do 
    {
        vibor = _getch();
    } while (vibor < '1' || vibor > '3');
    return vibor;
}

char menuEditStudentFields()
{
    char element;
    printf("\nВыберите поле, который нужно изменить:\n1 - Фамилия\n2 - Номер группы\n3 - Средний балл\n4 - Физика");
    printf("\n5 - Программирование\n6 - Математика\n7 - Английский язык\n8 - Базы данных\n");
    do 
    {
        element = _getch();
    } while (element < '1' || element > '8');
    return element;
}

int addStudent()
{
    int n;
    if (!file_open(0, SEEK_END)) 
    {
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
        count++;
    }
    fclose(data);
    printf("\nБинарный файл, состоящий из элементов структуры был успешно сформирован.\n");
    return 1;
}

void insertStudentData(bool newStudent)
{
    if (newStudent) 
    {
        insertStudentDataId();
    }
    insertStudentDataName();
    insertStudentDataGroup();
    insertStudentDataAverage();
    for (int i = 0; i < SIZE_OF_ELECTIVE; i++) 
    {
        insertStudentDataElective(i);
    }
    fwrite(&buffer, sizeof(buffer), 1, data);
}

void insertStudentDataField(char symbol)
{
    switch (symbol) 
    {
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
        insertStudentDataElective(0);
        break;
    case '5':
        insertStudentDataElective(1);
        break;
    case '6':
        insertStudentDataElective(2);
        break;
    case '7':
        insertStudentDataElective(3);
        break;
    case '8':
        insertStudentDataElective(4);
        break;
    }
    fwrite(&buffer, sizeof(buffer), 1, data);
}

void insertStudentDataId()
{
    fseek(data, ftell(data) - sizeof(buffer), SEEK_SET);
    if (fread(&temp, sizeof(temp), 1, data)) 
    {
        buffer.id = temp.id + 1;
        fseek(data, 0, SEEK_END);
    }
    else 
    {
        fseek(data,0, SEEK_END);
        buffer.id = 1;
    }
}

void insertStudentDataName()
{
    bool flag = false;
    while (true)
    {
        puts("Введите фамилию студента : \n");
        fflush(stdin);
        if (!flag)
        {
            getchar();
            flag = true;
        }
        gets_s(buffer.name);
        if (checkInputDataName(buffer.name))
        {
            break;
        }
    }
}

void insertStudentDataGroup()
{
    while (true)
    {
        puts("Введите номер группы студента :\n");
        scanf_s("%d", &buffer.group_number);
        if (checkInputDataGroup(buffer.group_number))
        {
            break;
        }
    }
}

void insertStudentDataAverage()
{
    while (true)
    {
        puts("Введите средний балл студента :\n");
        scanf_s("%f", &buffer.average_mark);
        if (checkInputDataAvarageMark(buffer.average_mark))
        {
            break;
        }
    }
}

void insertStudentDataElective(int electiveIndex)
{
    const char* electiveName = ALLDATA[electiveIndex][1];
    while (true)
    {
        printf("\n%s? (1 | 0) ", electiveName);
        scanf_s("%d", &buffer.electives[electiveIndex]);
        if (checkInputDataElective(buffer.electives[electiveIndex]))
        {
            break;
        }
    }
    if (buffer.electives[electiveIndex] == 1) {
        pushStudentToElective(buffer.id, electiveIndex);
    }
    else {
        deleteStudentFromElective(buffer.id, electiveIndex);
    }
}

int tableStudents()
{
    SetConsoleTextAttribute(hConsole3, FOREGROUND_BLUE);
    int quantity = 0;
    if (!file_open()) 
    {
        return 0;
    }
    if (fgetc(data) == EOF) 
    {
        printf("\n\n--------------------------------------------------------------\n");
        printf("| В системе не были найдены какие-либо сведения о студентах. |\n");
        printf("--------------------------------------------------------------\n");
        return 0;
    }
    else
    {
        rewind(data);
        system("cls");
        SetConsoleTextAttribute(hConsole3, FOREGROUND_MAGENTA);
        printf("\n\n--------------------------------------------------------------------------------------------------------------------------------------\n");
        printf(   "|                                        В системе существуют следующие сведения о студентах  :                                      |\n");
        printf(    "--------------------------------------------------------------------------------------------------------------------------------------\n");
        printStudentTableHeader();
        SetConsoleTextAttribute(hConsole3, FOREGROUND_CYAN);
        while (fread(&buffer, sizeof(buffer), 1, data) > 0)
        {
            printStudentTableRow(++quantity, buffer);
        }
        system("pause");
        SetConsoleTextAttribute(hConsole3, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    fclose(data);
    return quantity;
}

void printStudentTableHeader()
{
    printf("\n\n+------------------------------------------------------------------------------------------------------------------------------------+\n");
    printf("| № | Фамилия студента |  Номер группы |  Средний балл  | Физика | Программирование |  Математика  | Английский язык |  Базы данных  |\n");
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
    if (!file_open()) 
    {
        return 0;
    }
    if (fgetc(data) == EOF)
    {
        printf("\n\n--------------------------------------------------------------\n");
        printf("| В системе не были найдены какие-либо сведения о студентах. |\n");
        printf("--------------------------------------------------------------\n");
    }
    else
    {
        rewind(data);
        SetConsoleTextAttribute(hConsole3, FOREGROUND_MAGENTA);
        printf("\n\n--------------------------------------------------------------------------------------------------------------------------------------\n");
        printf(    "|                                         Отсортированный по среднему баллу спискок ВСЕХ студентов :                                 |\n");
        printf(  "--------------------------------------------------------------------------------------------------------------------------------------\n");
        printStudentTableHeader();
        SetConsoleTextAttribute(hConsole3, FOREGROUND_CYAN);
        while (fread(&studentsData[quantity], sizeof(buffer), 1, data) > 0)
        {
            quantity++;
        }
        fclose(data);
        for (i = 0; i < quantity - 1; i++) 
        {
            for (j = 0; j < quantity - i - 1; j++) 
            {
                if (studentsData[j].average_mark < studentsData[j + 1].average_mark) 
                {
                    buffer = studentsData[j];
                    studentsData[j] = studentsData[j + 1];
                    studentsData[j + 1] = buffer;
                }
            }
        }
        for (i = 0; i < quantity; i++) 
        {
            printStudentTableRow(i + 1, studentsData[i]);
        }
        system("pause");
    }
    SetConsoleTextAttribute(hConsole3, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return 1;
}
