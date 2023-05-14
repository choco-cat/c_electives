
#include "Prototypes and Classes.h"

Teacher teachers[5];

Teacher editTeacher()
{
	printf("\n\nСведения о преподавателе какого факультатива вы желаете изменить?");
	int index =	list() - 1;
    printf("\nФакультатив %s", ALLDATA[index][1]);
    printf("\nВведите фамилию преподавателя : ");
    scanf_s("%s", &teachers[index].name, sizeof(teachers[index].name));
    printf("\nВведите номер телефона преподавателя : ");
    scanf_s("%s", &teachers[index].phone_number, sizeof(teachers[index].phone_number));
    printf("\nВведите название кафедры : ");
    scanf_s("%s", &teachers[index].department, sizeof(teachers[index].department));
    printf("\nВведите научное звание преподавателя : ");
    scanf_s("%s", &teachers[index].scientific_title, sizeof(teachers[index].scientific_title));
	return teachers[index];
}

Teacher getTeacher(int id)
{
    return teachers[id];
}