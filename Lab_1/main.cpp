//main.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.H>
#include <fstream>
#include "Info.h"
#include "Classes.h"

using namespace std;

int menu()
{
	int x = 0;
	cout<< "\t\t ==MAIN MENU==\n"
		<< "\t 1. Enter students into the DB.\n"
		<< "\t 2. Enter courses into the DB.\n"
		<< "\t 3. Assign 4 existing courses for an exitsting student.\n"
		<< "\t 4. Display a report of students (CURRENT TESTING)\n"
		<< "\t 5. Display a report of classes (CURRENT TESTING)\n"
		<< "\t\t 10. EXIT\n"<<endl; 
	cin >> x;
	return x;
}

int studentEntry(Info* infoPTR, int count, int num)
{
	string sid, fn, ln;
	for (int x = 0; x < num; x++)
	{
		cout << "\t\t Enter the following information for student " << x + 1 << ":\n";
		cout << "Student ID: ";
		cin >> sid;
		cout << "First Name: ";
		cin >> fn;
		cout << "Last Name: ";
		cin >> ln;
		
		infoPTR -> setStu_ID(sid);
		infoPTR -> setF_name(fn);
		infoPTR -> setL_name(ln);
		
		infoPTR++;
		count++;	
	}
	return count;
}

int classAssign(Classes* clsPTR, int num, int count)
{
	string courseN, cid, noc;
	//cid = course id
	//noc = number of credits
	
	for (int x = 0; x < num; x++)
	{
		cout << "\t\t Enter the following information for class " << x + 1 << ":\n";
		cout << "Course ID: ";
		cin >> cid;
		cout << "Course Name: ";
		cin >> courseN;
		cout << "Number of Credits: ";
		cin >> noc;
		
		clsPTR -> setClass_ID(cid);
		clsPTR -> setClass_N(courseN);
		clsPTR -> setNumOfCredits(noc);
		
		clsPTR++;
		count++;
	}
	return count;
}

void printALL(Info* infoPTR, int count, Classes* clsPTR, int cc)
{
	for (int x = 0; x < count; x++)
	{
		infoPTR -> print();
		infoPTR++;
	}
	
	for (int y = 0; y < cc; y++)
	{
		clsPTR -> print();
		clsPTR++;	
	}
		
} 

void printStu(Info* infoPTR, int count)
{
	for (int x = 0; x < count; x++)
	{
		infoPTR -> print();
		infoPTR++;		
	}
}

void printCls(Classes* clsPTR, int cc)
{
	for (int y = 0; y < cc; y++)
	{
		clsPTR -> print();
		clsPTR++;	
	}
}

void assignClasses(Info* infoPTR, Classes* clsPTR, int count, int cc)
{
	int choice, c2;
	string classID, studentID;
	cout << "Chose the class number to assign to the student:"<<endl;
	cin >> classID;
	int rf = 0;
	//result found
//	cout << "Enter a class ID to see all of the details: ";

		
	for (int x = 0; x < cc; x++)
	{
		if (classID == clsPTR -> getClass_ID())
		{
			clsPTR -> print();
			rf = 1;		

			cout << "enter the ID student you want to add to this class? ";
			cin >> studentID;
			for (int t = 0; t < count; t++)
			{
				if (studentID == infoPTR -> getStu_ID())
				{
					cout << "This class will be added to student " << studentID << ".\n";
					clsPTR -> print();
					infoPTR -> setClass_ID(clsPTR -> getClass_ID());
					infoPTR -> setClass_N(clsPTR -> getCourse());
					infoPTR -> setNumOfCredits(clsPTR -> getNumOfCredits());
				}
			}
		
		}
		else
		{
			clsPTR++;
			rf = 0;
		}
	}
	if (rf == 0)
	{
		cout << "\tNO CLASS WAS FOUND\n";
	}
}

int main(int arg, char** argv)
{
	Info info[100];
	Classes cls[100];
	int choice, counter, nos, noc, CC;
	//nos = number of students
	//noc = number of classes
	//CC = class counter this counts the number of classes that have been entered
	
	do
	{
		choice = menu();
		switch (choice)
		{
			case 1:
			{
				cout << "How many students are you entering above the 4 by defualt? ";
				cin >> nos;
				nos = nos + 4;
				counter = studentEntry(info, counter, nos);
			}
			break;
			
			case 2:
			{
				cout << "How many classes are you entering above the 10 by defualt? ";
				cin >> noc;
				noc = noc + 1;//change this to 10 when going to final version
				CC = classAssign(cls, noc, CC);
			}
			break;
			
			case 3:
			{
				//arrayTest(cls, CC);
				assignClasses(info, cls, counter, CC);
			}
			break;
			
			case 4:
			{
				//printALL(info, counter, cls, CC);
				printStu(info, counter);
			}
			break;
			
			case 5:
			{
					printCls(cls, CC);
			}		
			
			//case 10:{cout<<"EXITING...\n";}break;
		}
		
	}while(choice != 10);





	return 0;
}
