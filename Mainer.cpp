#include "Prototypes and Classes.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	system("color F0");
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
					goOut();
					return 0;
				}
				if (choice == -5)
				{
					goBack();
					break;
				}
			}
			break;
		case '2':
			if (loginUser()) {
				choice = interfaceOfUser();
				if (choice == -10)
				{
					goOut();
					return 0;
				}
				if (choice == -5)
				{
					goBack();
					break;
				}
			}
			break;
		case '$':
			if (regUser()) {
				choice = interfaceOfUser();
				if (choice == -10)
				{
					goOut();
					return 0;
				}
				if (choice == -5)
				{
					goBack();
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