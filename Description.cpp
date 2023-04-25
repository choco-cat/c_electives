
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
        printf("\nÄèñöèïëèíà ïîä íîìåðîì %d áûëà óñïåøíî äîáàâëåíà â ñïèñîê æåëàåìûõ.", number );
    }
}

int file_open()
{
    err = fopen_s(&data, "DataOfStudent.bin", "a+");
    if (!data)
    {
        printf("Îøèáêà ïðè ðàáîòå ñ ôàéëîì (åãî ñîçäàíèè èëè îòêðûòèè) .\n");
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
    printf(    "| Îñóùåñòâëÿåì äîáàâëåíèå ñâåäåíèé î ñòóäåíòå... |\n");
    printf(    "--------------------------------------------------\n");
    printf("Êàêîå êîëè÷åñòâî ñâåäåíèé âû æåëàåòå äîáàâèòü?");
    scanf_s("%d", &n);
    int count = 0;
    while (count < n)
    {
        printf("Çàïèñü äàííûõ %d-îãî ñòóäåíòà...\n", count + 1);
        puts("Ââåäèòå ôàìèëèþ ñòóäåíòà : \n");
        fflush(stdin);
        getchar();
        gets_s(buffer.name);
        puts("Ââåäèòå íîìåð ãðóïïû ñòóäåíòà :\n");
        //fflush(stdin);
        //getchar();
        scanf_s("%d", &buffer.group_number);
        puts("\nÂâåäèòå ñðåäíèé áàëë ñòóäåíòà.\n");
        scanf_s("%f", &buffer.average_mark);
        //faculties(buffer);
        printf("\nÔèçèêà? ");
        scanf_s("%d", &buffer.electives[0]);

        printf("\nÏðîãðàììèðîâàíèå? ");
        scanf_s("%d", &buffer.electives[1]);
        printf("\nÌàòåìàòèêà? ");
        scanf_s("%d", &buffer.electives[2]);
        printf("\nÀíãëèéñêèé ÿçûê? ");
        scanf_s("%d", &buffer.electives[3]);
        printf("\nÁàçû äàííûõ? ");
        scanf_s("%d", &buffer.electives[4]);
        printf("\nÄàííûå %d-îé èíôîðìàöèè áûëè çàïèñàíû â áèíàðíûé ôàéë.\n", count + 1);
        fwrite(&buffer, sizeof(buffer), 1, data);//çàïèñü öåëèêîì
        count++;
    }
    fclose(data);
    printf("\nÁèíàðíûé ôàéë, ñîñòîÿùèé èç ýëåìåíòîâ ñòðóêòóðû áûë óñïåøíî ñôîðìèðîâàí.\n");
    stud++;
    return 0;
	
}

int menu()
{
    int n;
    printf("\nÍàø àññîðòèìåíò ôóíêöèé :");
    printf("\n1 - Ôîðìèðîâàíèå áèíàðíîãî ôàéëà èç ýëåìåíòîâ, çàäàííîé ñòðóêòóðû.");
    printf("\n2 - Ïå÷àòü ôîðìèðîâàííîãî áèíàðíîãî ôàéëà.");
    printf("\n3 - Äîáàâëåíèå äàííûõ î äðóãèõ ìàøèíàõ.");
    printf("\n4 - Ïîèñê äàííûõ î ìàøèíå ïî ìàðêå.");
    printf("\n5 - Âûõîä èç ïðîãðàììû.");
    printf("\n×åãî èçâîëèòå?\n");
    scanf_s("%d", &n);
    return n;
}

/*
int form_file()
{
    prov = 1;
    int k;
    printf("\nÍà÷èíàåì ôîðìèðîâàíèå ôàéëà...\n");
    if (file_open() == -2)
    {
        return 0;
    }
    printf("\nÂâåäèòå ïëàíèðóåìûõ çàïèñåé äàííûõ àâòîìîáèëåé n = ");
    scanf_s("%d", &n);
    count = 0;
    while (count < n)
    {
        printf("Çàïèñü äàííûõ %d-îãî àâòîìîáèëÿ...\n", count + 1);
        puts("Ââåäèòå ðåãèñòðàöèîííûé íîìåð àâòîìîáèëÿ :\n");
        fflush(stdin);
        getchar();
        gets_s(avt.regnomer);
        puts("Ââåäèòå ìàðêó àâòîìîáèëÿ :\n");
        gets_s(avt.mark);
        puts("Ââåäèòå èìÿ ìàñòåðà àâòîìîáèëÿ :\n");
        gets_s(avt.master);
        do
        {
            printf("Ââåäèòå äëèíó ïðîáåãà (â êèëîìåòðàõ) àâòîìîáèëÿ :\n");
            scanf_s("%f", &avt.probeg);
            if (avt.probeg <= 0)
            {
                printf("\nÍåäîïóñòèìîå çíà÷åíèå äëèíà ïðîáåãà àâòîìîáèëÿ.");
            }
        } while (avt.probeg <= 0);
        printf("\nÄàííûå %d-îãî àâòîìîáèëÿ áûëè çàïèñàíû â áèíàðíûé ôàéë.\n", count + 1);
        fwrite(&avt, sizeof(avt), 1, f);//çàïèñü öåëèêîì
        count++;
    }

    fclose(f);
    printf("\nÁèíàðíûé ôàéë, ñîñòîÿùèé èç ýëåìåíòîâ ñòðóêòóðû áûë óñïåøíî ñôîðìèðîâàí.\n");
    return 0;
}
*/

/*
int vivod_file()
{
    if (file_open() == -2)
    {
        printf("Ôàéë íå áûë ñôîðìèðîâàí. Ïîïðîñèì âàñ åãî ñôîðìèðîâàòü.\n");
    }

    int i = 1;

    while (fread(&avt, sizeof(avt), 1, f) > 0)
    {
        printf("\nÄàííûå %d-îãî àâòîìîáèëÿ.", i);
        printf("\nÐåãèñòðàöèîííûé íîìåð àâòîìîáèëÿ : ");
        printf("%s\n", avt.regnomer);
        printf("Ìàðêà àâòîìîáèëÿ : ");
        printf("%s\n", avt.mark);
        printf("Èìÿ ìàñòåðà àâòîìîáèëÿ : ");
        printf("%s\n", avt.master);
        printf("Äëèíà ïðîáåãà àâòîìîáèëÿ ( â êèëîìåòðàõ) : ");
        printf("%f\n", avt.probeg);
        i++;
    }

    if (i == 1) {
        printf("Ôàéë íå ñóùåñòâóåò èëè íå ñîäåðæèò äàííûõ.\n");
    }

    fclose(f);
    return 0;
}

*/

int PrintStudent()
{
    if (file_open() == -2)
    {
        printf("Ôàéë íå áûë ñôîðìèðîâàí. Ïîïðîñèì âàñ åãî ñôîðìèðîâàòü.\n");
    }

    int i = 1;
    
    //while (!feof(data)) {
    //    fread(&buffer, sizeof(buffer), 1, data);
    //    while (fread(&avt, sizeof(avt), 1, f) > 0)
    while (fread(&buffer, sizeof(buffer), 1, data) > 0) {
    
        printf("Çàïèñü äàííûõ %d-îãî ñòóäåíòà...\n", i);
        printf("\n Èìÿ ñòóäåíòà : ");
        printf("%s", buffer.name);
        printf("\n Íîìåð ãðóïïû ñòóäåíòà : ");
        printf("%d", buffer.group_number);
        printf("\n Ñðåäíèé áàëë ñòóäåíòà : ");
        printf("%f", buffer.average_mark);
        printf("\n%d - äèñöèïëèíà 'ôèçèêà'.", buffer.electives[0]);
        printf("\n%d - äèñöèïëèíà 'ïðîãðàììèðîâàíèå'.", buffer.electives[1]);
        printf("\n%d - äèñöèïëèíà 'ìàòåìàòèêà'.", buffer.electives[2]);
        printf("\n%d - äèñöèïëèíà 'àíãëèéñêèé ÿçûê'.", buffer.electives[3]);
        printf("\n%d - äèñöèïëèíà 'áàçû äàííûõ'.", buffer.electives[4]);
        i++;
    }
    if (i == 1)
    {
        printf("Ôàéë íå ñóùåñòâóåò èëè íå ñîäåðæèò äàííûõ.\n");
    }
    fclose(data);
    return 0;
}

void TableStudent()
{
   
    printf("----------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| Ôàìèëèÿ ñòóäåíòà |  Íîìåð ãðóïïû |  Ñðåäíèé áàëë  | Ôèçèêà | Ïðîãðàììèðîâàíèå |  Ìàòåìàòèêà  | Àíãëèéñêèé ÿçûê | | Áàçû äàííûõ |\n");
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
    printf("| ÑÎÐÒÈÐÎÂÊÀ ÇÀÏÈÑÅÉ                 |");
    printf("\n--------------------------------------");
    while (true)
    {
        /*switch ()
        {

        }*/
    }
}
