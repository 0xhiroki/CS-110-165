//Lab 4.5 - Option 1
/*This program prompts the user for their last 4 quarterly bills,
  and outputs the average monthly water bill, plus a message about
  the amount of water being used. */

// Kasra Ferdowsifard and Hiroki Hori

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

const int TWELVE = 12;
const int FLOOR = 25;
const int CEIL = 75;
const int MIN = 0;

int main ()
{
    //declaring variables
    float bill1, bill2, bill3, bill4;
    double average;
    string transfer;

    //prompts
    cout << "Please input your water bill for quarter 1:" << endl;
    getline (cin, transfer);
    stringstream (transfer) >> bill1;
    cout << endl << "Please input your water bill for quarter 2:" << endl;
    getline (cin, transfer);
    stringstream (transfer) >> bill2;
    cout << endl << "Please input your water bill for quarter 3:" << endl;
    getline (cin, transfer);
    stringstream (transfer) >> bill3;
    cout << endl << "Please input your water bill for quarter 4:" << endl;
    getline (cin, transfer);
    stringstream (transfer) >> bill4;

    //calculations
    average = (bill1+bill2+bill3+bill4)/ TWELVE;

    //output formatting, first output
    cout << fixed << showpoint << setprecision(2) << endl;
    cout << "Your average monthly bill is $" << average << ". ";

    //conditioned output
    if (average > CEIL) {
        cout << "You are using excessive amounts of water" << endl;
    } else if (average > FLOOR){
        cout << "You are using a typical amount of water" << endl;
    } else if (average<FLOOR && average>MIN) {
        cout << "Congratulations! You are conserving water" << endl;
    } else {
        cout << "Error: Invalid Input" << endl;
    }

    return 0;
}
