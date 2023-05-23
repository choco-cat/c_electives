
#include "Prototypes and Classes.h"

int checkInputDataName(char* name)
{
	for (register int i = 0; name[i] != '\0'; i++)
	{
		if (!isalpha(name[i]))
		{
			printf("\n������������ ����. ��������� ����.\n");
			return 0;
		}
	}
	return 1;
}

int checkInputDataGroup(int number)
{
	if (number < 0 || number > 999999)
	{
		printf("\n������������ ����. ��������� ����.\n");
		return 0;
	}
	return 1;
}

int checkInputDataAvarageMark(float number)
{
	if (number < 0 || number > 10)
	{
		printf("\n������������ ����. ��������� ����.\n");
		return 0;
	}
	return 1;
}

