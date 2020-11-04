#include <iostream>
#include <conio.h>
using namespace std;



void instructions();
bool user_says_yes();
const int getRow();
int getCol();


bool whilesucks(char c) {
    if (c == 'X' || c == ' ')
    {
        return true;

    }
    else
    {
        cout << "NO!";
        return false;
    }
}



class Life {
public:
    void initialize();
    void print();
    void update();
    void neighbor_count();

private:
    int maxrow = 20, maxcol = 60;

    int grid[20 + 2][60 + 2];  //  allows for two extra rows and columns
    int neighbor_count(int row, int col);


};



int main()  //  Program to play Conway's game of Life.
/*
Pre:  The user supplies an initial configuration of living cells.
Post: The program prints a sequence of pictures showing the changes in
      the configuration of living cells according to the rules for
      the game of Life.
Uses: The class Life and its methods initialize(), print(), and update().
      The functions  instructions(),  user_says_yes().
*/

{

    Life configuration;
    instructions();
    configuration.initialize();
    configuration.print();
    cout << "Continue viewing new generations? " << endl;
    while (user_says_yes()) {
        configuration.update();
        configuration.print();
        cout << "Continue viewing new generations? " << endl;
    }


}


const int getRow() {
    int row;
    cout << "Enter the number of rows you would like:";
    cin >> row;
    return row;
}

int getCol() {
    int col;
    cout << "Enter the number of columns you would like:";
    cin >> col;
    return col;
}


void Life::initialize()
/*
Pre:  None.
Post: The Life object contains a configuration specified by the user.
*/

{
    cout << "Would you like to change the size of the grid?";
    if (user_says_yes())
    {
        cout << "Enter row:";
        cin >> maxrow;
        while (maxrow < 1 || maxrow > 20) { // makes sure input is between max parameteres
            cout << "Enter row:";
            cin >> maxrow;
        }
        cout << "Enter col:";
        cin >> maxcol;
        while (maxcol < 1 || maxcol > 60) {// makes sure input is between max parameteres
            cout << "Enter col:";
            cin >> maxcol;
        }
    }

    /*
    int row, col;
    for (row = 0; row <= maxrow + 1; row++)
        for (col = 0; col <= maxcol + 1; col++)
            grid[row][col] = 0;
    cout << "List the coordinates for living cells." << endl;
    cout << "Terminate the list with the special pair -1 -1" << endl;
    cin >> row >> col;

    while (row != -1 || col != -1) {
        if (row >= 1 && row <= maxrow)
            if (col >= 1 && col <= maxcol)
                grid[row][col] = 1;
            else
                cout << "Column " << col << " is out of range." << endl;
        else
            cout << "Row " << row << " is out of range." << endl;
        cin >> row >> col;
    }
    
    */


    char c;

    cout << "Only use X or space" << endl;
    for (int row = 0; row < maxrow; row++)
    {
        cout << endl << row + 1 << '.';
        for (int col = 0; col < maxcol; col++)
        {
            do
            {
                c = _getch();
                cout << c;
                c = toupper(c);
            } while (!whilesucks(c));
            if (c == 'X')
            {
                grid[row][col] = 1;
            }
            else
            {
                grid[row][col] = 0;
            }
        }
    }


}


void Life::print()
/*
Pre:  The Life object contains a configuration.
Post: The configuration is written for the user.
*/

{
    int row, col;
    cout << "\nThe current Life configuration is:" << endl;
    for (row = 1; row <= maxrow; row++) {
        for (col = 1; col <= maxcol; col++)
            if (grid[row][col] == 1) cout << '*';
            else cout << ' ';
        cout << endl;
    }
    cout << endl;
}


void Life::update()
/*
Pre:  The Life object contains a configuration.
Post: The Life object contains the next generation of configuration.
*/

{
    int row, col;
    int new_grid[20 + 2][60 + 2];

    for (row = 1; row <= maxrow; row++)
        for (col = 1; col <= maxcol; col++)
            switch (neighbor_count(row, col)) {
            case 2:
                new_grid[row][col] = grid[row][col];  //  Status stays the same.
                break;
            case 3:
                new_grid[row][col] = 1;                //  Cell is now alive.
                break;
            default:
                new_grid[row][col] = 0;                //  Cell is now dead.
            };
    for (row = 1; row <= maxrow; row++)
        for (col = 1; col <= maxcol; col++)
            grid[row][col] = new_grid[row][col];
};


void instructions()
/*
Pre:  None.
Post: Instructions for using the Life program have been printed.
*/

{
    cout << "Welcome to Conway's game of Life." << endl;
    cout << "This game uses a grid of size 20 by 60 in which" << endl;
    cout << "each cell can either be occupied by an organism or not." << endl;
    cout << "The occupied cells change from generation to generation" << endl;
    cout << "according to the number of neighboring cells which are alive."
        << endl;
}


bool user_says_yes()
{
    int c;
    bool initial_response = true;

    do {  //  Loop until an appropriate input is received.
        if (initial_response)
            cout << " (y,n)? " << flush;

        else
            cout << "Respond with either y or n: " << flush;

        do { //  Ignore white space.
            c = cin.get();
        } while (c == '\n' || c == ' ' || c == '\t');
        initial_response = false;
    } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
    return (c == 'y' || c == 'Y');
}

int Life::neighbor_count(int row, int col)
/*
Pre:  The Life object contains a configuration, and the coordinates
      row and col define a cell inside its hedge.
Post: The number of living neighbors of the specified cell is returned.
*/

{
    int i, j;
    int count = 0;
    for (i = row - 1; i <= row + 1; i++)
        for (j = col - 1; j <= col + 1; j++)
            count += grid[i][j];  //  Increase the count if neighbor is alive.
    count -= grid[row][col]; //  Reduce count, since cell is not its own neighbor.
    return count;
}

