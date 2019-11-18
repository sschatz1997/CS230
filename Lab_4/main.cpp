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
		<< "\t2. Add a class to a student.\n"
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

void printNormal(Student_List* stuL)
{
	cout << "Printing normally: "<<endl;
	stuL -> normalListPrint();
}

void printRecursivly(Student_List* stuL)
{
	cout << "Printing with recursion: "<<endl;
	stuL -> rePrint();
}

int main(int argc, char** argv) {
	
	int choice;
	Student_List stuList;
	
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
				
			}
			break;
			
			case 3:
			{
				printNormal(&stuList);
			}
			break;
			
			case 4:
			{
				printRecursivly(&stuList);
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
