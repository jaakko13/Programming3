/* Program extracts from Chapter 3 of
   "Data Structures and Program Design in C++"
   by Robert L. Kruse and Alexander J. Ryba
   Copyright (C) 1999 by Prentice-Hall, Inc.  All rights reserved.
   Extracts from this file may be used in the construction of other programs,
   but this code will not compile or execute as given here. */


   // Section 3.1:


#include <iostream>
using namespace std;

typedef int Queue_entry;

void introduction();
char get_command();
void help();

enum Error_code {
    success, fail, utility_range_error, underflow, overflow, fatal,
    not_present, duplicate_error, entry_inserted, entry_found,
    internal_error
};





const int maxqueue = 10;


class Queue {
public:
    Queue();
    bool empty() const;
    Error_code serve();
    Error_code append(const Queue_entry &item);
    Error_code retrieve(Queue_entry &item) const;
protected:
    int count;
    int front, rear;
    Queue_entry entry[maxqueue];
};

class Extended_queue : public Queue {
public:
    bool full() const;
    int size() const;
    void clear();
    Error_code serve_and_retrieve(Queue_entry& item);
};

Queue::Queue()
{
    count = 0;
    rear = maxqueue - 1;
    front = 0;
}
bool Queue :: empty() const
{
    return count == 0;
}

//Its here bc it only wokrs after the extended_queue class
bool do_command(char c, Extended_queue& test_queue);


Error_code Queue::append(const Queue_entry& item)
/*
Post: item is added to the rear of the Queue. If the Queue is full
return an Error_code of overflow and leave the Queue unchanged.
*/

{
    if (count >= maxqueue) return overflow;
    count++;
    rear = ((rear + 1) == maxqueue) ? 0 : (rear + 1);
    entry[rear] = item;
    return success;
}

Error_code Queue::serve()
/*
Post: The front of the Queue is removed. If the Queue
is empty return an Error_code of underflow.
*/

{
    if (count <= 0) return underflow;
    count--;
    front = ((front + 1) == maxqueue) ? 0 : (front + 1);
    return success;
}

Error_code Queue::retrieve(Queue_entry& item) const
/*
Post: The front of the Queue retrieved to the output
      parameter item. If the Queue is empty return an Error_code of underflow.
*/

{
    if (count <= 0) return underflow;
    item = entry[front];
    return success;
}


int Extended_queue::size() const
/*
Post:   Return the number of entries in the Extended_queue.
*/
{
    return count;
}









int main()
/* Post: Accepts commands from user as a menu-driven demonstration program for the
class Extended queue.
Uses: The class Extended queue; the functions introduction, get command,
and do command. */
{
    Extended_queue test_queue;
    introduction();
    while (do_command(get_command(), test_queue));
}




void introduction() {
    help();
}


void help()
/* Post: A help screen for the program is printed, giving the meaning of each command
that the user may enter. */
{
    cout << endl
        << "This program allows the user to enter one command" << endl
        << "(but only one) on each input line." << endl
        << "For example, if the command S is entered, then" << endl
        << "the program will serve the front of the queue." << endl
        << endl
        << " The valid commands are:" << endl
        << "A − Append the next input character to the extended queue"
        << endl
        << "S − Serve the front of the extended queue" << endl
        << "R − Retrieve and print the front entry." << endl
        << "# − The current size of the extended queue" << endl
        << "C − Clear the extended queue (same as delete)" << endl
        << "P − Print the extended queue" << endl
        << "H − This help screen" << endl
        << "Q − Quit" << endl
        << "Press < Enter > to continue." << flush;
    char c;
    do {
        cin.get(c);
    } while (c != '\n');
}

char get_command() {
    char c;
    cout << "Enter a character:";
    cin >> c;

    return c;
}


bool do_command(char c, Extended_queue &test_queue)
/* Pre: c represents a valid command.
Post: Performs the given command c on the Extended queue test queue. Returns false if c == 0
q0
, otherwise returns true.
Uses: The class Extended queue. */
{
    bool continue_input = true;
    Queue_entry x;
    switch (c) {
    case 'a':
        cout << "Enter a value to append:" << endl;
        cin >> x;
        test_queue.append(x);
        break;
    case 'p':
        while (test_queue.retrieve(x) != underflow)
        {
            cout << x << endl;
            test_queue.serve();
        }
        break;
    case 's':
        test_queue.serve();
        cout << "Front has been deleted.";
        break;
    case '#':
        cout << "The size of the queue is " << test_queue.size() << endl;
        break;
    case 'c':
        while (test_queue.retrieve(x) != underflow)
        {
            test_queue.serve();
        }
        cout << "The queue has been deleted.";
        break;
    case 'h':
        help();
        break;
    case 'r':
        if (test_queue.retrieve(x) == underflow)
            cout << "Queue is empty." << endl;
        else
            cout << endl
            << "The first entry is: " << x
            << endl;
        break;
    case 'q':
        cout << "Extended queue demonstration finished." << endl;
        continue_input = false;
        break;
        //  Additional cases will cover other commands.
    }
    return continue_input;
}