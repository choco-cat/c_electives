
#include "Prototypes and Classes.h"

Teacher teachers[5];

Teacher editTeacher()
{
	printf("\n\n�������� � ������������� ������ ������������ �� ������� ��������?");
	int index =	list() - 1;
    printf("\n����������� %s", ALLDATA[index][1]);
    printf("\n������� ������� ������������� : ");
    scanf_s("%s", &teachers[index].name, sizeof(teachers[index].name));
    printf("\n������� ����� �������� ������������� : ");
    scanf_s("%s", &teachers[index].phone_number, sizeof(teachers[index].phone_number));
    printf("\n������� �������� ������� : ");
    scanf_s("%s", &teachers[index].department, sizeof(teachers[index].department));
    printf("\n������� ������� ������ ������������� : ");
    scanf_s("%s", &teachers[index].scientific_title, sizeof(teachers[index].scientific_title));
	return teachers[index];
}

Teacher getTeacher(int id)
{
    return teachers[id];
}