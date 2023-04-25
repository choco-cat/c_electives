
#include "Prototypes and Classes.h"

int main()
{
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
				interfaceOfAdmin();
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