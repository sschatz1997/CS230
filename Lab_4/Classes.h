//Classes.h
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <list> 
#include <iterator> 
#include <fstream>

#ifndef CLASSES_H
#define CLASSES_H

using namespace std;

class Classes
{
	public:
		Classes();
		
		void setClasses(string, string);
		string getClasses() const;

	private:
		string class1;//C1
		string class2;//C2

	
};

#endif
