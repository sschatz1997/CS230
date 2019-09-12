#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdio>	
#include <fstream>
#include "BallInfo.h"
using namespace std;
using std::string;
//main program
//diameter == ball_mm
//IDnumber == ball_ID
//ballColor == ball_color
//ballTexture == ball_texture

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
		<<"\b\t8. file I/O testing\n"
		<<"\t10. exit\n";
	cin >> choice;
	return choice;
}

void writeToFile(double mm, string id, string col, string tx)
{
	//http://www.cplusplus.com/doc/tutorial/files/
	/*
	file output guide
	[
	ball_mm
	ball_id
	ball_color
	ball_texture
	] 
	these [] represent one entry set
	*/
	ofstream theFile;
	theFile.open("mainFile.txt", std::ios_base::app);
	//opens in appened mode
	if (theFile.is_open())
	{
		theFile << "[\n";
		theFile << mm << "\n";
		theFile << id << "\n";
		theFile << col << "\n";
		theFile	<< tx << "\n";
		theFile	<< "]\n";
		theFile.close();
	}
	else cout<< "ERROR: file i/o";
}

int numberOfLines()
{
	int lines = 0;
	string line;
	ifstream theFile("mainFile.txt");
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
	
	string STRING, id[50], col[50], tx[50], t[50], main[50];
	double mm[50];
	short loop=0;
	int lines, x;
	string l;
	lines = numberOfLines();
	x = 0;
	ifstream theFile("mainFile.txt");
	if (theFile.is_open())
	{
		while(!theFile.eof())
		{
			getline(theFile,l);
		//	cout<<STRING;
			main[loop] = l; 
			cout << main[loop] << endl;
			if (main[loop] == "[" && x != 2)
			{
				cout << "entered" <<endl;
				mm[loop] = stod(main[loop+1]);
				blPTR -> setDiameter(mm[loop]);
				id[loop] = main[loop+2];
				blPTR -> setID(id[loop]);
				col[loop] = main[loop+3];
				blPTR -> setColor(col[loop]);
				tx[loop] = main[loop+4];
				blPTR -> setTexture(tx[loop]);
				blPTR++;
				x = 2;
				
			}
		}
		theFile.close();

	}
//	for (x = 0; x < lines; x++)
//	{
//		cout << "array location " << x << main[x]<<"\n";		
//	}
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

int main(int argc, char** argv)
{
	BallInfo bl[100];
	string search, text, col, id;
	int menuChoice, lines;
	double mm;
	int counter = 0;
	lines = numberOfLines();
	cout << "Number of lines: " << lines << "\n";
	
	readFromFile(bl, counter);
	
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
				printALL(bl, counter);
			}
			break;
			
			case 3:
			{
				searchGreaterTen(bl, counter);
				cls();
			}
			break;
			
			case 4:
			{
				searchLessTen(bl, counter);
				cls();
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
				cls();
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
				readFromFile(bl, counter);
			}
			break;
			
			case 10:{cout<<"bye\n";}break;

		//default: cout<<"invalid choice"<<endl;
		}


	}while (menuChoice != 10);

	return 0;
}
