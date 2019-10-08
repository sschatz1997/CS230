//Files.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include "Files.h"

using namespace std;

Entries::Entries()
{
	string enter = "";
}

void Entries::setEntries(string E) { enter = E; }

string Entries::getEntries() const { return enter;}
