#pragma once

struct Elective
{
	int id;
	int teacher_id;
	char duration[30] = " - ";
	char location[10] = " - ";
	char start_time[20] = " - ";

};
extern void topOfElective();
extern int pushStudentToElective(int, int);
extern int deleteStudentFromElective(int, int);
extern int file_opens(char*, int,int);
extern void editInfoOfElective();
extern void infoOfElective();
extern void printInfoOfElective(int);
