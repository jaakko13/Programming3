using namespace std;
#include <iostream>

template <class something>


class queue_nodeChain
{
private:
	struct node {
		node* previous;
		something data;
	};
	node* head;
	node* back;
	int count = 0;

public:
	//constructr
	queue_nodeChain() { head = back = NULL; }

	//destructor
	~queue_nodeChain() {
		while (count != 0)
		{
			pop();
		}
	}

	//copy constructor
	queue_nodeChain(const queue_nodeChain& a) {
		node* temp = new node;
		temp = a.head;

		for (int tcount = a.count; tcount > 0; tcount--)
		{
			push(temp->data);
			temp = temp->previous;
		}

		this->count = a.count;

	}

	//assignment operator
	queue_nodeChain& operator= (const queue_nodeChain& a) {
		//delete contents of queue that is being copied into
		while (count != 0)
		{
			pop();
		}

		node* temp = new node;
		temp = a.head;

		for (int tcount = a.count; tcount > 0; tcount--)
		{
			push(temp->data);
			temp = temp->previous;
		}

		this->count = a.count;

		return *this;
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

	//adds data to front of queue
	void push(something d) {
		node* temp = new node;
		temp->data = d;

		if (count == 0)
		{
			//back->previous = temp;
			head = back = temp;
			//head->previous = back;
			count++;
			//cout << "if work";
		}
		else if (count == 1)
		{
			head->previous = temp;
			back = temp;
			count++;
			//cout << "else work";
		}
		else
		{
			back->previous = temp;
			back = temp;
			count++;
		}


	}

	int size() { return count; }

	bool empty() { return (count == 0) ? true : false; }

	something retrieve() { return head->data; }


	//full method returns true if queue is full which is always full except when it is empty
	//You might need to know if the queue is not empty in certain scenarios when making a driver program.
	bool full() {
		if (empty() == true)
		{
			cout << "Queue is not full.";
			return false;
		}
		else {
			cout << "Queue is full.";
			return true;
		}
	}
};


int main() {

	queue_nodeChain<int> numbers;

	numbers.push(1);
	numbers.push(2);
	numbers.push(3);

	//queue_nodeChain<int> copied(numbers);


	queue_nodeChain<int> copied;
	copied.push(4);
	copied = numbers;

	for (int i = 0; i < 3; i++)
	{
		cout << numbers.retrieve();
		numbers.pop();
	}

	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << copied.retrieve();
		copied.pop();
	}



}