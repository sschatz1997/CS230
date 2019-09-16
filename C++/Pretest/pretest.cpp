#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include "BallInfo.h"
using namespace std;
using std::string;

int menu()
{
	int choice;
	cout <<"\t\tMenu\n"
		<<"\t1. Add new ball\n"
		<<"\t2. View all entries\n"
		<<"\t3. List all balls with diameters above 10mm\n"
		<<"\t4. List all balls with less or equal to 10mm\n"
		<<"\t5. Show all smooth ball entries \n"
		<<"\t6. Show all rough ball entries\n"
		<<"\t7. Find a ball based on its ID\n"
		<<"\t8. How many balls of a specific color are in the database?\n"
		<<"\t10. exit\n";
	cin >> choice;
	return choice;
}

void writeToFile(double mm, string id, string col, string tx)
{
	//http://www.cplusplus.com/doc/tutorial/files/
	/*
	file output guide
	ball_mm
	ball_id
	ball_color
	ball_texture
	*/
	ofstream stringsFile;
	stringsFile.open("strings.txt", std::ios_base::app);
	//opens in appened mode
	if (stringsFile.is_open())
	{
	//	theFile << mm << "\n";
		stringsFile << id << "\n";
		stringsFile << col << "\n";
		stringsFile	<< tx << "\n";
	}
	stringsFile.close();
	//sencond file because of double
	ofstream doubleFile;
	doubleFile.open("double.txt", std::ios_base::app);
	if (doubleFile.is_open())
	{
		doubleFile << id << "\n";
	}
	doubleFile.close();
//	else cout<< "ERROR: file i/o";
	
}

int numberOfLines()
{
	int lines = 0;
	string line;
	ifstream theFile("strings.txt");
	while (getline(theFile, line))
	{
		++lines;
	}
	return lines;
}
void readFromFile(BallInfo* blPTR, int count)
{
	//the ball point will move within the loop but the count will just add the number of lines.
	//http://www.cplusplus.com/forum/beginner/8388/
	//need to make two files one for string then the second for double
	
	string STRING, main[50], temp[50], line, t, tm, pusher[50];
	string tID, tColor, tText;
	double mm[50], tMM;
	short loop=0;
	int lines, x, i, q;
	string l;
	lines = numberOfLines();
	int math = count * 4;
	x = 0;
	i = 0;
	q = 0;
	ifstream stringsFile("strings.txt");
	
	if (stringsFile.is_open())
	{
		while(!stringsFile.eof())
		{
			getline(stringsFile, line);
			main[x++] = line;
		}
		stringsFile.close();

	}
	
	ifstream doubleFile("double.txt");
	if (doubleFile.is_open())
	{
		while(!doubleFile.eof())
		{
			getline(doubleFile, t);
			temp[i++] = t;
		}
	}
	doubleFile.close();
	do
	{
		for (int u = 0; u == count * 4; u++)
		{
			cout << "u: " << u <<endl;
			if(u = 0)
			{
				tm =  temp[u-1];
				tMM = stod (tm);
				cout << "mm: " << mm[u] <<endl;
				blPTR -> setDiameter(stod(pusher[u]));
			}
			if (u = 1)
			{
				tID = main[u-1];
				cout << "id: " << tID<<endl;
				blPTR -> setID(tID);
			}
			if (u = 2)
			{
				tColor = main[u-1];
				cout << "color: " << tColor<<endl;
				blPTR -> setColor(tColor);
			}
			if (u = 3)
			{
				tText = main[u-1];
				cout << "texture: " << tText <<endl;
				blPTR -> setTexture(tText);
			}

			blPTR++;
			q++;
		}
	}while(q < math);

}

int addEntry(BallInfo* blPTR, int count)
{
	string ID, color, texture;
	double diameter;
	int num = 0;
	cout << "\tHow many do you want to enter? ";
	cin >> num;
	for (int x = 0; x < count; x++)
		blPTR++;
		
	for (int w = 0; w < num; w++)
	{
		cout << "What is the ball Diameter in MM? ";
		cin >> diameter;
		cout << "What is the ID of the ball? ";
		cin >> ID;
		cout << "What is the color of the ball? ";
		cin >> color;
		cout << "Which texture is the ball? ";
		cin >> texture;
		cout << "\n";
		
		blPTR -> setDiameter(diameter);
		blPTR -> setID(ID);
		blPTR -> setColor(color);
		blPTR -> setTexture(texture);
		
		writeToFile(diameter, ID, color, texture);
		
		blPTR++;
		count++;
	}
	return count;
}

void textureSearchSmooth(BallInfo* blPTR, int count)
{
	string texture, smooth, value;
	smooth = "smooth";
	for (int x = 0; x < count; x++)
	{
		value = blPTR -> getTexture();
		if (smooth == value)
		{
			cout << "Entries where the ball is smooth are the following: "
				<< "\t Ball Diameter: "<< blPTR -> getDiameter() <<"\n"
				<< "\t Ball ID: "<< blPTR -> getID() << "\n"
				<< "\t Ball Color: "<< blPTR -> getColor() << "\n"
				<< "\t Ball Texture: "<< blPTR -> getTexture() <<"\n\n" <<endl;
		}
		blPTR++;
	}
}

void textureSearchRough(BallInfo* blPTR, int count)
{
	string texture, rough, value;
	rough = "rough";
	for (int x = 0; x < count; x++)
	{
		value = blPTR -> getTexture();
		if (rough == value)
		{
			cout << "Entries where the ball is rough are the following: \n\n"
				<< "\t Ball Diameter: "<< blPTR -> getDiameter() <<"\n"
				<< "\t Ball ID: "<< blPTR -> getID() << "\n"
				<< "\t Ball Color: "<< blPTR -> getColor() << "\n"
				<< "\t Ball Texture: "<< blPTR -> getTexture() <<"\n\n" <<endl;
		}
		blPTR++;
	}
}


void searchGreaterTen(BallInfo* blPTR, int count)
{
	double value;
	double ten = 10;
	for (int x = 0; x < count; x++)
	{
		value = blPTR -> getDiameter();
		if (value > ten && value != ten)
		{
			cout << "Entries where the ball is greater then 10mm are the following: \n\n"
				<< "\t Ball Diameter: "<< blPTR -> getDiameter() <<"\n"
				<< "\t Ball ID: "<< blPTR -> getID() << "\n"
				<< "\t Ball Color: "<< blPTR -> getColor() << "\n"
				<< "\t Ball Texture: "<< blPTR -> getTexture() <<"\n\n" <<endl;
		}
		blPTR++;
	}	
	
}

void searchLessTen(BallInfo* blPTR, int count)
{
	double value;
	double ten = 10.0;
	for (int x = 0; x < count; x++)
	{
		value = blPTR -> getDiameter();
		if (value <= ten)
		{
			cout << "Entries where the ball is less then or equal to 10mm are the following: "
				<< "\t Ball Diameter: "<< blPTR -> getDiameter() <<"\n"
				<< "\t Ball ID: "<< blPTR -> getID() << "\n"
				<< "\t Ball Color: "<< blPTR -> getColor() << "\n"
				<< "\t Ball Texture: "<< blPTR -> getTexture() <<"\n\n" <<endl;
		}
		blPTR++;
	}	
	
}

void idSearch(BallInfo* blPTR, int count, string search)
{
	string tempID;
	for (int x = 0; x < count; x++)
	{
		tempID = blPTR -> getID();
		if (search == tempID)
		{
			cout << "Entery where the ID is "<< tempID << " \n\n" 
				<< "\t Ball Diameter: "<< blPTR -> getDiameter() <<"\n"
				<< "\t Ball ID: "<< blPTR -> getID() << "\n"
				<< "\t Ball Color: "<< blPTR -> getColor() << "\n"
				<< "\t Ball Texture: "<< blPTR -> getTexture() <<"\n\n" <<endl;
		}
		blPTR++;
	}	
	
}

void cls()
{
	system("CLS");
}


void printALL(BallInfo* blPTR, int count)
{
	for (int x = 0; x < count; x++)
	{
		blPTR -> print();
		blPTR++;
	}
}

void findColors(BallInfo* blPTR, int count)
{
	string color, compare;
	int number = 0;
	cout << "Enter the color that you want to find the number of: ";
	cin >> color;
	for (int x = 0; x < count; x++)
	{
		compare = blPTR -> getColor();
		if (compare == color)
		{
			number++;
		}
	}
	cout << color << " had " << number << " matches."<<endl;
}

int main(int argc, char** argv)
{
	BallInfo bl[100];
	string search, text, col, id;
	int menuChoice, lines;
	double mm;
	int counter = 0;
	lines = numberOfLines();
//	cout << "Number of lines: " << lines << "\n";
	
//	readFromFile(bl, counter);
	
	do
	{
		menuChoice = menu();
		switch (menuChoice)
		{
			case 1:
			{
				counter = addEntry(bl, counter);
				cls();
			}
			break;

			case 2:
			{
				//readFromFile(bl, counter);
				printALL(bl, counter);
			}
			break;
			
			case 3:
			{
				searchGreaterTen(bl, counter);

			}
			break;
			
			case 4:
			{
				searchLessTen(bl, counter);

			}
			break;
			
			case 5:
			{
				textureSearchSmooth(bl, counter);
			}
			break;

			case 6:
			{
				textureSearchRough(bl, counter);

			}
			break;
			
			case 7:
			{
				cout << "what ID entry do you want to find? ";
				cin >> search;
				idSearch(bl, counter, search);
			}
			break;
			
			case 8:
			{
				findColors(bl, counter);
			}
			break;
			
			case 10:{cout<<"bye\n";}break;

		//default: cout<<"invalid choice"<<endl;
		}


	}while (menuChoice != 10);

	return 0;
}
