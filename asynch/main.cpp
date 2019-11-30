#include <list>
#include <string>
#include <fstream>
#include <cstring>
#include <iostream>
#include <iterator> 
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef list<int> IntegerList1;
typedef list<string> stringList1;

int menu()
{
	int choice;
	cout<<"==MENU==\n"
		<<"1. Add a ID to the list.\n"
		<<"2. Add a age to the list.\n"
		<<"3. Search for a ID.\n"
		<<"4. Search for a aga.\n"
		<<"5. Remove a ID.\n"
		<<"6. Remove a age.\n"
		<<"7. EXIT"<<endl;
	cin >> choice;
	return choice;
}

int addID()
{
	int ID;
	cout<<"What is the ID that you want to add to the list: ";
	cin >> ID;
	return ID;
	
}

int searchID()
{
	int ID;
	cout << "What is the ID that you want to seach for: ";
	cin >> ID;
	return ID;
}

int searchAge()
{
	int age;
	cout << "What is the age you want to search for: ";
	cin >> age;
	return age;
}

int addAge()
{
	int age;
	cout << "Note: age can not be 0"<<endl;
	cout<<"What is the age that you want to add to the list: ";
	cin >> age;
	return age;
}



int main(int argc, char** argv) {
	list<int> ID;
	list<int> IDTemp;
	list<int> age;
	list<int> ageT;
	list<int> removed;
	int lastVal;
	int tempS, temp2, searchN;
	int tempA, size;
	int test[100];
	
	int choice;
	
	do
	{
		choice = menu();
		
		switch(choice)
		{
			case 1:
			{
				tempS = addID();
				ID.push_back(tempS);
			}
			break;
			
			case 2:
			{
				tempA = addAge();
				age.push_back(tempA);
			}
			break;
			
			case 3:
			{
				int aa;
				aa = searchID();
				for (std::list<int>::iterator it = ID.begin(); it != ID.end(); ++it)
				{
					if(*it == aa)
					{
						cout<<"ID found"<<endl;
					}else{
						cout<<"ID not found"<<endl;
					}
				}				
			}
			break;
			
			case 4:
			{
				int aa;
				aa = searchAge();
				for (std::list<int>::iterator it = age.begin(); it != age.end(); ++it)
				{
					if(*it == aa)
					{
						cout<<"age found"<<endl;
					}else{
						cout<<"age not found"<<endl;
					}
				}
			}
			break;

			case 5:
			{
				int temp1;
				int test = 0;
				cout << "What is the ID that you want to delete? ";
				cin >> temp1;
				do
				{
					for (std::list<int>::iterator it = ID.begin(); it != ID.end(); ++it)
					{
						if(*it == temp1)
						{
							for (std::list<int>::iterator it2 = ID.begin(); it2 != ID.end(); ++it2)
							{
								if(*it2 != temp1)
								{
									IDTemp.push_back(*it2);
								}
							}						
							test = 1;
						}else{
							//cout<<"ID not found"<<endl;
						}
					}		
				}while(test != 1);
				if(test == 1)
				{
					ID.clear();
					IDTemp.merge(ID);
				}
				IDTemp.clear();			
			}
			break;

			case 6:
			{
				int temp1;
				int test = 0;
				cout << "What is the Age that you want to delete? ";
				cin >> temp1;
				do
				{
					for (std::list<int>::iterator it = age.begin(); it != age.end(); ++it)
					{
						if(*it == temp1)
						{
							for (std::list<int>::iterator it2 = age.begin(); it2 != age.end(); ++it2)
							{
								if(*it2 != temp1)
								{
									ageT.push_back(*it2);
								}
							}						
							test = 1;
						}else{
							//cout<<"ID not found"<<endl;
						}
					}		
				}while(test != 1);
				if(test == 1)
				{
					age.clear();
					ageT.merge(age);
				}										
			}
				
			
			break;

			case 7:
			{
				cout<<"==EXITING=="<<endl;
			}
			break;			
		}
	}
	while(choice != 7);
	
	return 0;
}
