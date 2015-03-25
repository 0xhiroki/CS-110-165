/*
    Write a program prompts the user to enter the year
    and month in this order, and display the number of days in the month.
    For example, if the user entered month 2 and year 2004, the program
    should display: February 2004 has 29 days. If the user entered month 3
    and year 2005, the program should display: March 2005 has 31 days.

    You should not use multiple IF statements or switch statement for months.
    Leap year: divisible / 4 except if it divisible / 100.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void Calculate(int month, int year) {
    vector<string> a = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    if (month == 2 && !(year%4) && year%100) {
        cout << a.at(month - 1) << " " << year << " has 29 days." << endl;
    } else {
        cout << a.at(month - 1) << " " << year << " has 31 days." << endl;
    }
}

int main() {
    string transfer;
    int year;
    int month;

    cout << "Input the year and month: ";
    getline(cin, transfer);
    stringstream(transfer) >> year >> month;

    Calculate(month, year);

    return 0;
}
