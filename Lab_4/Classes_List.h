//Classes_List.h
#include <iostream>
#include "Classes.h"


class Class_List
{
	public:
		Class_List();
		void addClass(Classes);
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

Class_list::Class_List()
{
	head = NULL;
	current = NULL;
}


