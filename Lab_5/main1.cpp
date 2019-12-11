#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
	struct node* node = new struct node;
	node->data = idata;
	node->left = NULL;
	node->right = NULL;
	return node;
};


/*
void node* search(int data){
	
}
class Node {
	struct Node* left;
	struct Node* right;
	int data;
	public Node::Node(int data)
	{
		this.data = data;
	};
	
	public void Node::insert(int value) {
		if (value <= data) {
			if (left == NULL){
				left = new Node(value);
			} else {
				left->insert(value);
			}
		} else {
			if (right == NULL){
				right = new Node(value);
			} else {
				right->insert(value);
			}
		}

	public bool Node::contains(int value){
		if (value == data){
			return true;
		} else if (value < data) {
			if (left == NULL){
				return false;
			} else {
				return left->contains(value);
			}
		} else {
			if (right == NULL){
				return false;
			} else {
				return right->contains(value);
			}
		}
	};
	
	public void Node::printInOrder() {
		if (left != NULL){
			left->printInOrder();
		}
		cout << data;
		if (right != NULL){
			right->printInOrder();
		}
	};
};*/


int main(int argc, char** argv) 
{
	int nodeSize;
	struct node *root = newNode();
	
	return 0;
}
