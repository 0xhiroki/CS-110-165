/***************************************************************
Problem: Project #1 Problem#2
Description: This program will ask the user to input the budget
for his dog house then calculate the house size based on the budget
and displays it.
Name: Hiroki Hori
ID: 1496802
Date: 02/20/2015
Status: complete
****************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

const float COST_PER_SQUARE_FOOT = 10.50;
const float POWER_TO_THE_HALF = 0.50;

const string ENTER_YOUR_BUDGET_PROMPT = "Enter the amount budgeted for your dog house $";
const string LAST_PROMPT_1 = "I can build you a luxurious square dog house \nthat is ";
const string LAST_PROMPR_2 = " feet on each side.";

int main() {
    string transfer;

    float budget;
    float feet;

    cout << ENTER_YOUR_BUDGET_PROMPT;
    getline(cin, transfer);
    stringstream(transfer) >> budget;

    feet = pow(budget / COST_PER_SQUARE_FOOT, POWER_TO_THE_HALF);

    cout << fixed << setprecision(2);
    cout << "For a price of $" << budget << endl << LAST_PROMPT_1 << feet << LAST_PROMPR_2 << endl;

    return 0;
}
