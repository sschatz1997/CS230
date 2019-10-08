//Files.h
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <fstream>

using namespace std;
class Entries
{
	public:
		Entries();
		
		string getEntries() const;
		
		void setEntries(string E);
		
	private:
		string enter; //E
};
