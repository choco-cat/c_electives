
#include "Prototypes and Classes.h"

#define authAdmin "login_of_admin.txt"          
#define authUser "logins_of_user.txt"    
#define passAdmin "Passwords_Of_Admin.txt"
#define passUser "Passwords_Of_User.txt"

HANDLE hConsole1 = GetStdHandle(STD_OUTPUT_HANDLE);

void infoOfAuthor();

int firstMenu()
{
	char yourChoice;
	printf( "\n\n-------------------------------\n");
	printf( "| ������������ �����������... |\n");
	printf( "-------------------------------\n");
	printf( "\n**************************************************\n");
	printf(   "*                                                *\n");
	printf(   "*   1 - ����������� � �������� ��������������.   *\n");
	printf(   "*   2 - ����������� � �������� ������������.     *\n");
	printf(   "*   3 - ����� �� ���������.                      *\n");
	printf(   "*                                                *");
	printf( "\n**************************************************\n");
	yourChoice =_getch();
	return yourChoice;
}

int secondMenuOfAdmin()
{
	char yourChoice;
	system("cls");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_BLUE);
	printf("\n\n-------------------------------\n");
	printf(    "| ���� ��������������         |\n");
	printf("-------------------------------\n");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_GREEN);
	printf( "\n**********************************************************************************\n");
	printf(   "*                                                                                *\n");
	printf(   "*   + - �������������� �������� � ������������� ������������.                    *\n");
	printf(   "*   1 - ���������� ������ ������ �������� � ����������� �������.                 *\n");
	printf(   "*   2 - �������������� ������ ������ ������������ ��������.                     *\n");
	printf(   "*   3 - �������� ������ ������ ������������ ��������.                           *\n");
	printf(   "*                                                                                *\n");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf(   "|                                                                                |\n");
	printf(   "|   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -    |\n");
	printf(   "|                           ������������� �������  :                             |\n");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_GREEN);
	printf("*                                                                                *\n");
	printf(   "*   4 - ���������� ��������� �� �������� �����.                                  *\n");
	printf(   "*   5 - �������� ���� ���������, �������� ���������� �� ����������� �����������.*\n");
	printf(   "*   6 - ����� �� ����� ������ ������������ ������ ������������������ ���������.  *\n");
	printf(   "*   7 - ��������� � ������� ������ ����������� ������������ ������������.       *\n");
	printf(   "*   8 - ������� ������ ������������� � ������� �� ��������������.                *\n");
	printf("*                                                                                *\n");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf(   "|                                                                                |\n");
	printf(   "|   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -    |\n");
	printf(   "|                                                                                |\n");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_GREEN);
	printf(   "*                                                                                *\n");
	printf(   "*   9 - ����� �� ������� ������.                                                 *\n");
	printf(   "*   0 - ����� �� ���������.                                                      *\n");
	printf(   "*   ? - ������������ ��.                                                         *\n");
	printf(   "*                                                                                *");
	printf("\n**********************************************************************************\n");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	yourChoice = _getch();
	return yourChoice;
}

int secondMenuOfUser()
{
	char yourChoice;
	printf("\n\n-------------------------------\n");
	printf("| ���� ������������         |\n");
	printf("    -------------------------------\n");
	printf("\n**********************************************************************************\n*\n");
	printf("*   1 - ���������� ����� ������ ������ � ����������� �������. \n");
	printf("*   2 - ���������� ��������� �� �������� ����� �� ����������� ������������. \n");
	printf("*   3 - ������� ������ ����������� ������������ ������������. \n");
	printf("*   4 - ������� ������ ������������� � ������� �� ��������������. \n");
	printf("*   5 - ����� �� ������� ������. \n");
	printf("*   6 - ����� �� ���������. \n*");
	printf("\n**********************************************************************************\n");
	yourChoice = _getch();
	return yourChoice;
}

int interfaceOfAdmin()
{
	system("cls");
	system("color 0F");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_RED);
	printf("\n�� ������� �������������� � �������� �������������, ������ ��� �������� ������ ����������������� �������.");
	while (1)
	{
		switch (secondMenuOfAdmin())
		{
		case '1':
			addStudent();
			break;
		case '2':
			editStudent();
			break;
		case '3':
			deleteStudents();
			break;
		case '4':
			sortStudents();
			//printf("\n����� � �������� ����:");
			break;
		case '5':
			lookElective();
			break;
		case '6':
			tableStudents();
			break;
		case '7':
			sortStudentsOfElective();
			break;
		case '8':
			topOfElective(); 
			break;
		case '9':
			return -5;
			break;
		case '0':
			return -10;
			break;
		case '?':
			infoOfAuthor();
			break;
		case '+':
			addTeacher();
			break;
		default:
			SetConsoleTextAttribute(hConsole1, FOREGROUND_RED);
			printf("\n��� ����� ������������ ����� ���������. ��������� ��������� ����� ������������� ������.\n\n");
			SetConsoleTextAttribute(hConsole1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}

int deleteStudents()
{
	system("cls");

	char vibor = '0';
	char viborField = '0';
	int quantity = 0;
	int number = 0;

	while (true) {
		system("cls");

		puts("\t�������� ������\n");
		int quantity = tableStudents();
		printf("������� ����� ������, ������� ���������� �������: ");
		do {
			scanf_s("%d", &number);
			fflush(stdin);
			if (number < 1 || number > quantity) {
				printf("������ � ����� ������� ���. ��������� ����: ");
			}
			else
				break;
		} while (true);

		return deleteStudent(number);
	}
}

int loginAdmin()
{
	system("cls");
	int counter = 0;
	puts("\t--- ���� ��� ��������������� ---\n");
	char login[20], file_login[20];
	char password[20], file_password[20];
	int i = 0;
	puts("��� ����� ������ � ������ � ��� ���� 3 �������.");
	printf("������� �����: ");
	FILE* lpa;
	fopen_s(&lpa, authAdmin, "r");
	if (lpa == NULL) {
		printf("���������� ������� ����");
		return 0;
	}

	fseek(lpa, 0, SEEK_SET);
	fscanf_s(lpa, "%s", file_login, sizeof(file_login));
	do {
		scanf_s("%s", login, sizeof(file_login));
		fflush(stdin);
		printf("\nlogin %s\n", login);
		if (strcmp(login, file_login)) {
			counter++;
			if (counter == 3) {
				puts("�� ��������� ���� �������.");
				_getch();
				fclose(lpa);
				return 0;
			}
			printf("����� ������ �������. ���������� ���������� ������� ��� ����� ������: %d.\n��������� �����: ", 3 - counter);
		}
		else break;
	} while (1);

	printf("������� ������: ");
	fscanf_s(lpa, "%s", file_password, sizeof(file_password));

	counter = 0;
	do {
		for (i = 0; (password[i] = _getch()) != '\r';) {
			if (password[i] == '\b' && i != 0) {
				printf("%s", "\b \b");
				i--;
			}
			else if (password[i] != '\b') {
				printf("%c", '*');
				i++;
			}
		}
		password[i] = '\0';

		if (strcmp(password, file_password)) {
			counter++;
			if (counter == 3) {
				puts("\n�� ��������� ���� �������.");
				_getch();
				fclose(lpa);
				return 0;
			}
			printf("\n������ ������ �������. ���������� ���������� ������� ��� ����� ������: %d.\n��������� ������: ", 3 - counter);
		}
		else break;
	} while (1);
	fclose(lpa);
	return 1;
}

int loginUser() {    
	FILE* lpu;
	system("cls");
	int counter = 0;
	char login[20], file_login[20];
	char password[20], file_password[20];
	int sch = 0;
	int i = 0;
	printf("����������� ������������...");
	fopen_s(&lpu, authUser, "r");
	if (lpu == NULL) {
		printf("���������� ������� ����");
		return 0;
	}
	else {
		printf("���� ������ ����������� ������");
	}

	fseek(lpu, 0, SEEK_SET);
	fscanf_s(lpu, "%s", file_login, sizeof(file_login));

	if (feof(lpu)) {
		puts("�� ���� ������������ �� ������.");
		_getch();
		fclose(lpu);
		return 1;
	}

	puts("\t--- ���� ��� ������������� ---\n");

	puts("��� ����� ������ � ������ � ��� ���� 3 �������.");
	do {
		printf("������� �����: ");
		scanf_s("%s", login, sizeof(login));
		fflush(stdin);
		printf("������� ������: ");
		for (i = 0; (password[i] = _getch()) != '\r';) {
			if (password[i] == '\b' && i != 0) {
				printf("%s", "\b \b");
				i--;
			}
			else if (password[i] != '\b') {
				printf("%c", '*');
				i++;
			}
		}
		password[i] = '\0';

		sch = 0;
		rewind(lpu);
		do {
			fscanf_s(lpu, "%s %s", file_login, (unsigned)_countof(file_login), file_password, (unsigned)_countof(file_password));
			if (feof(lpu)) {
				break;
			}
			if (!strcmp(login, file_login)) {
				sch = 1;
				break;
			}
		} while (1);
		if (sch == 0) {
			counter++;
			if (counter == 3) {
				puts("\n�� ��������� ���� �������.");
				_getch();
				fclose(lpu);
				return 1;
			}
			printf("\n������ \"%s\" ���. ���������� ���������� ������� ��� ����� ������: %d.\n��������� ����.\n", login, 3 - counter);
		}
		else break;
	} while (1);
	fclose(lpu);
	counter = 0;

	do {
		if (strcmp(password, file_password)) {
			counter++;
			if (counter == 3) {
				puts("\n�� ��������� ���� �������.");
				_getch();
				return 1;
			}
			printf("\n�������� ������. ���������� ���������� ������� ��� ����� ������: %d.\n��������� ������: ", 3 - counter);
		}
		else {
			break;
		}
		for (i = 0; (password[i] = _getch()) != '\r';) {
			if (password[i] == '\b' && i != 0) {
				printf("%s", "\b \b");
				i--;
			}
			else if (password[i] != '\b') {
				printf("%c", '*');
				i++;
			}
		}
		password[i] = '\0';
	} while (1);
	return 0;
}

void infoOfAuthor()
{

	system("cls");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_BLUE);
	printf("\n\n--------------------------------------------\n");
	printf(    "| �� ���� ����������� ��������� 1 �����... |\n");
	printf(    "--------------------------------------------\n");
	printf("\n\n-----------------------------------------------\n|");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_GREEN);
	printf(" ����������� : ");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf(	"���������� ��������� �������� ");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_BLUE);
	printf(    "|\n-----------------------------------------------\n");
	printf("\n\n----------------------------------------------------\n|");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_GREEN);
	printf(" �������� ����� : ");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf(	"stasa_stasa_stasa_stasa@mail.ru");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_BLUE);
	printf(    " |\n----------------------------------------------------\n");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_RED);
	printf("\n\n------------------------------------------------------------------------------------------------------\n");
	printf(    "| ��� ������������ ������ ��������� ��������� ������ �� ����������� ����� � �������� ���� ���������. |\n");
	printf(    "------------------------------------------------------------------------------------------------------\n");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_BLUE);
	printf("\n\n--------------------------\n|");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_GREEN);
	printf(" ������ �� : ");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("1.0 (BETA) ");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_BLUE);
	printf(    "|\n--------------------------\n\n\n");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	system("pause");
	system("cls");

}
