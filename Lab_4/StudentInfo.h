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
		void setID(int);
//		void setIDList(int);
		void setName(string, string);
//		void setNameList(string, string);
		void setClasses(int, int, int, int, int, int);
//		void setCalssesList(int, int, int, int, int, int);
		void setgpa(int);
//		void setgpaList(int);
		
		
		int getID() const;
//		int getIDList() const;
		string getFullName() const;
//		string getFullNameList() const;
		int getClasses() const;
//		int getClassesList() const;
		int getGPA() const;
//		int getGPAList() const;
		
	private:
		int id; //ID
		string fname;//FName
		string lname;//LName
		int gc1;//GC1
		int gc2;//GC2
		int gc3;//GC3
		int gc4;//GC4
		int gc5;//GC5
		int gc6;//GC6
		int gpa;//GPA
	
};


#endif
