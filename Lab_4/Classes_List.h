//Classes_List.h
#include <iostream>
#include "Classes.h"


class Class_List
{
	public:
		Class_List();
		void addClass(Classes);
		void normalPrintC();
		void rePrintClasses();//this is recursive
	private:
		typedef struct node
		{
			Classes cl;
			node* next;
		}* nodePTR;
		nodePTR head;
		nodePTR current;
		void rec2(nodePTR);
		
};

Class_List::Class_List()
{
	head = NULL;
	current = NULL;
}

void Class_List::addClass(Classes C)
{
	nodePTR newN = new node;
	newN -> next = NULL;
	newN -> cl = C;
	
	if (head != NULL)
	{
		current = head;
		while(current -> next != NULL)
		{
			current = current -> next;
		}
		current -> next = newN;
	}
	else
	{
		head = newN;
	}
}

void Class_List::normalPrintC()
{
	current = head;
	while(current != NULL)
	{
		cout << current -> cl.getClasses()<<endl;
		current = current -> next;
	}
}

void Class_List::rePrintClasses()
{
	current = head;
	rec2(current);
}

void Class_List::rec2(nodePTR c)
{
	if (c != NULL)
	{
		cout << c -> cl.getClasses()<<endl;
		rec2(c -> next);
	}
}
