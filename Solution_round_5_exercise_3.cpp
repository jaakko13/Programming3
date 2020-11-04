#include <iostream>
#include <queue>
#include <stack>

using namespace std;


int bought(int price, int stock);
int sold(int price, int stock);

int main() {

	/*
	queue<int> capital;


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
		totalMoney += capital.front();
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
	*/


	stack<int> capital;


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
