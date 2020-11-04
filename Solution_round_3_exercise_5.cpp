#include <iostream>
#include<stack>
using namespace std;

typedef char Stack_entry;
const int maxstack = 100;

enum Error_code {
    success, fail, utility_range_error, underflow, overflow, fatal,
    not_present, duplicate_error, entry_inserted, entry_found,
    internal_error
};

class Extended_stack {
public:
    Extended_stack();
    Error_code pop();
    Error_code push(const Stack_entry& item);   
    Error_code top(Stack_entry& item) const;
    bool empty() const;
    void clear(); // Reset the stack to be empty.
    bool full() const; // If the stack is full, 
                         // return true; else return false.
    int size() const; // Return the number of entries 
                       // in the stack.

private:
    int count;

    Stack_entry entry[maxstack];
};


int main() {
    int x;
    Extended_stack source;
    cout << "Size of stack: " << source.size() << endl;

    cout << "Enter a number to put in the stack:";
    cin >> x;
    source.push(x);
    cout << endl << "Size of stack: " << source.size() << endl;

    cout << "Now the stack will be cleared. And the size will be shown again.";
    source.clear();
    cout << endl << "Size of stack: " << source.size() << endl;


    if (source.full() == 0)
    {
        cout << "The stack is NOT full.";
    }
    else if (source.full() == 1)
    {
        cout << "The stack is full.";
    }


}


void Extended_stack::clear() {
    memset(entry, 0, sizeof entry);
    count = 0;
}

bool Extended_stack::full() const {
    return(count >= maxstack) ? true : false;
}

int Extended_stack::size() const {
    return count;
}





Error_code Extended_stack::push(const Stack_entry& item)
/* Pre: None.
Post: If the Stack is not full, item is added to the top of the Stack. If the Stack is
full, an Error code of overflow is returned and the Stack is left unchanged.
*/
{
    Error_code outcome = success;
    if (count >= maxstack)
        outcome = overflow;
    else
        entry[count++] = item;
    return outcome;
}

Error_code Extended_stack::pop()
/* Pre: None.
Post: If the Stack is not empty, the top of the Stack is removed. If the Stack is
empty, an Error code of underflow is returned. */
{
    Error_code outcome = success;
    if (count == 0)
        outcome = underflow;
    else --count;
    return outcome;
}

Error_code Extended_stack::top(Stack_entry& item) const
/* Pre: None.
Post: If the Stack is not empty, the top of the Stack is returned in item. If the Stack
is empty an Error code of underflow is returned. */
{
    Error_code outcome = success;
    if (count == 0)
        outcome = underflow;
    else
        item = entry[count - 1];
    return outcome;
}

bool Extended_stack::empty() const
/* Pre: None.
Post: If the Stack is empty, true is returned. Otherwise false is returned. */
{
    bool outcome = true;
    if (count > 0) outcome = false;
    return outcome;
}
Extended_stack::Extended_stack()
/* Pre: None.
Post: The stack is initialized to be empty. */
{
    count = 0;
}