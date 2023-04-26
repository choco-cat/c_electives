#pragma once

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

extern int firstMenu();
extern int secondMenuOfAdmin();
extern int secondMenuOfUser();
extern int loginAdmin();
extern int loginUser();
extern int interfaceOfAdmin();
extern int AddStudent();
extern int PrintStudent();
extern void TableStudent();

struct Student
{
	int id;
	int age;
	int group_number;
	float average_mark;
	int electives[5] = {0,0,0,0};
	char name[30];
	char password[10];
	char sex[10];
	char phone_number[30];
	char faculty[30];
};

struct Teacher
{
	//int id;
	char name[30] = "Не известен";
	char password[10];
	char sex[10];
	char phone_number[15];
	//char elective[15];
	char department[10];
	char scientific_title[10];
};

struct Elective
{
	int id;
	int teacher_id;
	char duration[10];
	char location[10];
	char start_time[10];

};

struct Student_Elective
{
	int id;
	int student_id;
	int elective_id;
};
