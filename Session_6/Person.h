//Person.h
#include<string>
using namespace std;
#ifndef PERSON_H
#define PERSON_H

class Person
{
	public:
		//constructor
		Person();
		//Person(string, string, string);
		
		//mutators
		void setFN(string fn);
		void setLN(string ln);
		void setID(string id);
		
		//accessor
		string getFN() const;
		string getLN() const;
		string getID() const;
		
	private:
		string first_name;
		string last_name;
		string ID;
};

#endif
