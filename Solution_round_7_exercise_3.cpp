#include <iostream>
using namespace std;

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

	int size() { return count; }

	bool empty() { return (count == 0) ? true : false; }

	something top() { return head->data; }
};

struct node {
	node* head;
	node* previous;
	node* next;
	int data;
};


int main(){
	//part a
	/*
	node* p0 = new node();
	node* p1 = p0->next = new node();
	p0->data = 0;
	p1->data = 1;

	cout << p0->data << endl;
	cout << p0->next->data;
	
	*/


	//part b
	/*
	node* p0 = new node();
	node* p1 = p0->previous = new node();
	node* p2 = p0->previous = new node();
	
	p0->data = 0;
	p1->data = 1;
	p2->data = 2;
	
	cout << p0->data << endl;
	cout << p0->previous->data << endl;
	*/

	//part c
	
	node* p0 = new node();
	node* p1 = p0->next = new node();
	node* p2 = p1->next = p1->previous = new node();

	p0->data = 0;
	p1->data = 1;
	p2->data = 2;

	cout << p0->data << endl;
	cout << p0->next->data << endl;
	cout << p1->next->data << endl;
	cout << p1->previous->data;




}

