//campusAppV1.cpp
#include<cstdlib>
#include<iostream>
#include "Person.h"
using namespace std;

void tester(Person* pPTR)
{
	string fn, ln, id;
	fn = "sam";
	ln = "schatz";
	id = "#1";
	pPTR -> setFN(fn);
	pPTR -> setLN(ln);
	pPTR -> setIDidd);

	cout << "First name: " << pPTR -> getFN() << endl;
	cout << "Last name: " << pPTR -> getLN() << endl;
	cout << "ID: " << pPTR -> getID() << endl;
}

int main(int argc, char *argv[])
{
	Person p1[100];
	
	tester(p1);

	return EXIT_SUCCESS;
}
