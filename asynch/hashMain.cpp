// map::empty
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include<cstdio>
#include<cstdlib>
#include <time.h>
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

const int VAR = 200;
//https://www.tutorialspoint.com/cplusplus-program-to-implement-hash-tables
using namespace std;

class hashEntry{
	public:
		int a;
		int x;
		hashEntry(int a, int x){
			this->a = a;
			this->x = x;
		}
};

class hashMap{
	private:
		hashEntry **t;
	public:
		hashTable(){
			t = new hashEntry * [VAR];
			for (int i = 0; i<VAR; i++)
			{
				t[i] = NULL;
			}
		}
		
		int hashing(int a)
		{
			return a % VAR;
		}
		
		void insert(int a, int x)
		{
			int q = hashing(a);
			while(t[q] != NULL && t[q]->a != x)
			{
				q = hashing(q + 1);
			}
			if(t[q] != NULL)
				delete t[q];
			t[q] = new hashEntry(a, x);
		}
		
		int search(int x)
		{
			int q = hashing(x);
			while(t[q] != NULL && t[q]->a != x)
			{
				q = hashing(q + 1);
			}
			if(t[q] != NULL)
				return -1;
			else
				return t[q]->x;	
		}
};

int menu()
{
	int c;
	cout << "==MAIN MENU=="<<endl;
	cout << "enter a value: ";
	cin  >> c;
	return c;
}

int main(int argc, char** argv) 
{
	hashMap hash1;
	int entry1, entry2;
	entry1 = menu();
	entry2 = menu();
	hash1.insert(entry1, entry2);
	
	cout << "key: " << entry2 << " value: " << hash1.search(entry1) << endl;

	
	return 0;
}


