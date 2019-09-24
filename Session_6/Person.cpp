//Person.cpp
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "Person.h"
using namespace std;

Person::Person()
{
	string first_name = "";
	string last_name = "";
	string ID = "";
}

void Person::setFN(string fn) { first_name = fn; }
void Person::setLN(string ln) { last_name = ln; }
void Person::setID(string id) { ID = id; }
//void Person::getBothNames(string first_name, string last_name)


string Person::getFN() const { return first_name; }
string Person::getLN() const { return last_name; }
string Person::getID() const { return ID; }



