//Info.h
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <fstream>


using namespace std;

class Info
{
	public:
		//constructors
		Info();
		
		//accessors
		void print() const;
		string getStu_ID() const;
		string getF_name() const;
		string getL_name() const;
		string getClass_ID() const;
		string getCourse() const;
		string getNumOfCredits() const;
		
		//mutators the comments will be what it will set to
		void setStu_ID(string stuID);//sid 
		void setF_name(string FN);//firstN
		void setL_name(string LN); //lastN
		void setClass_N(string CN); //clasN
		void setClass_ID(string ClassID); //cid
		void setNumOfCredits(string nCreds); //nof

	private:
		string sid;
		string firstN;
		string lastN;
		string clasN;
		string cid;
		string nof;



};
