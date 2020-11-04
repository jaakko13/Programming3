#include <iostream>


using namespace std;


int bought(int price, int stock);
int sold(int price, int stock);

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


int main() {

	stack_nodeChain<int> capital;


	int purchasedStock = 100;
	int janPrice = 10;
	int aprPrice = 30;
	int junPrice = 20;
	int sepPrice = 50;
	int novPrice = 30;
	int totalMoney = 0;


	cout << "Buy stock in January." << endl;
	capital.push(bought(janPrice, purchasedStock));

	cout << "Buy stock in April." << endl;
	capital.push(bought(aprPrice, purchasedStock));

	cout << "Sell stock in June." << endl;
	capital.push(sold(junPrice, purchasedStock));

	cout << "Buy stock in September." << endl;
	capital.push(bought(sepPrice, purchasedStock));

	cout << "Sell stock in November." << endl;
	capital.push(sold(novPrice, purchasedStock));

	while (!capital.empty())
	{
		totalMoney += capital.top();
		capital.pop();
	}

	if (totalMoney > 0)
	{
		cout << "Your total capital gain is " << totalMoney << ".";
	}
	else if (totalMoney < 0)
	{
		cout << "Your total capital loss is " << totalMoney << ".";
	}
	else
	{
		cout << "You did not gain or lose money.";
	}
}

int bought(int price, int stock) {
	int totalCost = -price * stock;
	return totalCost;
}

int sold(int price, int stock) {
	int totalProfit = price * stock;
	return totalProfit;
}
