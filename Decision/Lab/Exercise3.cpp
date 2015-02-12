//Lab 4.5 - Option 3
/* This program prompts the user for their residential status and
   whether they require room and board, and outputs their total bill
   for the semester accordingly. */

// Kasra Ferdowsifard and Hiroki Hori
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

//Initializing Constants
const int TUT1 = 3000;
const int TUT2 = 4500;
const int ROOM1 = 2500;
const int ROOM2 = 3500;

int main ()
{
    //declaring variables
    char residency, roomAndBoard;
    string transfer;

    //prompting
    cout << "Please input \"I\" if you are in-state or \"O\" if you are out-of-state:" << endl;
    getline (cin, transfer);
    stringstream (transfer) >> residency;
    residency = toupper(residency);

    cout << endl << "Please input \"Y\" if you require room and board and \"N\" if you do not:" << endl;
    getline (cin, transfer);
    stringstream (transfer) >> roomAndBoard;
    roomAndBoard = toupper(roomAndBoard);

    //outputting the right total
    switch (residency)
    {
    case 'I':
        switch (roomAndBoard)
        {
            case 'Y':
                cout << endl << "Your total bill for this semester is $" << TUT1+ROOM1 << endl;
                break;
            case 'N':
                cout << endl << "Your total bill for this semester is $" << TUT1 << endl;
                break;
        }
        break;

    case 'O':
        switch (roomAndBoard)
        {
            case 'Y':
                cout << endl << "Your total bill for this semester is $" << TUT2+ROOM2 << endl;
                break;
            case 'N':
                cout << endl << "Your total bill for this semester is $" << TUT2 << endl;
                break;
        }
    }
}
