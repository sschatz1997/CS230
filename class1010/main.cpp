//main.cpp
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

struct node{
	int data;
	node* next;
};

class ll
{
	private:
		node *head, *tail;
	public:
		ll()
		{
			head = NULL;
			tail = NULL;
		}

		void addNode(int x)
		{
			node *temp = new node;
			temp->data = x;
			temp->next = NULL;

			if (head == NULL)
			{
				head = temp;
				tail = temp;
			}
			else
			{
				tail->next = temp;
				tail = tail->next;
			}
		}
		
		node* gethead()
		{
			return head;
		}
		
		void print(node *head)
		{
			if (head == NULL)
			{
				cout << "NULL" << endl;
			}
			else
			{
				cout << head->data <<endl;
				print(head->next);
			}


		}
};

int menu()
{
	int choice;
	cout << "\t\t MAIN MENU\n"
		<<"\t1. add new int\n"
		<<"\t2. view all ints\n"
		<<"\t3. exit\n"
		<<"enter your option: ";
	cin>>choice;
	return choice;
}	

void data(ll* lPTR)
{
	lPTR -> addNode(1);
}

string print(ll* lPTR)
{
	lPTR -> print(0);
}

int main(int  arg, char** argv)
{
	ll* a;
	int choice;
//	a.addNode(1);
//	a.addNode(2);

	choice = menu();
	do{
		switch(choice)
		{
			case 1: data(a);
				break;
			case 2: print(a);
				break;
			

		}


	}while(choice != 3);
	return 0;
}



