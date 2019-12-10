#include <iostream>
#include <vector>
using namespace std;

//int search()


void addToVector(vector<int> &g1, int userInput)
{
	g1.push_back(userInput);
}

void binSearch(vector<int> &g1, int userInput, int size)
{
	int low = 0;
	int high = size - 1;
	int mid;
	int count;
	
	while(low <= high)
	{
		mid = (low+high) / 2;
		count++;
		
		if (userInput == g1[mid])
		{
			break;
		}
		else if(userInput > g1[mid])
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	
	cout << "Binary search comparison: " << count << endl;
}

void linSearch(vector<int> &g1, int userInput, int size)
{
	int count = 0;
	for(int i = 0; i < size; i++)
	{
		count++;
		if (userInput == g1[i])
		{
			break;
		}
	}

	cout << "Lin Search Comparison: " << count << endl;
	// this will alway be the slowest because we are adding the value to the back
}

int main(int argc, char** argv)
{
	vector<int> g1;
	int sizeOfVec;
	int userInput;
	int userInput2;
	int userInput3;
	char input2;
	
	cout << "Enter the size of the vector: ";
	cin >> sizeOfVec;
	
	g1.resize(sizeOfVec);
	
	cout << "Enter a int between 1 and " << sizeOfVec << " to seatch in the vector."<<endl;
	cout << ": ";
	cin >> userInput;
	addToVector(g1, userInput);

	for(int i = 0; i < g1.size(); i++)
	{
		cout << "This was entered: " << g1[i] << endl;
	}

	cout << "Enter a int between 1 and " << sizeOfVec << " to seatch in the vector Binary Search."<<endl;
	cout << ": ";
	cin >> userInput2;
	binSearch(g1, userInput2, sizeOfVec);
	
	cout << "Enter a int between 1 and " << sizeOfVec << " to seatch in the vector Linear Search."<<endl;
	cout << ": ";
	cin >> userInput3;
	linSearch(g1, userInput3, sizeOfVec);

}
