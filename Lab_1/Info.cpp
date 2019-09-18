//Info.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.H>
#include <fstream>
#include "Info.h"

using namespace std;


Info::Info()
{
	string sid = "";
	string firstN = "";
	string lastN = "";
	string clasN = "";
	string cid = "";
	string nof = "";
}

void Info::setStu_ID(string stuID) { sid = stuID;}
void Info::setF_name(string FN) { firstN = FN; }
void Info::setL_name(string LN) { lastN = LN; }
void Info::setClass_N(string CN) { CN = clasN; }
void Info::setClass_ID(string ClassID) { cid = ClassID; }
void Info::setNumOfCredits(string nCreds) { nof = nCreds; }

string Info::getStu_ID() const { return sid; }
string Info::getF_name() const { return firstN; }
string Info::getL_name() const { return lastN; }
string Info::getCourse() const { return clasN; }
string Info::getClass_ID() const { return cid; }
string Info::getNumOfCredits() const { return nof; }

void Info::print() const { 
	cout << "\t\t all student info: \n"
		<<"\t Student ID: " << sid << "\n"
		<<"\t First name: " << firstN << "\n"
		<<"\t Last name: " << lastN << "\n";
	if(clasN == "")
		cout << "\t Class name: not entered yet.\n";
	else
		cout << "\t Class name: " << clasN << "\n";
	if(cid == "")
		cout << "\t Class ID: not entered yet.\n";
	else
		cout << "\t Class ID: " << cid << "\n";
	if(nof == "")
		cout << "\t Number of Credits: not entered yet.\n";
	else
		cout << "\t Number of Credits: " << nof << "\n";
}
