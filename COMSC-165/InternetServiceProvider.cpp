/***************************************************************
 Problem: Lab - Making Decisions: Internet Service Provider
 Description: This program asks the user to input package name, hours, and month, and then calculate the bill.
 It also displays the possible savings if the user changed the plan to another one.
 Name: Hiroki Hori
 ID: 1496802
 Date: 09/06/2015
 Status: complete
 ****************************************************************/

#include <iostream>
#include <string>
#include <sstream>

#include "CPackage.h"

using namespace std;

int main() {
    string transfer;
    
    // PackageName prompt
    char packageName;
    cout << "Which package did you purchase?: ";
    getline(cin, transfer);
    stringstream(transfer) >> packageName;
    
    CPackage pObj = CPackage(packageName);
    if (pObj.isValidPackageName()) {
        // Hours prompt
        int hours;
        cout << "How many hours were used?: ";
        getline(cin, transfer);
        stringstream(transfer) >> hours;
        
        // Month prompt
        cout << "In which month?: ";
        getline(cin, transfer);
        
        // Hours validation based on the month given
        if (pObj.isValidHours(hours, transfer)) {
            double bill = pObj.calculateBill(hours);
            cout << "Your bill is: $" << bill << endl;
            pObj.showSavings(hours);
        } else {
            cout << "Invalid hours... Please input the valid hours." << endl;
        }
    } else {
        cout << "Invalid Package..." << endl;
    }
    
    return 0;
}
