/*
    #4 Phone keypads
    Hiroki Hori & Satoru Sasozaki
*/

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int getNumber(char uppercaseLetter) {
    uppercaseLetter = toupper(uppercaseLetter);

    int v = uppercaseLetter - 'A';

    if (uppercaseLetter >= 'A' && uppercaseLetter <= 'C') {
        return 2;
    } else if (uppercaseLetter >= 'D' && uppercaseLetter <= 'F') {
        return 3;
    } else if (uppercaseLetter >= 'G' && uppercaseLetter <= 'I') {
        return 4;
    } else if (uppercaseLetter >= 'J' && uppercaseLetter <= 'L') {
        return 5;
    } else if (uppercaseLetter >= 'M' && uppercaseLetter <= 'O') {
        return 6;
    } else if (uppercaseLetter >= 'P' && uppercaseLetter <= 'S') {
        return 7;
    } else if (uppercaseLetter >= 'T' && uppercaseLetter <= 'V') {
        return 8;
    } else if (uppercaseLetter >= 'W' && uppercaseLetter <= 'Z') {
        return 9;
    }
}

int main() {
    string transfer;
    string total;
    cout << "Enter the phone number: ";
    getline(cin, transfer);

    for (int i=0; i<transfer.length(); i++) {
        char c = transfer.at(i);
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            char b = getNumber(c) + '0';
            total += b;
        } else {
            total += c;
        }
    }
    cout << total << endl;
    return 0;
}
