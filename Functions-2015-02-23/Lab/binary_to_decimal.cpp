/*
    #2 Binary to decimal
    Hiroki Hori & Satoru Sasozaki
*/

#include <string>
#include <iostream>

using namespace std;

int bin2Dec(const string& binaryString) {
    int total = 0;
    int base = 1;
    for (int i=binaryString.length() - 1; i>=0; i--) {
        int integer = binaryString.at(i) - '0';
        total += (integer * base);
        base *= 2;
    }
    return total;
}

int main() {
    string transfer;
    cout << "Enter the binary number: ";
    getline(cin, transfer);
    cout << "It's decimal equivalent number is " << bin2Dec(transfer) << endl;
    return 0;
}
