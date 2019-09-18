//Classes.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include "Classes.h"

using namespace std;

Classes::Classes()
{
	string clasN = "";
	string cid = "";
	string nof = "";	
}

void Classes::setClass_N(string CN) { clasN = CN; }
void Classes::setClass_ID(string ClassID) { cid = ClassID; }
void Classes::setNumOfCredits(string nCreds) { nof = nCreds; }

string Classes::getCourse() const { return clasN; }
string Classes::getClass_ID() const { return cid; }
string Classes::getNumOfCredits() const { return nof; }

void Classes::print() const {
		cout << "\t\t All classes entered: \n"
			<< "\t course id: " << cid <<"\n"
			<< "\t course name: " << clasN << "\n"
			<< "\t number of credits: " << nof << "\n";
}
