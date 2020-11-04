#include <iostream>
#include <stack>

using namespace std;

int main() {
	int number;
	stack<int> divisors;
	cout << "Enter a number: ";
	cin >> number;

	int prime[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };


	for (int i = 0; number != 1; i++)
	{

		while (number % prime[i] == 0)
		{
			number = number / prime[i];
			divisors.push(prime[i]);
		}
	}

	while (!divisors.empty())
	{
		cout << divisors.top() << " ";
		divisors.pop();
	}




}