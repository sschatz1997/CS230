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
	cout<<"\t\t===MAIN MENU==\n"
		<<"\t1. Enter student name.\n"
		<<"\t2. Add a class to a student.\n"
		<<"\t3. Remove a class from a student.\n"
		<<"\t4. List a studnets information.\n"
		<<"\t5. List all studnets.\n"
		<<"\t6.EXIT\n"
		<<"Enter your choice: ";
	cin>>choice;
	return choice;
}



int main(int argc, char** argv) {
	
	int choice;
	do
	{
		choice = menu();
		
		switch(choice)
		{
			case 1:
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
			break;
			
			case 4:
			{
				
			}
			break;
			
			case 5:
			{
				
			}
			break;
			
			case 6:
			{
				cout<<"==EXITING=="<<endl;
			}
			break;
		}
	}
	while(choice != 6);
	
	return 0;
}
