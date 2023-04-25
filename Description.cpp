
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
    printf(    "| Список доступных факультативов |\n");
    printf(    "----------------------------------\n");
    printf("\n***********************************************\n*\n");
    printf("*   1 -  дисциплина 'физика'.\n");
    printf("*   2 -  дисциплина 'программирование'.\n");
    printf("*   3 -  дисциплина 'математика'.\n");
    printf("*   4 -  дисциплина 'английский язык'.\n");
    printf("*   5 -  дисциплина 'базы данных'.\n");
    printf("\n***********************************************\n");
    printf("\nНа какое количество факультативов вы желаете записаться? ");
    scanf_s("%d", &count_of_faculties);
    printf("\nУкажите их номера в привиденной таблице.");
    for (register int i = 0; i < count_of_faculties; i++)
    {
        scanf_s("%d", &number);
        //buffer.electives[number - 1] = 1;
        printf("\nДисциплина под номером %d была успешно добавлена в список желаемых.", number );
    }
}

int file_open()
{
    err = fopen_s(&data, "DataOfStudent.bin", "a+");
    if (!data)
    {
        printf("Ошибка при работе с файлом (его создании или открытии) .\n");
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
    printf(    "| Осуществляем добавление сведений о студенте... |\n");
    printf(    "--------------------------------------------------\n");
    printf("Какое количество сведений вы желаете добавить?");
    scanf_s("%d", &n);
    int count = 0;
    while (count < n)
    {
        printf("Запись данных %d-ого студента...\n", count + 1);
        puts("Введите фамилию студента : \n");
        fflush(stdin);
        getchar();
        gets_s(buffer.name);
        puts("Введите номер группы студента :\n");
        //fflush(stdin);
        //getchar();
        scanf_s("%d", &buffer.group_number);
        puts("\nВведите средний балл студента.\n");
        scanf_s("%f", &buffer.average_mark);
        //faculties(buffer);
        printf("\nФизика? ");
        scanf_s("%d", &buffer.electives[0]);

        printf("\nПрограммирование? ");
        scanf_s("%d", &buffer.electives[1]);
        printf("\nМатематика? ");
        scanf_s("%d", &buffer.electives[2]);
        printf("\nАнглийский язык? ");
        scanf_s("%d", &buffer.electives[3]);
        printf("\nБазы данных? ");
        scanf_s("%d", &buffer.electives[4]);
        printf("\nДанные %d-ой информации были записаны в бинарный файл.\n", count + 1);
        fwrite(&buffer, sizeof(buffer), 1, data);//запись целиком
        count++;
    }
    fclose(data);
    printf("\nБинарный файл, состоящий из элементов структуры был успешно сформирован.\n");
    stud++;
    return 0;
	
}

int menu()
{
    int n;
    printf("\nНаш ассортимент функций :");
    printf("\n1 - Формирование бинарного файла из элементов, заданной структуры.");
    printf("\n2 - Печать формированного бинарного файла.");
    printf("\n3 - Добавление данных о других машинах.");
    printf("\n4 - Поиск данных о машине по марке.");
    printf("\n5 - Выход из программы.");
    printf("\nЧего изволите?\n");
    scanf_s("%d", &n);
    return n;
}

/*
int form_file()
{
    prov = 1;
    int k;
    printf("\nНачинаем формирование файла...\n");
    if (file_open() == -2)
    {
        return 0;
    }
    printf("\nВведите планируемых записей данных автомобилей n = ");
    scanf_s("%d", &n);
    count = 0;
    while (count < n)
    {
        printf("Запись данных %d-ого автомобиля...\n", count + 1);
        puts("Введите регистрационный номер автомобиля :\n");
        fflush(stdin);
        getchar();
        gets_s(avt.regnomer);
        puts("Введите марку автомобиля :\n");
        gets_s(avt.mark);
        puts("Введите имя мастера автомобиля :\n");
        gets_s(avt.master);
        do
        {
            printf("Введите длину пробега (в километрах) автомобиля :\n");
            scanf_s("%f", &avt.probeg);
            if (avt.probeg <= 0)
            {
                printf("\nНедопустимое значение длина пробега автомобиля.");
            }
        } while (avt.probeg <= 0);
        printf("\nДанные %d-ого автомобиля были записаны в бинарный файл.\n", count + 1);
        fwrite(&avt, sizeof(avt), 1, f);//запись целиком
        count++;
    }

    fclose(f);
    printf("\nБинарный файл, состоящий из элементов структуры был успешно сформирован.\n");
    return 0;
}
*/

/*
int vivod_file()
{
    if (file_open() == -2)
    {
        printf("Файл не был сформирован. Попросим вас его сформировать.\n");
    }

    int i = 1;

    while (fread(&avt, sizeof(avt), 1, f) > 0)
    {
        printf("\nДанные %d-ого автомобиля.", i);
        printf("\nРегистрационный номер автомобиля : ");
        printf("%s\n", avt.regnomer);
        printf("Марка автомобиля : ");
        printf("%s\n", avt.mark);
        printf("Имя мастера автомобиля : ");
        printf("%s\n", avt.master);
        printf("Длина пробега автомобиля ( в километрах) : ");
        printf("%f\n", avt.probeg);
        i++;
    }

    if (i == 1) {
        printf("Файл не существует или не содержит данных.\n");
    }

    fclose(f);
    return 0;
}

*/

int PrintStudent()
{
    if (file_open() == -2)
    {
        printf("Файл не был сформирован. Попросим вас его сформировать.\n");
    }

    int i = 1;
    
    //while (!feof(data)) {
    //    fread(&buffer, sizeof(buffer), 1, data);
    //    while (fread(&avt, sizeof(avt), 1, f) > 0)
    while (fread(&buffer, sizeof(buffer), 1, data) > 0) {
    
        printf("Запись данных %d-ого студента...\n", i);
        printf("\n Имя студента : ");
        printf("%s", buffer.name);
        printf("\n Номер группы студента : ");
        printf("%d", buffer.group_number);
        printf("\n Средний балл студента : ");
        printf("%f", buffer.average_mark);
        printf("\n%d - дисциплина 'физика'.", buffer.electives[0]);
        printf("\n%d - дисциплина 'программирование'.", buffer.electives[1]);
        printf("\n%d - дисциплина 'математика'.", buffer.electives[2]);
        printf("\n%d - дисциплина 'английский язык'.", buffer.electives[3]);
        printf("\n%d - дисциплина 'базы данных'.", buffer.electives[4]);
        i++;
    }
    if (i == 1)
    {
        printf("Файл не существует или не содержит данных.\n");
    }
    fclose(data);
    return 0;
}

void TableStudent()
{
   
    printf("----------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| Фамилия студента |  Номер группы |  Средний балл  | Физика | Программирование |  Математика  | Английский язык | | Базы данных |\n");
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
    printf("| СОРТИРОВКА ЗАПИСЕЙ                 |");
    printf("\n--------------------------------------");
    while (true)
    {
        /*switch ()
        {

        }*/
    }
}