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
	list<string> name;
	list<string> nameTemp;
	list<int> age;
	list<int> ageT;
	list<int> removed;
	string lastVal;
	string tempS, temp2, searchN;
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
				std::list<std::string>::iterator stt;
				name.merge(nameTemp);	
				string test1;
				test1 = searchName();
				size = name.size();
				stt = find(name.begin(), name.end(), test1);
				if(stt != name.end())
				{
					cout << "name found" << endl;
				}else{
					cout << "name not found" << endl;
				}
				/*for (int x = 0; x < size; x++)
				{
					if(nameTemp.front() == test1)
					{
						cout << "name found "<<endl;
					}else{
						nameTemp.pop_front();
					}
				}*/
				
				
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
				std::list<std::string>::iterator stt;
				name.merge(nameTemp);	
				string test1;
				test1 = searchName();
				size = name.size();
				stt = find(name.begin(), name.end(), test1);
				if(stt != name.end())
				{
					cout << "name found" << endl;
				}else{
					cout << "name not found" << endl;
				}
																
			}
			break;

			case 6:
			{
				int a2;
				a2 = searchAge();
				int e = 0;
				age.sort();
				for (std::list<int>::iterator it = age.begin(); it != age.end(); ++it)
				{
					test[e] = *it;
					e++;
					//cout << "test " << *it <<endl;
				}
				
				age.clear();
				
				for(int x = 0; x < e; x++)
				{
					if(test[x] == a2){
						test[x] = 0;
					}
					if(test[x] != 0)
					{
						age.push_back(test[x]);
					}
					if(x == e){
						cout<<"That age was never entered!"<<endl;
					}
				//	cout << "array: " << test[x] << endl;
				}
				cout << a2 <<" was deleted"<<endl;
				
			}
			break;

			case 7:
			{
				std::list<std::string>::iterator stt;
				cout << name;
				
			}
			break;	

			case 8:
			{
				cout<<"==EXITING=="<<endl;
			}
			break;			
		}
	}
	while(choice != 8);
	
	return 0;
}
