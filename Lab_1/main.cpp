//main.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
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

//string searchStudent()
string returnCourse(Classes* clsPTR, int cc, string id)
{
	for(int x = 0; x < cc; x++)
	{
		if(id == clsPTR -> getClass_ID())
		{
			return clsPTR -> getCourse();
		}
		else
			clsPTR++;
	}
		
}

string returnNOC(Classes* clsPTR, int cc, string id)
{
	for(int x = 0; x < cc; x++)
	{
		if(id == clsPTR -> getClass_ID())
		{
			return clsPTR -> getNumOfCredits();
		}
		else
			clsPTR++;
	}
		
}

void assignClasses(Info* infoPTR, Classes* clsPTR, int count, int cc)
{
	int v, choice, c2, loops, check, check2;
	string course, noc;
	loops = count * 4;
	string classID, studentID;
	//insert a 4x loop here, get the class number 
	cout << "\t\tThis will loop Dependant how many students you have entered"
		<< "\t\t thus assigning 4 classes to each student\n";

	//	cout << "Chose the class number to assign to the student:"<<endl;
	//	cin >> classID;
	
	//force the user to move down the list of entered students
//	do
//	{
	for (int x = 0; x < 1; x++)
	{
		if (x == 0)
		{
			cout <<"Student " << infoPTR -> getStu_ID() << " : " << infoPTR -> getStu_ID() << "\n";	
			cout << "Enter the first class: ";
			cin >> classID;
			course = returnCourse(clsPTR, cc, classID);
			cout << "course: " << course << endl;
			noc = returnNOC(clsPTR, cc, classID);
			cout << "NOC: " << noc << endl;
			infoPTR -> setClass_ID(classID);
			infoPTR -> setClass_N(course);
			infoPTR -> setNumOfCredits(noc);
		//cout << "course test: " << course << endl;
		

		}

		if (x == 1)
		{
			cout << "Student " << infoPTR -> getStu_ID() << " : " << infoPTR -> getStu_ID() << "\n";
			cout << "Enter the first class: ";
			cin >> classID;
			course = returnCourse(clsPTR, cc, classID);
			noc = returnNOC(clsPTR, cc, classID);
			infoPTR -> setClass_ID2(classID);
			infoPTR -> setClass_N2(course);
			infoPTR -> setNumOfCredits(noc);
		}

		if (x == 2)
		{


		}

		if (x == 3)
		{

		}

		clsPTR++;
		infoPTR++;
		/*	switch(x)
			{
				case 0:
				{
					cout <<"Student1: " << infoPTR -> getStu_ID() << "\n\n";	
					cout << "Enter the first class: ";
					cin >> classID;
					course = returnCourse(clsPTR, cc, classID);
					noc = returnNOC(clsPTR, cc, classID);
					infoPTR -> setClass_ID(classID);
					infoPTR -> setClass_N(course);
					infoPTR -> setNumOfCredits(noc);
					//cout << "course test: " << course << endl;
					
					clsPTR++;
					infoPTR++;

										
				}
				break;
				
/*				case 1:
				{
					
				}
				break;
				
				case 2:
				{
					
				}
				break;
				
				case 3:
				{
					
				}
				break;*/
	}
		
		//result found
		
/*		for (int x = 0; x < cc; x++)
		{
			
			switch(x)
			{
				case 0:
				{
					if(classID == clsPTR -> getClass_ID())
					{
						cout << "Enter the student ID you want to assign this class to: ";
						cin >> studentID;
						for(int c = 0; c < count; c++)
						{
							infoPTR -> searchStudent(studentID);
							infoPTR++;
						}
					}
					else
						clsPTR++;
				}
				break;
				
				case 1:
				{
					if(classID == clsPTR -> getClass_ID())
					{
						cout << "Enter the student ID you want to assign this class to: ";
						cin >> studentID;
						for(int c = 0; c < count; c++)
						{
							infoPTR -> searchStudent(studentID);
							infoPTR++;
						}
					}
					else
						clsPTR++;	
				}
				break;
				
				case 2:
				{
					if(classID == clsPTR -> getClass_ID())
					{
						cout << "Enter the student ID you want to assign this class to: ";
						cin >> studentID;
						for(int c = 0; c < count; c++)
						{
							infoPTR -> searchStudent(studentID);
							infoPTR++;
						}
					}
					else
						clsPTR++;				
				}
				break;
				
				case 3:
				{
					if(classID == clsPTR -> getClass_ID())
					{
						cout << "Enter the student ID you want to assign this class to: ";
						cin >> studentID;
						for(int c = 0; c < count; c++)
						{
							infoPTR -> searchStudent(studentID);
							infoPTR++;
						}
					}
					else
						clsPTR++;				
				}
				break;
			}
			
			v++;*/
		
//		v++;
//		clsPTR++;
//		infoPTR++;
//	}while(v != 1);
	//}while(v < loops);
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
				nos = nos + 1;
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
