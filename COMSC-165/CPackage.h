/***************************************************************
 Problem: Lab - Making Decisions: Internet Service Provider
 Description: This program asks the user to input package name, hours, and month, and then calculate the bill.
 It also displays the possible savings if the user changed the plan to another one.
 Name: Hiroki Hori
 ID: 1496802
 Date: 09/06/2015
 Status: complete
 ****************************************************************/

#ifndef __sampleCplusplus__CPackage__
#define __sampleCplusplus__CPackage__

#include <stdio.h>
#include <string>

using namespace std;

class CPackage {
private:
    char packageName_;
public:
    CPackage();
    CPackage(char);
    void setPackageName(char);
    char getPackageName();
    bool isValidPackageName();
    bool isValidHours(int, string);
    double calculateBill(int);
    void showSavings(int);
};

#endif /* defined(__sampleCplusplus__CPackage__) */
