#include <stack>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;

	stack<string> words;
	cout << "Type in a word."
		<< endl
		<< " The word will be printed in reverse order."
		<< endl;

	getline(cin, word);

	words.push(word);
	stack<char> backwards;

	for (int i = 0; i < word.length(); i++)
	{
		char letter = word[i];
		backwards.push(letter);
	}

	while (!backwards.empty()) {
		cout << backwards.top() << " ";
		backwards.pop();
	}

	
	

}