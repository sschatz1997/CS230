#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <bits/stdc++.h> 
#include <fstream>
#include "names.h"
#include "Files.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menu()
{
	int choice;
	cout<< "\t\t ==MAIN MENU==\n"
		<< "\t 1. Enter a name to add to the file(append).\n"
		<< "\t 2. Read a name from the file.\n"
		<< "\t 3. Enter a name to overwrite all entries in the file\n"
		<< "\t 4. print all\n"
		<< "\t\t 10. EXIT\n"<<endl; 
	cin >> choice;
	return choice;
}

int getMain(Names* nPTR, int counter)
{
	string fname, lname;
	int x;
	cout << "How many are you entering? ";
	cin >> x;
	for(int y = 0; x > y; y++)
	{
		cout <<"the counter is: " << counter << "\n\n";
		cout << "Enter the first name: ";
		cin >> fname;
		cout << "Enter the last name: ";
		cin >> lname;
		
		nPTR -> setFname(fname);
		nPTR -> setLname(lname);
		//http://www.cplusplus.com/reference/string/to_string/
		nPTR -> defaultWrite(to_string(counter+1),fname,lname);
		nPTR++;
		counter++;		
	}
	
	return counter;	
} 

int overwritePrevious(Names* nPTR, int counter)
{
	string fname, lname;
	cout <<"the counter is: " << counter << "\n\n";
	cout << "Enter the first name: ";
	cin >> fname;
	cout << "Enter the last name: ";
	cin >> lname;
	
	nPTR -> setFname(fname);
	nPTR -> setLname(lname);
	nPTR -> setKey(to_string(1));
	//this sets the new key to 0 and the
	nPTR -> overwriteFile(to_string(1),fname,lname);
	nPTR++;
	counter++;		
	
	return counter;
}

void searchName(Names* nPTR, int counter, string userInput)
{
	int x = 0;
	int checker = 1;
	
//	do
	for(x; x < counter; x++)
	{
		if(userInput == nPTR -> getFname())
		{
			cout<< "\t\tThis is the enties from that name: \n";
			cout << "First name: " << nPTR -> getFname() << endl;
			cout << "Last name: " << nPTR -> getLname() << "\n\n";
			checker = 0;
		//	x = counter;
		}
		else
		{
			checker = 1;
			//x++;
			
		}
		nPTR++;
	}
//	}while(x < counter or checker != 0);
	if(checker == 1)
	{
		cout <<"That entry does not exist!\n";
	}
}


int numberOfLines()
{
	int lines = 0;
	string line;
	ifstream theFile("info.txt");
	while(getline(theFile, line))
	{
		lines++;
	}
	return lines;
}

int print(Entries* ePTR)
{
	int lines;
	int x = 0;
	lines = numberOfLines();
	string array[lines];
	string test;
	ifstream theFile("info.txt");
	while(getline(theFile, test))
	{
	//	cout<<test<<endl;
		array[x] = test;
		x++;
	}
	for(int y = 0; y < lines; y++)
	{
		cout << y + 1<< ": " << array[y]<<"\n";
		ePTR -> setEntries(array[y]);
		ePTR++;
	}
}

int readLineByLine(Entries* ePTR)
{
	int lines;
	int x = 0;
	lines = numberOfLines();
	string array[lines];
	string test;
	ifstream theFile("info.txt");
	while(getline(theFile, test))
	{
	//	cout<<test<<endl;
		array[x] = test;
		x++;
	}
	for(int y = 0; y < lines; y++)
	{
	//	cout << y + 1<< ": " << array[y]<<"\n";
		ePTR -> setEntries(array[y]);
		ePTR++;
	}
	
}

int splitLinesAdd(Entries* ePTR, int lines, Names* nPTR, int counter)
{
	string temp;
	for(int x = 0; x < lines; x++){
		temp = ePTR -> getEntries();
		istringstream ss(temp);
		int c = 0;
		do {
			string word;

			ss >> word;
			if(word != "")
			{
				if(c == 0){
					nPTR -> setFname(word);

				}
				if(c == 1){
					nPTR -> setLname(word);
					
				}
				if (c == 2){
					nPTR -> setKey(word);
				}
				//cout << "\n" << word << " TEST\n";
			}
			c++;
			

		}while(ss);
		nPTR++;
		ePTR++;
		counter++;
	}
	return counter;
}

int main(int argc, char** argv) {
	
	int choice, counter1, counterM, lines;
	string nameSearch;
	Names n[100];
	Entries e[100];
	lines = numberOfLines();
	cout << "\t\t====================\n";
	cout << "\tTheir are curently " << lines << " entries." << endl;
	cout << "\t\t====================\n";
	
	readLineByLine(e);
	
	counterM = splitLinesAdd(e, lines, n, counter1);
		
	do
	{
		choice = menu();

		switch (choice)
		{
			case 1:
			{
			//	cout << "\n\ncounterM " << counterM << endl;
				counterM = getMain(n, counterM);
		//		cout << "\n\ncounter1 " << counter1 << endl;	
			//	counterM =+ counter1;
			//	cout << "\n\ncounter main: " << counterM << endl;	
				//defaultWrite(n, counterM);
			}
			break;
			
			case 2:
			{
				cout<<"\t Enter the name you want to search: ";	
				cin >> nameSearch;
				searchName(n, counterM, nameSearch);
			}
			break;
			
			case 3:
			{
				counterM = 0;
				counterM = overwritePrevious(n, counterM);
				
			}
			break;
			
			case 4:
			{
				print(e);
				//readLineByLine(e);
			}		
			break;

		}
		
	}while(choice != 10);
	
	
	return 0;
}
