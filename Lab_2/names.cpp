#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include "names.h"

using namespace std;

Names::Names()
{
	string firstN = "";
	string lastN = "";
	string both = "";
}

void Names::setFname(string fname) { firstN = fname; }
void Names::setLname(string lname) { lastN = lname; }

string Names::getFname() const { return firstN; }
string Names::getLname() const { return lastN; }
string Names::getBoth() const {
	string both;
	both = firstN + " " + lastN;
	return both;
}

void Names::print() const {
	cout << "First name: " << firstN << endl;
	cout << "Last name: " << lastN << endl;
}
