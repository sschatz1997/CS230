//fileio.cp

#include<iostream>
#include<fstream>

using namespace std;

void readFromFile()
{
	string line;
	ifstream inData ("namesFile.txt");
	if (inData.is_open())
	{
		while (getline (inData,line))
		{
			cout << line << "\n";
		}
		inData.close();
	}
	else
		cout << "File doesnt exist\n";

}


void writeToFile(string* namePTR, int count)
{
	ofstream outData;
	outData.open("namesFile.txt", ios::app);
	for (int i = 0; i < count; i++)
	{
		outData << *namePTR << endl;
		namePTR++;
	}
	outData.close();

}


int  writeToBuffer(string* namePTR, int count)
{
	string name;
	for (int i = 0; i < count; i++)
	{
		namePTR++;
	}
	cout << "Enter last name: ";
	cin >> name;
	*namePTR = name;
	namePTR++;
	count++;
	return count;
}

void printAll(string* namePTR, int count)
{
	for(int i = 0; i < count; i++)
	{
		cout << "name[" << i << "]: " << *namePTR << endl;
		namePTR++;
	}
}


int main()
{
	int count = 0;
	int choice;
	string names[100];
	
	readFromFile();
	
	do
	{
		cout << "enter record 1 for yes, 2 for no: ";
		cin >> choice;
		if (choice != 2)
		{
			count = writeToBuffer(names, count);
		}
	}while(choice != 2);

	//count = writeToFile(names, count);
	cout << " data in buffer is: \n";
	
	printAll(names, count);
	writeToFile(names, count);

	return 0;
}
