#pragma once

struct Student
{
	int id;
	int age;
	int group_number;
	float average_mark;
	int electives[5] = { 0,0,0,0,0 };
	char name[30];
	char password[10];
	char sex[10];
	char phone_number[30];
	char faculty[30];
};

struct Student_Elective
{
	int id;
	int student_id;
	int elective_id;
};

extern int addStudent();
extern int printStudent();
extern int tableStudents();
extern void TableStudentOfElective(FILE*, char*);
extern int sortStudents();
extern int editStudent();
extern char menuEditStudent();
extern char menuEditStudentFields();
extern void insertStudentData();
extern void insertStudentDataField(char symbol);
extern void insertStudentDataName();
extern void insertStudentDataGroup();
extern void insertStudentDataAverage();
extern void insertStudentDataElective(int indexElective);
extern void printStudentTableHeader();
extern void printStudentTableRow(int number, Student student);
extern int pushStudentToElective(Student, int);