//Classes.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <list> 
#include <iterator> 
#include <fstream>
#include "Classes.h"

using namespace std;


Classes::Classes()
{
	string C1 = "";
	string C2 = "";
}

void Classes::setClasses(string C1, string C2)
{
	class1 = C1;
	class2 = C2;
}

string Classes::getClasses() const
{
	return "Class 1: " + class1 + "\n" +
			"Class 2: " + class2 + "\n";
}


