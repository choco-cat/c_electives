
#include "Prototypes and Classes.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("--------------------------------------\n");
	printf("| ����� ���������� � ���� ���������! |");
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
				"\n| ������������ ����� �� ���������... |\n" 
				"| �� ������ �������!                 |\n" 
				"--------------------------------------\n");
			return 0;
		default:
			printf("\n��� ����� ������������ ����� ���������. ��������� ��������� ����� ������������� ������.");
		}
	}
}