#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <bits/stdc++.h> 
#include <fstream>
#include "names.h"

using namespace std;

Names::Names()
{
	string key = "";
	string firstN = "";
	string lastN = "";
	string both = "";
}

void Names::setFname(string fname) { firstN = fname; }
void Names::setLname(string lname) { lastN = lname; }
void Names::setKey(string mKey) { key = mKey; }

string Names::getKey() const { return key; }
string Names::getFname() const { return firstN; }
string Names::getLname() const { return lastN; }
string Names::getBoth() const {
	string both;
	both = firstN + " " + lastN;
	return both;
}

void Names::print() const {
	cout << "key: " << key << endl;
	cout << "First name: " << firstN << endl;
	cout << "Last name: " << lastN << endl;
}

void Names::defaultWrite(string key, string fname, string lname)
{
	ofstream outData;
	outData.open("info.txt", ios::app);
	outData << fname << " ";
	outData << lname << " ";
	outData << key << "\n";
	outData.close();
}

void Names::overwriteFile(string key, string fname, string lname)
{
	//http://www.cplusplus.com/reference/fstream/ofstream/ofstream/
	ofstream overwrite("info.txt");
	overwrite << fname << " ";
	overwrite << lname << " ";
	overwrite << key << "\n";
	overwrite.close();
}
