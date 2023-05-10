#pragma once



#include<io.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include "Constants.h"
#include "StudentClass.h"
#include "TeacherClass.h"
#include "ElectiveClass.h"

extern int list();
extern int lookElective();
extern int firstMenu();
extern int secondMenuOfAdmin();
extern int secondMenuOfUser();
extern int loginAdmin();
extern int loginUser();
extern int interfaceOfAdmin();
extern int interfaceOfUser();
extern int AddStudent();
extern int contains(int*, int, int);
extern int cleaner();

