//fileio.cp

#include<iostream>
#include<fstream>

using namespace std;

void writeToFile()
{


}


int  writeToBuffer(string* namePTR, int cout)
{
	string tempName;
	for (int i = 0; i < count; i++)
	{
		namePTR++;
	}
	cout << "Enter last name: ";
	cin >> tempName;

}


int main()
{
	int count = 0;
	int choice;
	string names[100];
	do
	{
		cout << "enter record 1 for yes, 2 for no: ";
		cin >> choice;
		if (choice != 2)
		{
			count = writeToBuffer(names, count);
		}
	}while(choice != 2);

	count = writeToFile(names, count);

	return 0;
}
