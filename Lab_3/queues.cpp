#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> q;

	for(int i = 0; i < 20; i++)
	{
		cout << "Queueing " <<i <<endl;
		q.push(i);
	}

	cout << "The size of the queue is: " << q.size() << endl;
	cout << "The first value is: " << q.front() << endl;
	cout << "The last value is: " << q.back() << endl;

	while(!q.empty())
	{
		cout << "Popping: " << q.front() << endl;
		q.pop();
	}

	cout << "The size of the queue after poping is: " << q.size() << endl;
	
	return 0;
}
