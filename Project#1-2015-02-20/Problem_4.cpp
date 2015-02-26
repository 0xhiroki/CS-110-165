/***************************************************************
Problem: Project #1 Problem#4
Description: This program will ask the user to input his income then
calculate the tax according to the rate schedule, and displays it.
(using if/else statement)
Name: Hiroki Hori
ID: 1496802
Date: 02/20/2015
Status: complete
****************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

const int NO_TAX_MAXIMUM = 15000;
const int TEN_PERCENT_TAX_MINIMUM = 25000;

const float FIVE_PERCENT_TAX = 0.05;
const float TEN_PERCENT_TAX = 0.10;

int main() {
    string transfer;
    float income;
    float tax;

    cout << "Enter net income (rounded to whole dollars) $";
    getline(cin, transfer);
    stringstream(transfer) >> income;

    if (income <= NO_TAX_MAXIMUM) {
        tax = 0;
    } else if (income <= TEN_PERCENT_TAX_MINIMUM) {
        tax = (income - NO_TAX_MAXIMUM) * FIVE_PERCENT_TAX;
    } else {
        tax = (income - TEN_PERCENT_TAX_MINIMUM) * TEN_PERCENT_TAX + (TEN_PERCENT_TAX_MINIMUM - NO_TAX_MAXIMUM) * FIVE_PERCENT_TAX;
    }

    cout << fixed << setprecision(2);
    cout << "Net income = " << "$" << income << endl;
    cout << "Tax bill = $" << tax << endl;

    return 0;
}

