#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> theStack;
	int size;
	theStack.push(1);
	theStack.push(10);
	theStack.push(20);
	theStack.push(30);
	theStack.push(15);
	theStack.push(25);
	theStack.push(35);
	size = theStack.size();
	// their 7 nodes in the stack
	cout << "The size of the stack is before popping " << theStack.size() << endl;
	while(!theStack.empty())
	{
		cout << "popping: " << theStack.top()<<endl;
		theStack.pop();
	}
	cout << "The size of the stack is after popping " << theStack.size() << endl;
	return 0;
}
