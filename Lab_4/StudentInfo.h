//StudentInfo.h
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <list> 
#include <iterator> 
#include <fstream>

using namespace std;

#ifndef STUDENTINFO_H
#define STUDENTINFO_H

class StudentInfo
{
	public:
		StudentInfo(); //default constructor
		//StudentInfo(int, string, string, int, int, int, int, int, int);

		void setInfo(string, string, string);
		string getFullInfo() const;
		
	private:
		string fname;//FName
		string lname;//LName
		string gpa;//GPA
	
};


#endif
