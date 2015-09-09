/***************************************************************
 Problem: Lab - Making Decisions: Internet Service Provider
 Description: This program asks the user to input package name, hours, and month, and then calculate the bill.
 It also displays the possible savings if the user changed the plan to another one.
 Name: Hiroki Hori
 ID: 1496802
 Date: 09/06/2015
 Status: complete
 ****************************************************************/

#include "CPackage.h"

#include <iostream>
#include <vector>
#include <cctype>

const vector<string> MONTHS = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
const vector<int> DAYS_IN_MONTH = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

CPackage::CPackage(char packageName) {
    packageName_ = packageName;
}

CPackage::CPackage() {
}

void CPackage::setPackageName(char packageName) {
    packageName_ = packageName;
}

char CPackage::getPackageName() {
    return packageName_;
}

bool CPackage::isValidPackageName() {
    char lowerP = tolower(packageName_);
    return lowerP == 'a' || lowerP == 'b' || lowerP == 'c';
}

bool CPackage::isValidHours(int hours, string month) {
    // To Lower
    for (int i=0; i<month.size(); i++) {
        month.at(i) = tolower(month.at(i));
    }
    
    // Find the month index
    int index = 0;
    bool found = false;
    for (int i=0; i<MONTHS.size() && !found; i++) {
        if (month == MONTHS.at(i)) {
            found = true;
            index = i;
        }
    }
    
    // Check if the given hour is valid
    bool isValid = false;
    if (found) {
        int days = DAYS_IN_MONTH.at(index);
        int maximumHours = days * 24;
        if (maximumHours >= hours) {
            isValid = true;
        }
    }
    
    return isValid;
}

double CPackage::calculateBill(int hours) {
    double base = 0.0;
    double additional = 0.0;
    int maximumHours = 0;
    switch (tolower(packageName_)) {
        case 'a':
            maximumHours = 10;
            base = 9.95;
            if (hours > maximumHours) {
                additional = 2.0*(hours-maximumHours);
            }
            break;
        case 'b':
            maximumHours = 20;
            base = 14.95;
            if (hours > maximumHours) {
                additional = 1.0*(hours - maximumHours);
            }
            break;
        case 'c':
            base = 19.95;
            break;
        default:
            break;
    }
    
    return base + additional;
}

void CPackage::showSavings(int hours) {
    switch (this->packageName_) {
        case 'a': {
            // B
            CPackage pObjB = CPackage('b');
            cout << "If you purchased package 'B', you can save $" << this->calculateBill(hours) - pObjB.calculateBill(hours) << "." <<endl;
            
            // C
            CPackage pObjC = CPackage('c');
            cout << "If you purchased package 'C', you can save $" << this->calculateBill(hours) - pObjC.calculateBill(hours) << "." <<endl;
        }
            break;
        case 'b': {
            // C
            CPackage pObjC = CPackage('c');
            cout << "If you purchased package 'C', you can save $" << this->calculateBill(hours) - pObjC.calculateBill(hours) << "." <<endl;
        }
            break;
        default:
            break;
    }
}
