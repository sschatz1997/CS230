//StudentInfo.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <list> 
#include <iterator> 
#include <fstream>
#include "StudentInfo.h"

StudentInfo::StudentInfo()
{
	int ID = 0;
	string FName = "";
	string LName = "";
	int GC1 = 0;
	int GC2 = 0;
	int GC3 = 0;
	int GC4 = 0;
	int GC5 = 0;
	int GC6 = 0;
	int GPA = 0;
}

void StudentInfo::setID(int ID) { ID = id; }
void StudentInfo::setName(string FName, string LName) 
{
	fname = FName;
	lname = LName;
}
void StudentInfo::setClasses(int gc1, int gc2, int gc3, int gc4, int gc5, int gc6)
{
	int GC1 = gc1;
	int GC2 = gc2;
	int GC3 = gc3;
	int GC4 = gc4;
	int GC5 = gc5;
	int GC6 = gc6;
}
void StudentInfo::setgpa(int GPA) { gpa = GPA; }

int StudentInfo::getID() const { return id; }
string StudentInfo::getFullName() const { return fname, fname; }
int StudentInfo::getClasses() const { return gc1, gc2, gc3, gc4, gc5, gc6; }
int StudentInfo::getGPA() const { return gpa; }
