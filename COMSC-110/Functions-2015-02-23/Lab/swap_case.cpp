/*
    #3 Swap case
    Hiroki Hori & Satoru Sasozaki
*/

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

string swapCase(const string& s) {
    string total;
    for (int i = 0; i<s.length(); i++) {
        char c = s.at(i);
        if (isupper(c)) {
            total+=tolower(c);
        } else{
            total+=toupper(c);
        }
    }
    return total;
}

int main() {
    string transfer;
    cout << "Enter string: ";
    getline(cin, transfer);
    cout << "The new string is: " << swapCase(transfer) << endl;
    return 0;
}
