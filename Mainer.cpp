#include "Prototypes and Classes.h"

/*Для формирования факультативных занятий необходимо обработать информацию следующего вида: 
ФИО студента, номер группы, средний балл успеваемости, пять возможных для факультативного посещения дисциплин. 
Выбираемая дисциплина помечается 1, невыбираемая – 0. Перечень предлагаемых дисциплин: математика, физика, программирование, английский язык, базы данных.
Индивидуальное задание: вывести список и общее количество студентов, желающих прослушать дисциплину х. 
Если число желающих больше 15, то отобрать 15 студентов с более высоким баллом успеваемости. 
Вывести предлагаемые дисциплины в порядке убывания популярности с указанием общего числа записавшихся на каждую из них.
Общее для всех вариантов задание: реализовать авторизацию для входа в систему, функционал администратора 
*/

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//SetConsoleTextAttribute(hConsole, FOREGROUND_RED);



int main()
{
	system("color F0");
	FILE* phisic, * math, * english, * database, * programming;
	int choice;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("--------------------------------------\n");
	printf("| Добро пожаловать в нашу программу! |");
	printf("\n--------------------------------------");
	while (true)
	{
		switch (firstMenu())
		{
		case '1':
			if (loginAdmin()) {
				choice = interfaceOfAdmin();
				if (choice == -10)
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
					printf("\n\n--------------------------------------"
						"\n| Осуществляем выход из программы... |\n"
						"| До скорой встречи!                 |\n"
						"--------------------------------------\n");
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					return 0;
				}
				if (choice == -5)
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
					printf("\n\n-------------------------------------------\n");
					printf("| Осуществляем выход из учётной записи... |\n");
					printf("-------------------------------------------\n");
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					system("pause");
					system("cls");
					system("color F0");
					break;
				}
			}
			break;
		case '2':
			if (loginUser()) {
				choice = interfaceOfUser();
				if (choice == -10)
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
					printf("\n\n--------------------------------------"
						"\n| Осуществляем выход из программы... |\n"
						"| До скорой встречи!                 |\n"
						"--------------------------------------\n");
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					return 0;
				}
				if (choice == -5)
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
					printf("\n\n-------------------------------------------\n");
					printf("| Осуществляем выход из учётной записи... |\n");
					printf("-------------------------------------------\n");
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					system("pause");
					system("cls");
					system("color F0");
					break;
				}
			}
			break;
		case '3':
			printf("--------------------------------------"
				"\n| Осуществляем выход из программы... |\n"
				"| До скорой встречи!                 |\n"
				"--------------------------------------\n");
			return 0;
		default:
			printf("\nБыл введён некорректный номер подзадачи. Ожидается корректый номер сущесутвующей задачи.\n\n");
			system("pause");
			system("cls");
		}
	}
}