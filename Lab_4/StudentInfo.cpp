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

using namespace std;

StudentInfo::StudentInfo()
{
	string FName = "";
	string LName = "";
	string GPA = "";
}

void StudentInfo::setInfo(string FName, string LName, string GPA) 
{
	fname = FName;
	lname = LName;
	gpa = GPA;
}

string StudentInfo::getFullInfo() const 
{
	return "First Name: " + fname + "\n" +
			"Last Name: " + lname + "\n" +
			"GPA: " + gpa + "\n"; 

}
