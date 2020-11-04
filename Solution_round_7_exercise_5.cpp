using namespace std;
#include <iostream>


template <class something>

class stack_nodeChain
{
private:
	struct node {
		node* previous;
		something data;
	};
	node* head;
	int count = 0;

public:
	stack_nodeChain() { head = NULL; }
	~stack_nodeChain() {

	}

	//delets current node and moves one back
	bool pop() {
		if (count <= 0)  return false;
		else {
			node* temp = head;
			head = head->previous;
			delete temp;
			count--;
			return true;
		}
	}

	//adds data to head of stack
	void push(something d) {
		node* temp = new node;
		temp->data = d;
		temp->previous = head;
		head = temp;
		count++;
	}


	//size method that returns size. Uses counter through program.
	int size() { return count; }

	bool empty() { return (count == 0) ? true : false; }

	something top() { return head->data; }
};

int main() {

	stack_nodeChain<int> showSize;


	showSize.push(1);
	showSize.push(2); 
	showSize.push(3);

	cout << "Size of stack chain is " << showSize.size();

}