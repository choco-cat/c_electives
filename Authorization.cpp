
#include "Prototypes and Classes.h"

#define authAdmin "login_of_admin.txt"          
#define authUser "logins_of_user.txt"    
#define passAdmin "Passwords_Of_Admin.txt"
#define passUser "Passwords_Of_User.txt"


int firstMenu()
{
	char yourChoice;
	printf( "\n\n-------------------------------\n");
	printf( "| Осуществляем авторизацию... |\n");
	printf( "-------------------------------\n");
	printf( "\n***********************************************\n*\n");
	printf( "*   1 - авторизация в качестве администратора. \n");
	printf( "*   2 - авторизация в качестве пользователя. \n");
	printf( "*   3 - выход из программы. \n*");
	printf( "\n***********************************************\n");
	yourChoice =_getch();
	return yourChoice;
}

int secondMenuOfAdmin()
{
	char yourChoice;

		printf("\n\n-------------------------------\n");
		printf("| Меню администратора |\n");
		printf("-------------------------------\n");
		printf("\n***********************************************\n*\n");
		printf("*   1 - добавить запись \n");
		printf("*   2 - редактировать запись \n");
		printf("*   3 - удалить запись \n");
		printf("*   0 - выход в основное меню \n*");
		printf("*   6 - печать студента \n*");
		printf("\n***********************************************\n");
		yourChoice = _getch();
		if (yourChoice == '4') {
			return 0;
		}
	
	return yourChoice;
}

int secondMenuOfUser()
{
	char yourChoice;
	yourChoice = _getch();
	return yourChoice;
}

int interfaceOfAdmin()
{
	char key;
	printf("\nВы успешно авторизовались в качестве админстратора, теперь вам доступен список администраторских функций.");
	do
	{
		key = secondMenuOfAdmin();
		printf("\nВы успешно авторизовались в качестве админстратора, теперь вам доступен список администраторских функций");
		switch (key)
		{
		case '1':
			printf("\nДобавляем запись:");
			AddStudent();
			break;
		case '2':
			//printf("\nРедактируем запись:");
			break;
		case '3':
			//printf("\nУдаляем запись:");
			break;
		case '4':
			//printf("\nВыход в основное меню:");
			break;
		case '5':
			
		case '6':
			PrintStudent();
			break;
		case '7':
			TableStudent();
			break;
		case '8':

			break;
		case '9':

			break;
		case '0':
			printf("\nВыход в основное меню:");
			break;
		case '?':

			break;
		default:
			printf("\nБыл введён некорректный номер подзадачи. Ожидается корректый номер сущесутвующей задачи.");
			break;
		}
	} while (key != '0');
	return 0;
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
		return 0;
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
				return 0;
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
				return 0;
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
	return 1;
}