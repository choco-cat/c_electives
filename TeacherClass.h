#pragma once

struct Teacher
{
	//int id;
	char name[30] = "�� ��������";
	char phone_number[15];
	//char elective[15];
	char department[10];
	char scientific_title[10];
};

extern int addTeacher();