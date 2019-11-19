//main.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <list> 
#include <iterator> 
#include <fstream>
#include "StudentInfo.h"
#include "Student_list.h"
#include "Classes.h"
#include "Classes_List.h"

using namespace std;

int menu()
{
	/*
	student name, id, grade class 1(gc1), grade class 2(gc2), grade class 3(gc3), gpa (calculate ((gc1+gc2+gc3)/3=gpa))
	add a class max of 6
	remove a class min of 3
	remove a student
	list a student 
	list all students
	*/
	int choice;
	cout << "\t\t===MAIN MENU==\n"
		<< "\t1. Enter student full Info.\n"
		<< "\t2. Add 2 classed to a student.\n"
		<< "\t3. List a students information(normallly).\n"
		<< "\t4. List a students information(recursively).\n"
		<< "\t5.EXIT\n"
		<< "Enter your choice: ";
	cin >> choice;
	return choice;
}

void addStu(Student_List* stuL)
{
	string fname, lname, gpa;
	cout << "Enter the Students First Name: "<<endl;
	cin >> fname;
	cout << "Enter the Students Last Name: "<<endl;
	cin >> lname;
	cout << "Enter the Students GPA: "<<endl;
	cin >> gpa;
	StudentInfo STU;
	STU.setInfo(fname, lname, gpa);
	stuL -> addStudent(STU);
}

void addClasses(Class_List* cl)
{
	string class1, class2;
	cout << "Enter the first class: " <<endl;
	cin >> class1;
	cout << "Enter the second class: " <<endl;
	cin >> class2;
	Classes CLS;
	CLS.setClasses(class1, class2);
	cl -> addClass(CLS);
}

void printNormal(Student_List* stuL, Class_List* cl)
{
	cout << "Printing normally Student: "<<endl;
	stuL -> normalListPrint();
	cout << "Classes: "<<endl;
	cl -> normalPrintC();
}

void printRecursivly(Student_List* stuL, Class_List* cl)
{
	cout << "Printing with recursion Student: "<<endl;
	stuL -> rePrint();
	cout << "Classes: "<<endl;
	cl -> rePrintClasses();
}

int main(int argc, char** argv) {
	
	int choice;
	Student_List stuList;
	Class_List clList;
	
	do
	{
		choice = menu();
		
		switch(choice)
		{
			case 1:
			{
				addStu(&stuList);
			}
			break;
			
			case 2:
			{
				addClasses(&clList);
			}
			break;
			
			case 3:
			{
				printNormal(&stuList, &clList);
			}
			break;
			
			case 4:
			{
				printRecursivly(&stuList, &clList);
			}
			break;

			case 5:
			{
				cout<<"==EXITING=="<<endl;
			}
			break;			
		}
	}
	while(choice != 5);
	
	return 0;
}
