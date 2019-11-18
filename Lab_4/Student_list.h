//Student_list.h
#include <iostream>
#include "StudentInfo.h"

using namespace std;

class Student_List
{
	public:
		Student_List();
		void addStudent(StudentInfo);
		void normalListPrint(); 
		void rePrint(); //prints recursivly
	private:
		typedef struct node
		{
			StudentInfo fi;
			node* next;
		}* nodePTR;
		nodePTR head;
		nodePTR current;
		void rec(nodePTR);

};

Student_List::Student_List()
{
	head = NULL;
	current = NULL;
}

void Student_List::addStudent(StudentInfo f)
{
	nodePTR newNode = new node;
	newNode -> next = NULL;
	newNode -> fi = f;
	
	if (head != NULL)
	{
		current = head;
		while(current -> next != NULL)
		{
			current = current -> next;
		}
		current -> next = newNode;
	}
	else
	{
		head = newNode;
	}
}

void Student_List::normalListPrint()
{
	current = head;
	while(current != NULL)
	{
		cout <<current -> fi.getFullInfo()<<endl;
		current = current -> next;
	}
}

void Student_List::rePrint()
{
	current = head;
	rec(current);
}

void Student_List::rec(nodePTR c)
{
	if (c != NULL)
	{
		cout << c -> fi.getFullInfo()<<endl;
		rec(c -> next);
	}
}

