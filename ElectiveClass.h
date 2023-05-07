#pragma once

struct Elective
{
	int id;
	int teacher_id;
	char duration[10];
	char location[10];
	char start_time[10];

};
extern void topOfElective();
extern int file_open_e(char* NameOfFile);