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
		string getCourse() const;
		string getCourse2() const;
		string getCourse3() const;
		string getCourse4() const;
		string getClass_ID() const;
		string getClass_ID2() const;
		string getClass_ID3() const;
		string getClass_ID4() const;
		string getNumOfCredits() const;
		string getNumOfCredits2() const;
		string getNumOfCredits3() const;
		string getNumOfCredits4() const;
		int searchStudent(string searchSID); //this will be done using the students ID
		
		//mutators the comments will be what it will set to
		void setStu_ID(string stuID);//sid 
		void setF_name(string FN);//firstN
		void setL_name(string LN); //lastN
		void setClass_N(string CN); //clasN
		void setClass_N2(string CN2);
		void setClass_N3(string CN3);
		void setClass_N4(string CN4);	
		void setClass_ID(string ClassID); //cid
		void setClass_ID2(string ClassID2);
		void setClass_ID3(string ClassID3);
		void setClass_ID4(string ClassID4);
		void setNumOfCredits(string nCreds); //nof
		void setNumOfCredits2(string nCreds2);
		void setNumOfCredits3(string nCreds3);
		void setNumOfCredits4(string nCreds4);
		
		
	private:
		string sid;
		string firstN;
		string lastN;
		string clasN;
		string clasN2;
		string clasN3;
		string clasN4;
		string cid;
		string cid2;
		string cid3;
		string cid4;
		string nof;
		string nof2;
		string nof3;
		string nof4;



};
