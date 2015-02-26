/***************************************************************
Problem: Project #1 Problem#1
Description: This program will ask the user to input hours and minutes
of his consultation and then calculates the bill and displays it.
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

const int QUARTER_HOUR_IN_MINUTE = 15;
const float QUARTER_HOUR = 0.25;
const int FIXED_RATE = 150;

int main() {
    string transfer;
    int hour;
    int minute;
    float bill;

    cout << "Thank you for choosing us!" << endl;
    cout << "The layers with a heart" << endl;

    cout << "Input the hours and minutes of your consultation: ";
    getline(cin, transfer);
    stringstream(transfer) >> hour >> minute;

    bill = (hour + (minute/QUARTER_HOUR_IN_MINUTE) * QUARTER_HOUR ) * FIXED_RATE;

    cout << fixed << showpoint << setprecision(1);
    cout << "For " << hour << " hours and " << minute << " minutes, your bill is $" << bill << endl;

    return 0;
}
