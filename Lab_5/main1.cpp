#include <vector>
#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	/*struct node* left;
	struct node* right;*/
};

node* getNewNode(int data)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
	/*node->data = idata;
	node->left = NULL;
	node->right = NULL;
	return node;*/
}

node* insert(node* root, int data)
{
	if(root == NULL){
		root = getNewNode(data);
	}
	//enter the lesser value in the right because the example i am using does the opposite
	else if(data <= root->data)
	{
		root->right = insert(root->right, data);
	} else {
		root->left = insert(root->left, data);
	}
	return root;
	
}

bool search(node* root, int data)
{
	if(root == NULL)
	{
		return false;
	}
	else if(root->data == data)
	{
		return true;
	}
	else if(data <= root->data)
	{
		return search(root->right, data);
	}
	else 
	{
		return search(root->left, data);
	}
}

void addToVector(vector<int> &v1, int val)
{
	v1.push_back(val);
}



int menu()
{
	int choice;
	cout<< "===MAIN MENU=="<<endl;
	cout<< "1. add value\n"
		<< "2. search value\n"
		<< "3. exit."<<endl;
	cout<<" : ";
	cin >> choice;
	return choice;
}


int main(int argc, char** argv) 
{
	node* root = NULL;
	int input;
	int choice;
	int sizeOfVec = 1000;
	vector<int> v1;

	v1.resize(sizeOfVec);

	do
	{
		choice = menu();
		
		switch (choice)
		{
			case 1:
			{
				cout << "enter a value: ";
				cin >> input;
				addToVector(v1, input);
				root = insert(root, input);
			}
			break;
			
			case 2:
			{
				cout << "enter the value you want to search for: ";
				cin >> input;
				if(search(root, input) == true)
				{
					cout << input << " exists in the tree!"<<endl;
				}else{
					cout << input << " does not exist in the tree!"<<endl;
				}

			}		
			break;
		}
		
	}while(choice != 3);	

	return 0;
}
