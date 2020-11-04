#include <stack>
#include <iostream>
using namespace std;

int main()

{
	int x;
	int y;
	double item;
	stack<double> numbers; 

	cout << " Type in an integers in increasing order." << endl;
	cin >> x;
	numbers.push(x);
	cin >> y;
	
	while (y > numbers.top())
	{
		numbers.push(y);
		cin >> y;
	}

	if (y < numbers.top())
	{
		cout << "You did not type in an increasing value and the input has stopped." << endl
			<< "The integers will now be printed in decreasing order." << endl;

		while (!numbers.empty()) {
			cout << numbers.top() << " ";
			numbers.pop();
		}
	}
	

	

		
	
	
}