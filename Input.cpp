
#include "Prototypes and Classes.h"

int checkInputDataName(char* name)
{
	for (register int i = 0; name[i] != '\0'; i++)
	{
		if (!isalpha(name[i]))
		{
			printf("\nНекорректный ввод. Повторите ввод.\n");
			return 0;
		}
	}
	return 1;
}

int checkInputDataGroup(int group)
{
	if (group < 0 || group > 999999)
	{
		printf("\nНекорректный ввод. Повторите ввод.\n");
		return 0;
	}
	return 1;
}

int checkInputDataAvarageMark(float number)
{
	if (number < 0 || number > 10)
	{
		printf("\nНекорректный ввод. Повторите ввод.\n");
		return 0;
	}
	return 1;
}

int checkInputDataElective(int number)
{
	if (number != 0 && number != 1)
	{
		printf("\nНекорректный ввод. Повторите ввод.\n");
		return 0;
	}
	return 1;
}
