#include <stack>
#include <iostream>
using namespace std;

int main()
/* Pre: The user supplies an integer n and n decimal numbers.
Post: The numbers are printed in reverse order.
Uses: The STL class stack and its methods */
{
	int n;
	char item;
	stack<char> letters; // declares and initializes a stack of numbers
	cout << " Type in an integer n followed by n letters."
		<< endl
		<< " The letters will be printed in reverse order."
		<< endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> item;
		letters.push(item);
	}
	cout << endl << endl;

	stack<char>check;
	int i;
	char x;
	bool odd = (n % 2 == 1) ? true : false;



	for (i = 0; i < n / 2; i++)
	{
		x = letters.top();
		check.push(x);
		letters.pop();

	}

	

	if (odd == true)
	{
		letters.pop();
	}


	

	
	for (int i = 0; i < n / 2; i++)
	{
		
		if (check.top() != letters.top())
		{
			cout << "Your word is not a palindrome.";
			exit(0);
		}
		else {
			cout << "Your word is a palindrome.";
			exit(0);
		}
	}
	

}