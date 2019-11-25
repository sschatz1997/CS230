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

int menu()
{
	int choice;
	cout<<"==MENU==\n"
		<<"1. Add a name to the list.\n"
		<<"2. Add a age to the list.\n"
		<<"3. Search for a name.\n"
		<<"4. Search for a aga.\n"
		<<"5. Remove a name.\n"
		<<"6. Remove a age.\n"
		<<"7. EXIT"<<endl;
	cin >> choice;
	return choice;
}

string addName()
{
	string name;
	cout<<"What is the name that you want to add to the list: ";
	cin >> name;
	return name;
	
}

string searchName()
{
	string name;
	cout << "What is the name that you want to seach for: ";
	cin >> name;
	return name;
}

int addAge()
{
	int age;
	cout<<"What is the age that you want to add to the list: ";
	cin >> age;
	return age;
}



int main(int argc, char** argv) {
	list<string> name;
	list<string> nameTemp;
	list<int> age;
	list<int> ageT;
	string lastVal;
	string tempS, temp2, searchN;
	int tempA;
	string test[100];
	
	int choice;
	
	do
	{
		choice = menu();
		
		switch(choice)
		{
			case 1:
			{
				tempS = addName();
				name.push_back(tempS);
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
				string aa;
				cout<<"enter an age: ";
				cin>>string;
				for (std::list<string>::iterator it = age.begin(); it != age.end(); ++it)
				{
					if(*it == aa)
					{
						cout<<"age found"<<endl;
					}else{
					
					}
				}

				/*int aa, LV;
				age.merge(ageT);
				cout<<"enter an age: ";
				cin>>aa;
				for(int x = 0; x < ageT.size(); x++)
				{
					LV = ageT.back();
					if(aa == LV)
					{
						cout<<"age found"<<endl;
					}else{
						ageT.remove(ageT.size());
					}
				}
				cout << "is c++ small brained?"<<endl;
				string temp;
				name.merge(nameTemp);
				int size, T;
				size = name.size();
				searchN = searchName();
				cout << "size: " << size<<endl;
				for (int x = 0; x < size; x++)
				{
					cout << "entering the loop\n";
					lastVal = nameTemp.back();
					if(lastVal == searchN)
					{
						cout << lastVal << "name found!"<< searchN<<endl;
						
					}else{
						nameTemp.erase(nameTemp.size(),);
					}
					T = x;
				}
				if(T == size)
				{
					cout << "name was not found"<<endl;
				}*/
				
				
			}
			break;
			
			case 4:
			{
				int aa;
				cout<<"enter an age: ";
				cin>>aa;
				for (std::list<int>::iterator it = age.begin(); it != age.end(); ++it)
				{
					if(*it == aa)
					{
						cout<<"age found"<<endl;
					}else{
					
					}
				}
			}
			break;

			case 5:
			{
				int size1 = name.size();
				
			//	string test1 = std::find(std::begin(name), std::end(name), name);
			//	cout << "test: " << test1<<endl;
				
			}
			break;

			case 6:
			{
				cout<<"==EXITING=="<<endl;
			}
			break;			
		}
	}
	while(choice != 7);
	
	return 0;
}
