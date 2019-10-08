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
		<< "\t 1. Enter a name to add to the file.\n"
		<< "\t 2. Read a name from the file.\n"
		<< "\t 3. Enter a name to append to the file.\n"
		<< "\t 4. Enter a name to overwrite all entries in the file\n"
		<< "\t 5. print all\n"
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
		cout << "Enter the first name: ";
		cin >> fname;
		cout << "Enter the last name: ";
		cin >> lname;
		
		nPTR -> setFname(fname);
		nPTR -> setLname(lname);
		
		nPTR++;
		counter++;		
	}
	
	return counter;	
} 

void print(Names* nPTR, int counter)
{
	for(int u = 0; u < counter; u++)
	{
		cout << "Entry " << u + 1 << endl;
		nPTR -> print();
		nPTR++;		
	}
}

void defaultWrite(Names* nPTR, int counter)
{
	ofstream outData;
	outData.open("info.txt", ios::app);
	for (int x = 0; x < counter; x++)
	{
		outData << "\n" << nPTR -> getFname();
		outData << " ";
		outData << nPTR -> getLname() << "\n";
		nPTR++;
	}
	outData.close();
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
		cout<<test<<endl;
		array[x] = test;
		x++;
	}
	for(int y = 0; y < lines; y++)
	{
		cout << y + 1<< ": " << array[y];
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
				
				cout << "\n" << word << " TEST\n";
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
	Names n[100];
	Entries e[100];
	lines = numberOfLines();
	cout << "When this program first ran their was already " << lines << " entries." << endl;
	
	readLineByLine(e);
	
	counterM = splitLinesAdd(e, lines, n, counter1);
		
	do
	{
		choice = menu();

		switch (choice)
		{
			case 1:
			{
				counter1 = getMain(n, counterM);
				counterM = counterM + counter1;
				defaultWrite(n, counterM);
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
				print(n, counterM);
			}		
			

		}
		
	}while(choice != 10);
	
	
	return 0;
}
