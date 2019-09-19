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
using std::string;

int menu()
{
	int x = 0;
	cout<< "\t\t ==MAIN MENU==\n"
		<< "\t 1. Enter students into the DB.\n"
		<< "\t 2. Enter courses into the DB.\n"
		<< "\t 3. Assign four existing courses for an exitsting student.\n"
		<< "\t 4. Display a report of students.\n"
		<< "\t 5. Display a report of classes.\n"
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

string returnCourse(Classes* clsPTR, int cc, string id)
{
	string returner;
	for(int x = 0; x < cc; x++)
	{
		if(id == clsPTR -> getClass_ID())
		{
			returner = clsPTR -> getCourse();
			return returner;
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


void writeInfo(Info* infoPTR, int count)
{
	ofstream outData;
	outData.open("info.txt", ios::app);
	for (int x = 0; x < count; x++)
	{
		outData << infoPTR -> getStu_ID() << endl;
		outData << infoPTR -> getF_name() << endl;
		outData << infoPTR -> getL_name() << endl;
		outData << infoPTR -> getClass_ID() << endl;
		outData << infoPTR -> getCourse() << endl;
		outData << infoPTR -> getNumOfCredits() << endl;
		outData << infoPTR -> getClass_ID2() << endl;
		outData << infoPTR -> getCourse2() << endl;
		outData << infoPTR -> getNumOfCredits2() << endl;
		outData << infoPTR -> getClass_ID3() << endl;
		outData << infoPTR -> getCourse3() << endl;
		outData << infoPTR -> getNumOfCredits3() << endl;
		outData << infoPTR -> getClass_ID4() << endl;
		outData << infoPTR -> getCourse4() << endl;
		outData << infoPTR -> getNumOfCredits4() << endl;

		infoPTR++;
	}
	outData.close();
}

int numberOfLines()
{
	int lines = 0;
	string line;
	ifstream theFile("strings.txt");
	while (getline(theFile, line))
	{
		lines++;
	}
	return lines;
}

int readFiles(Info* infoPTR)
{
	string line;
	int lines;
	double sets;
	lines = numberOfLines();
	sets = lines / 15;
	string sid, firstN, lastN, clasN, clasN2, clasN3, clasN4, cid;
	string cid2, cid3, cid4, nof, nof2, nof3, nof4;
	int count;
	ifstream inData ("info.txt");
	if (inData.is_open() /*&& lines <= 15*/)
	{
		while(!inData.eof())
		{
				inData >>sid
					>>firstN
					>>lastN
					>>clasN
					>>cid
					>>nof
					>>clasN2
					>>cid2
					>>nof2
					>>clasN3
					>>cid3
					>>nof3
					>>clasN4
					>>cid4
					>>nof4;
				infoPTR -> setStu_ID(sid);
				infoPTR -> setF_name(firstN);
				infoPTR -> setL_name(lastN);
				infoPTR -> setClass_ID(cid);//1
				infoPTR -> setClass_N(clasN);
				infoPTR -> setNumOfCredits(nof);
				infoPTR -> setClass_ID2(cid2);//2
				infoPTR -> setClass_N2(clasN2);
				infoPTR -> setNumOfCredits2(nof2);
				infoPTR -> setClass_ID3(cid3);//3
				infoPTR -> setClass_N3(clasN3);
				infoPTR -> setNumOfCredits3(nof3);
				infoPTR -> setClass_ID4(cid4);//4
				infoPTR -> setClass_N4(clasN4);
				infoPTR -> setNumOfCredits4(nof4);
				count++;
		}
	}
	return count;
}

void assignClasses(Info* infoPTR, Classes* clsPTR, int count, int cc)
{
	int v, choice, c2, loops, check, check2;
	string course, noc;
	loops = count * 4;
	string classID, studentID;
	cout << "\t\tThis will loop Dependant how many students you have entered"
		<< "\t\t thus assigning 4 classes to each student\n";
	
	//force the user to move down the list of entered students

	for(int x = 0; x < 4; x++)
	{
		cout <<"Student " << infoPTR -> getStu_ID() << " : " << infoPTR -> getStu_ID() << "\n";	
		cout << "Enter the first class: ";
		cin >> classID;
		course = returnCourse(clsPTR, cc, classID);
		noc = returnNOC(clsPTR, cc, classID);
		infoPTR -> setClass_ID(classID);
		infoPTR -> setClass_N(course);
		infoPTR -> setNumOfCredits(noc);
		cout << "Student " << infoPTR -> getStu_ID() << " : " << infoPTR -> getStu_ID() << "\n";
		cout << "Enter the second class: ";
		cin >> classID;
		course = returnCourse(clsPTR, cc, classID);
		noc = returnNOC(clsPTR, cc, classID);
		infoPTR -> setClass_ID2(classID);
		infoPTR -> setClass_N2(course);
		infoPTR -> setNumOfCredits2(noc);
		cout << "Student " << infoPTR -> getStu_ID() << " : " << infoPTR -> getStu_ID() << "\n";
		cout << "Enter the third class: ";
		cin >> classID;
		course = returnCourse(clsPTR, cc, classID);
		noc = returnNOC(clsPTR, cc, classID);
		infoPTR -> setClass_ID3(classID);
		infoPTR -> setClass_N3(course);
		infoPTR -> setNumOfCredits3(noc);
		cout << "Student " << infoPTR -> getStu_ID() << " : " << infoPTR -> getStu_ID() << "\n";
		cout << "Enter the fourth class: ";
		cin >> classID;
		course = returnCourse(clsPTR, cc, classID);
		noc = returnNOC(clsPTR, cc, classID);
		infoPTR -> setClass_ID4(classID);
		infoPTR -> setClass_N4(course);
		infoPTR -> setNumOfCredits4(noc);
		clsPTR++;
		infoPTR++;
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
	//	counter = readFiles(info);
		switch (choice)
		{
			case 1:
			{
				cout << "How many students are you entering above the 4 by defualt? ";
				cin >> nos;
				nos = nos + 4;// @final change this to 4 when going to final version
				counter = studentEntry(info, counter, nos);
			}
			break;
			
			case 2:
			{
				cout << "How many classes are you entering above the 10 by defualt? ";
				cin >> noc;
				noc = noc + 10;// @final change this to 10 when going to final version
				CC = classAssign(cls, noc, CC);
			}
			break;
			
			case 3:
			{
				//arrayTest(cls, CC);
				if(info[0].getF_name() != "" && cls[0].getClass_ID() != "")
				{
					assignClasses(info, cls, counter, CC);
					writeInfo(info, counter);
				}
				else
					cout << "not enough entries to assign to eachother." << endl;
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
