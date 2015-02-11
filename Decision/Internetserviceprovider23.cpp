/***************************************************************
Problem: Assignment 23 & 24
Description: "This program will ask the user
to input which package the customer has purchased
and how many hours were used.
Then it calculates and displays the total amount due
and possible saving amount in case the user purchases other package."
Name: Hiroki Hori
ID: 1496802
Date: 02/05/2015
Status: complete
****************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

const float PACKAGE_A = 9.95;
const float PACKAGE_B = 14.95;
const float PACKAGE_C = 19.95;

const float HOURS_A = 10;
const float HOURS_B = 20;

const float EXTRA_COST_PER_HOUR_A = 2.00;
const float EXTRA_COST_PER_HOUR_B = 1.00;

const int MAX_HOURS = 744;

const string DEFAULT_MESSAGE = "Your total amount due is $";
const string INVALID_PACKAGE_MESSAGE = "Please choose from 'A', 'B', or 'C' for your package.";
const string INVALID_HOURS_MESSAGE = "Your hours is invalid. It cannot exceed 744 and cannot be negative.";
const string TIPS_FOR_PACKAGE_B_MESSAGE = "If you switch to B, you can save $";
const string TIPS_FOR_PACKAGE_C_MESSAGE = "If you switch to C, you can save $";

int main() {
    string transfer;
    char package;
    int hours;
    float totalA;
    float totalB;
    float totalC;

    // Prompt for package
    cout << "Which package have you got?" << endl;
    getline(cin, transfer);
    stringstream(transfer) >> package;

    // Prompt for hours
    cout << endl << "How many hours were used?" << endl;
    getline(cin, transfer);
    stringstream(transfer) >> hours;

    if (hours >= 0 && hours <= MAX_HOURS) {
        // Be kind enough to convert lower case to upper case
        package = toupper(package);

        // Package switch statement
        switch(package) {
            case 'A':
                totalA = hours > HOURS_A ? PACKAGE_A + (hours - HOURS_A) * EXTRA_COST_PER_HOUR_A : PACKAGE_A;
                totalB = hours > HOURS_B ? PACKAGE_B + (hours - HOURS_B) * EXTRA_COST_PER_HOUR_B : PACKAGE_B;
                totalC = PACKAGE_C;

                cout << endl << DEFAULT_MESSAGE << totalA << endl;
                if (totalA - totalB > 0) cout << TIPS_FOR_PACKAGE_B_MESSAGE << totalA - totalB << endl;
                if (totalA - totalC > 0) cout << TIPS_FOR_PACKAGE_C_MESSAGE << totalA - totalC << endl;

                break;
            case 'B':
                totalB = hours > HOURS_B ? PACKAGE_B + (hours - HOURS_B) * EXTRA_COST_PER_HOUR_B : PACKAGE_B;
                totalC = PACKAGE_C;

                cout << endl << DEFAULT_MESSAGE << totalB << endl;
                if (totalB - totalC > 0) cout << TIPS_FOR_PACKAGE_C_MESSAGE << totalB - totalC << endl;

                break;
            case 'C':
                totalC = PACKAGE_C;
                cout << endl << DEFAULT_MESSAGE << totalC << endl;
                break;
            default:
                cout << endl << INVALID_PACKAGE_MESSAGE << endl;
                break;
        }
    } else {
        cout << endl << INVALID_HOURS_MESSAGE << endl;
    }

    return 0;
}
