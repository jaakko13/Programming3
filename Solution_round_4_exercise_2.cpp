#include <iostream>
#include <stack>

using namespace std;

typedef char Stack_entry;

bool full(stack<int> &s);
void clear(stack<int>& s);
int size(stack<int>& s);
void delete_all(stack<int>& s, Stack_entry x);


enum Error_code {
	success, fail, utility_range_error, underflow, overflow, fatal,
	not_present, duplicate_error, entry_inserted, entry_found,
	internal_error
};

int main() {
	stack<int> s;
	int howmany, x;

	cout << "How many numbers?";
	cin >> howmany;


	for (int i = 0; i < howmany; i++)
	{
		cout << "What number would you like to insert?";
		cin >> x;

		s.push(x);
	}

	//full(s);


	delete_all(s, 3);

	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	
}




bool full(stack<int> &s) {
	
	if (!s.empty())
	{
		cout << "The stack is full.";
		return true;
	}
	else if (s.empty());
	{
		cout << "The stack is empty.";
		return false;
	}

}


Error_code pop_top(stack<int> &s, Stack_entry &t) {
	t = s.top();
	s.pop();

	return success;
}


void clear(stack<int> &s) {

	while (!s.empty())
	{
		s.pop();
	}

}


int size(stack<int> &s) {
	cout << "Size of the stack is " << s.size();
	return s.size();
}


void delete_all(stack<int>& s, Stack_entry x) {
	stack<int> temp;


	while (!s.empty())
	{
		if (s.top() == x)
		{
			s.pop();
		}
		else if (s.top() != x)
		{
			temp.push(s.top());
			s.pop();
		}
	}

	while(!temp.empty())
	{
		s.push(temp.top());
		temp.pop();
	}
}