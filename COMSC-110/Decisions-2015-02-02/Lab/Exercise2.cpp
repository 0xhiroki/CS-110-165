/*
    Lab 4.5 option2
    Hiroki Hori and Kasra Ferdowsifard
*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

const int FIVE = 5;
const int ELEVEN = 11;
const int TWENTY_ONE = 21;
const int THIRTY_ONE = 31;

const float DISC1 = 0.90;
const float DISC2 = 0.85;
const float DISC3 = 0.80;
const float DISC4 = 0.75;

const int TWELVE = 12;

int main() {

    int shirts;
    float cost;
    float total;
    string transfer;

    cout << "How many shirts would you like ?" << endl;
    getline(cin, transfer);
    stringstream(transfer) >> shirts;

    if (shirts >= 0) {
        if (shirts < FIVE) {
            cost = TWELVE;
        } else if (shirts < ELEVEN) {
            cost = TWELVE * DISC1;
            cout << fixed << showpoint << setprecision(2);
        } else if (shirts < TWENTY_ONE) {
            cost = TWELVE * DISC2;
            cout << fixed << showpoint << setprecision(2);
        } else if (shirts < THIRTY_ONE) {
            cost = TWELVE * DISC3;
            cout << fixed << showpoint << setprecision(2);
        } else {
            cost = TWELVE * DISC4;
            cout << fixed << showpoint << setprecision(2);
        }
        total = cost * shirts;
        cout << endl << "The cost per shirts $" << cost << " and the total cost is $" << total << endl;
    } else {
        cout << "Please input a nonnegative integer." << endl;
    }

    return 0;
}
