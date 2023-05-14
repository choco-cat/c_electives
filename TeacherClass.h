#pragma once

struct Teacher
{
	//int id;
	char name[30] = " - ";
	char phone_number[15] = " - ";
	//char elective[15];
	char department[30] = " - ";
	char scientific_title[30] = " - ";
};

extern Teacher editTeacher();
extern Teacher getTeacher(int);