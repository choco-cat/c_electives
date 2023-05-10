
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
	printf( "| Осуществляем авторизацию... |\n");
	printf( "-------------------------------\n");
	printf( "\n**************************************************\n");
	printf(   "*                                                *\n");
	printf(   "*   1 - авторизация в качестве администратора.   *\n");
	printf(   "*   2 - авторизация в качестве пользователя.     *\n");
	printf(   "*   3 - выход из программы.                      *\n");
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
	printf(    "| Меню АДМИНИСТРАТОРА         |\n");
	printf("-------------------------------\n");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_GREEN);
	printf( "\n**********************************************************************************\n");
	printf(   "*                                                                                *\n");
	printf(   "*   + - редактирование сведений о преподавателе факультативе.                    *\n");
	printf(   "*   1 - добавление личных данных студента в рейтинговую систему.                 *\n");
	printf(   "*   2 - редактирование личных данных определённого студента.                     *\n");
	printf(   "*   3 - удаление личных данных определённого студента.                           *\n");
	printf(   "*                                                                                *\n");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf(   "|                                                                                |\n");
	printf(   "|   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -    |\n");
	printf(   "|                           ИНДИВИДУЛЬНОЕ ЗАДАНИЕ  :                             |\n");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_GREEN);
	printf("*                                                                                *\n");
	printf(   "*   4 - сортировка студентов по среднему баллу.                                  *\n");
	printf(   "*   5 - просмотр всех студентов, желающих записаться на определённый факультатив.*\n");
	printf(   "*   6 - вывод на экран списка персональных данных зарегистрированных студентов.  *\n");
	printf(   "*   7 - составить и вывести списки зачисленных определённого факультатива.       *\n");
	printf(   "*   8 - вывести список факультативов в порядке их пополулярности.                *\n");
	printf("*                                                                                *\n");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf(   "|                                                                                |\n");
	printf(   "|   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -    |\n");
	printf(   "|                                                                                |\n");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_GREEN);
	printf(   "*                                                                                *\n");
	printf(   "*   9 - выход из учётной записи.                                                 *\n");
	printf(   "*   0 - выход из программы.                                                      *\n");
	printf(   "*   ? - техподдержка ПО.                                                         *\n");
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
	printf("| Меню ПОЛЬЗОВАТЕЛЯ         |\n");
	printf("    -------------------------------\n");
	printf("\n**********************************************************************************\n*\n");
	printf("*   1 - добавление СВОИХ личных данных в рейтинговую систему. \n");
	printf("*   2 - сортировка студентов по среднему баллу на определённом факультативе. \n");
	printf("*   3 - вывести списки зачисленных определённого факультатива. \n");
	printf("*   4 - вывести список факультативов в порядке их пополулярности. \n");
	printf("*   5 - выход из учётной записи. \n");
	printf("*   6 - выход из программы. \n*");
	printf("\n**********************************************************************************\n");
	yourChoice = _getch();
	return yourChoice;
}

int interfaceOfAdmin()
{
	system("cls");
	system("color 0F");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_RED);
	printf("\nВы успешно авторизовались в качестве админстратора, теперь вам доступен список администраторских функций.");
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
			printf("\nБыл введён некорректный номер подзадачи. Ожидается корректый номер сущесутвующей задачи.\n\n");
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

		puts("\tУдаление данных\n");
		int quantity = tableStudents();
		if (quantity == 0)
		{
			return 0;
		}
		printf("Введите номер записи, которую необходимо удалить: ");
		do {
			scanf_s("%d", &number);
			fflush(stdin);
			if (number < 1 || number > quantity) {
				printf("Записи с таким номером нет. Повторите ввод: ");
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
	puts("\t--- Вход под администратором ---\n");
	char login[20], file_login[20];
	char password[20], file_password[20];
	int i = 0;
	puts("Для ввода логина и пароля у Вас есть 3 попытки.");
	printf("Введите логин: ");
	FILE* lpa;
	fopen_s(&lpa, authAdmin, "r");
	if (lpa == NULL) {
		printf("Невозможно открыть файл");
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
				puts("Вы исчерпали свои попытки.");
				_getch();
				fclose(lpa);
				return 0;
			}
			printf("Логин введен неверно. Оставшееся количество попыток для ввода логина: %d.\nПовторите логин: ", 3 - counter);
		}
		else break;
	} while (1);

	printf("Введите пароль: ");
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
				puts("\nВы исчерпали свои попытки.");
				_getch();
				fclose(lpa);
				return 0;
			}
			printf("\nПароль введен неверно. Оставшееся количество попыток для ввода пароля: %d.\nПовторите пароль: ", 3 - counter);
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
	printf("Авторизация пользователя...");
	fopen_s(&lpu, authUser, "r");
	if (lpu == NULL) {
		printf("Невозможно открыть файл");
		return 0;
	}
	else {
		printf("Файл данных авторизации найден");
	}

	fseek(lpu, 0, SEEK_SET);
	fscanf_s(lpu, "%s", file_login, sizeof(file_login));

	if (feof(lpu)) {
		puts("Ни один пользователь не создан.");
		_getch();
		fclose(lpu);
		return 1;
	}

	puts("\t--- Вход под пользователем ---\n");

	puts("Для ввода логина и пароля у Вас есть 3 попытки.");
	do {
		printf("Введите логин: ");
		scanf_s("%s", login, sizeof(login));
		fflush(stdin);
		printf("Введите пароль: ");
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
				puts("\nВы исчерпали свои попытки.");
				_getch();
				fclose(lpu);
				return 1;
			}
			printf("\nЛогина \"%s\" нет. Оставшееся количество попыток для ввода логина: %d.\nПовторите ввод.\n", login, 3 - counter);
		}
		else break;
	} while (1);
	fclose(lpu);
	counter = 0;

	do {
		if (strcmp(password, file_password)) {
			counter++;
			if (counter == 3) {
				puts("\nВы исчерпали свои попытки.");
				_getch();
				return 1;
			}
			printf("\nНеверный пароль. Оставшееся количество попыток для ввода пароля: %d.\nПовторите пароль: ", 3 - counter);
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
	printf(    "| ПО было разработано студентом 1 курса... |\n");
	printf(    "--------------------------------------------\n");
	printf("\n\n-----------------------------------------------\n|");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_GREEN);
	printf(" Разработчик : ");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf(	"ПАНФИЛЕНКО СТАНИСЛАВ ИГОРЕВИЧ ");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_BLUE);
	printf(    "|\n-----------------------------------------------\n");
	printf("\n\n----------------------------------------------------\n|");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_GREEN);
	printf(" Обратная связь : ");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf(	"stasa_stasa_stasa_stasa@mail.ru");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_BLUE);
	printf(    " |\n----------------------------------------------------\n");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_RED);
	printf("\n\n------------------------------------------------------------------------------------------------------\n");
	printf(    "| При некорректной работе программы отправьте письмо на электронную почту с заданной вами проблемой. |\n");
	printf(    "------------------------------------------------------------------------------------------------------\n");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_BLUE);
	printf("\n\n--------------------------\n|");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_GREEN);
	printf(" Версия ПО : ");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("1.0 (BETA) ");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_BLUE);
	printf(    "|\n--------------------------\n\n\n");
	SetConsoleTextAttribute(hConsole1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	system("pause");
	system("cls");

}
