//Info.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include "Info.h"

using namespace std;


Info::Info()
{
	string sid = "";
	string firstN = "";
	string lastN = "";
	string CN = "";
	string CN2 = "";
	string CN3 = "";
	string CN4 = "";
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
void Info::setClass_N(string CN) { clasN = CN; }
void Info::setClass_N2(string CN2) { clasN2 = CN2; }
void Info::setClass_N3(string CN3) { clasN3 = CN3; }
void Info::setClass_N4(string CN4) { clasN4 = CN4; }
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
string Info::getCourse2() const { return clasN2; }
string Info::getCourse3() const { return clasN3; }
string Info::getCourse4() const { return clasN4; }
string Info::getClass_ID() const { return cid; }
string Info::getClass_ID2() const { return cid2; }
string Info::getClass_ID3() const { return cid3; }
string Info::getClass_ID4() const { return cid4; }
string Info::getNumOfCredits() const { return nof; }
string Info::getNumOfCredits2() const { return nof2; }
string Info::getNumOfCredits3() const { return nof3; }
string Info::getNumOfCredits4() const { return nof4; }

int Info::searchStudent(string searchSID)
{
	string temp;
	searchSID = temp;
	if(searchSID == sid)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Info::print() const { 
	cout << "\t\t all student info: \n"
		<<"\t Student ID: " << sid << "\n"
		<<"\t First name: " << firstN << "\n"
		<<"\t Last name: " << lastN << "\n";
	cout << "\t Class 1: "<<endl;
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
	
	cout << "\t Class 2: "<<endl;
	
	if(clasN2 == "")
		cout << "\t Class name: not entered yet.\n";
	else
		cout << "\t Class name: " << clasN2 << "\n";
	if(cid2 == "")
		cout << "\t Class ID: not entered yet.\n";
	else
		cout << "\t Class ID: " << cid2 << "\n";
	if(nof2 == "")
		cout << "\t Number of Credits: not entered yet.\n";
	else
		cout << "\t Number of Credits: " << nof2 << "\n";
		
	cout << "\t Class 3:"<<endl;
	if(clasN3 == "")
		cout << "\t Class name: not entered yet.\n";
	else
		cout << "\t Class name: " << clasN3 << "\n";
	if(cid3 == "")
		cout << "\t Class ID: not entered yet.\n";
	else
		cout << "\t Class ID: " << cid3 << "\n";
	if(nof3 == "")
		cout << "\t Number of Credits: not entered yet.\n";
	else
		cout << "\t Number of Credits: " << nof3 << "\n";
		
	cout << "\t Class 4:"<<endl;
	if(clasN4 == "")
		cout << "\t Class name: not entered yet.\n";
	else
		cout << "\t Class name: " << clasN4 << "\n";
	if(cid4 == "")
		cout << "\t Class ID: not entered yet.\n";
	else
		cout << "\t Class ID: " << cid4 << "\n";
	if(nof4 == "")
		cout << "\t Number of Credits: not entered yet.\n";
	else
		cout << "\t Number of Credits: " << nof4 << "\n";
}
