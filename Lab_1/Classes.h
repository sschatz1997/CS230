//Classes.h
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <fstream>

using namespace std;

class Classes
{
	public:
		//constructors
		Classes();
		
		//accessors
		void print() const;
		string getClass_ID() const;
		string getCourse() const;
		string returnCourse(int CC);
		string getNumOfCredits() const;
		int searchClass(string searchCls) const;
				
		//mutators the comments will be what it will set to
		void setClass_N(string CN); //clasN
		void setClass_ID(string ClassID); //cid
		void setNumOfCredits(string nCreds); //nof
		
	private:
		string clasN;
		string cid;
		string nof;	
		string temp;
	
};
