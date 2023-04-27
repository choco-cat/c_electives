#pragma once

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <windows.h>
#include <stdlib.h>


struct Student
{
	int id;
	int age;
	int group_number;
	float average_mark;
	int electives[5] = { 0,0,0,0 };
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

extern int firstMenu();
extern int secondMenuOfAdmin();
extern int secondMenuOfUser();
extern int loginAdmin();
extern int loginUser();
extern int interfaceOfAdmin();
extern int addStudent();
extern int printStudent();
extern int tableStudent();
extern int editStudent();
extern char menuEditStudent();
extern char menuEditStudentFields();
extern void insertStudentData();
extern void insertStudentDataField(char symbol);
extern void insertStudentDataName();
extern void insertStudentDataGroup();
extern void insertStudentDataAverage();
extern void insertStudentDataElective_0();
extern void insertStudentDataElective_1();
extern void insertStudentDataElective_2();
extern void insertStudentDataElective_3();
extern void insertStudentDataElective_4();