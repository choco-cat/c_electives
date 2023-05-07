﻿
#include "Prototypes and Classes.h"

/*Для формирования факультативных занятий необходимо обработать информацию следующего вида: 
ФИО студента, номер группы, средний балл успеваемости, пять возможных для факультативного посещения дисциплин. 
Выбираемая дисциплина помечается 1, невыбираемая – 0. Перечень предлагаемых дисциплин: математика, физика, программирование, английский язык, базы данных.
Индивидуальное задание: вывести список и общее количество студентов, желающих прослушать дисциплину х. 
Если число желающих больше 15, то отобрать 15 студентов с более высоким баллом успеваемости. 
Вывести предлагаемые дисциплины в порядке убывания популярности с указанием общего числа записавшихся на каждую из них.
Общее для всех вариантов задание: реализовать авторизацию для входа в систему, функционал администратора 
*/

int main()
{
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
					 printf("--------------------------------------"
						 "\n| Осуществляем выход из программы... |\n"
						 "| До скорой встречи!                 |\n"
						 "--------------------------------------\n");
					 return 0;
				 }
				 if (choice == -5)
				 {
					 printf("\n\n-------------------------------------------\n");
					 printf(    "| Осуществляем выход из учётной записи... |\n");
					 printf(    "-------------------------------------------\n");
					 break;
				 }
			}
			break;
		case '2':
			loginUser();
			break;
		case '3':
			printf("--------------------------------------"
				"\n| Осуществляем выход из программы... |\n" 
				  "| До скорой встречи!                 |\n" 
				  "--------------------------------------\n");
			return 0;
		default:
			printf("\nБыл введён некорректный номер подзадачи. Ожидается корректый номер сущесутвующей задачи.");
		}
	}
}