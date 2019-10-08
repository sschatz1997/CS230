#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <fstream>

using namespace std;

class Names 
{
	public:
		//constructors
		Names();
		
		//accessors
		void print() const;
		string getFname() const;
		string getLname() const;
		string getBoth() const;
		
		//mutators the comments will be what it will set to
		void setFname(string fname); //firstN
		void setLname(string lname); //lastN
		
	
	private:
		string firstN;
		string lastN;
		string both;

};
