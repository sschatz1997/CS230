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
	string clasN2 = "";
	string clasN3 = "";
	string clasN4 = "";
	string cid = "";
	string cid2 = "";
	string cid3 = "";
	string cid4 = "";
	string nof = "";
	string nof2 = "";
	string nof3 = "";
	string nof4 = "";
}

void Info::setStu_ID(string stuID) { sid = stuID;}
void Info::setF_name(string FN) { firstN = FN; }
void Info::setL_name(string LN) { lastN = LN; }
void Info::setClass_N(string CN) { CN = clasN; }
void Info::setClass_N2(string CN2) { CN2 = clasN2; }
void Info::setClass_N3(string CN3) { CN3 = clasN3; }
void Info::setClass_N4(string CN4) { CN4 = clasN4; }
void Info::setClass_ID(string ClassID) { cid = ClassID; }
void Info::setClass_ID2(string ClassID2) { cid2 = ClassID2; }
void Info::setClass_ID3(string ClassID3) { cid3 = ClassID3; }
void Info::setClass_ID4(string ClassID4) { cid4 = ClassID4;}
void Info::setNumOfCredits(string nCreds) { nof = nCreds; }
void Info::setNumOfCredits2(string nCreds2) { nof2 = nCreds2; }
void Info::setNumOfCredits3(string nCreds3) { nof3 = nCreds3; }
void Info::setNumOfCredits4(string nCreds4) { nof4 = nCreds4; }

string Info::getStu_ID() const { return sid; }
string Info::getF_name() const { return firstN; }
string Info::getL_name() const { return lastN; }
string Info::getCourse() const { return clasN; }
string Info::getClass_ID() const { return cid; }
string Info::getNumOfCredits() const { return nof; }

int Info::searchStudent(string searchSID)
{
	string temp;
	searchSID = temp;
	if(searchSID == sid)
	{
		cout << "yes" << endl;
		return 1;
	}
	else
	{
		cout << "no" << endl;
		return 0;
	}
}

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
