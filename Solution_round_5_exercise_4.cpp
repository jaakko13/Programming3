#include <iostream>
#include <queue>
#include <stack>

using namespace std;


void stacktoqueue(stack<int>& stonk, queue<int>& q);
void queuetostack(stack<int>& stonk, queue<int>& q);
void sameStack(stack<int>& first, stack<int>& second);
void reverseStack(stack<int>& first, stack<int>& second);
void reversequeuewithstack(stack<int>& stonk, queue<int>& q);
void reversestackwithqueue(stack<int>& stonk, queue<int>& q);


int main() {
	stack<int> stonk;
	stack<int> second;
	queue<int> q;
	int numbers;
	int wants;

	cout << "How many numbers insert:" << endl;
	cin >> numbers;

	for (int i = 0; i < numbers; i++)
	{
		cout << "what number?" << endl;
		cin >> wants;
		stonk.push(wants);
	}

	reversestackwithqueue(stonk, q);

	cout << "here is your thang." << endl;

	while (!stonk.empty())
	{
		cout << stonk.top() << endl;
		stonk.pop();
	}

}

void stacktoqueue(stack<int> &stonk, queue<int> &q) {
	while (!stonk.empty())
	{
		q.push(stonk.top());
		stonk.pop();
	}

}


void queuetostack(stack<int>& stonk, queue<int>& q) {
	while (!q.empty())
	{
		stonk.push(q.front());
		q.pop();
	}
}


void sameStack(stack<int>& first, stack<int>& second) {
	stack<int> temp;

	while (!first.empty())
	{
		temp.push(first.top());
		first.pop();
	}


	while (!temp.empty())
	{
		second.push(temp.top());
		temp.pop();
	}
}


void reverseStack(stack<int>& first, stack<int>& second) {
	
	while (!first.empty())
	{
		second.push(first.top());
		first.pop();
	}
}

void reversequeuewithstack(stack<int>& stonk, queue<int>& q) {

	while (!q.empty())
	{
		stonk.push(q.front());
		q.pop();
	}

	while (!stonk.empty())
	{
		q.push(stonk.top());
		stonk.pop();
	}

}

void reversestackwithqueue(stack<int>& stonk, queue<int>& q) {

	while (!stonk.empty())
	{
		q.push(stonk.top());
		stonk.pop();
	}

	while (!q.empty())
	{
		stonk.push(q.front());
		q.pop();
	}

}