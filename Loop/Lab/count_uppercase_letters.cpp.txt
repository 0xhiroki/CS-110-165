/*
    Lab Part 1
    #3 Count uppercase letters
    Hiroki Hori & Satoru Sasozaki
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

const string PROMPT_FIRST = "Enter a string: ";
const string PROMPT_LAST = "The number of uppercase letters is ";

int main() {
    string transfer;
    int counter = 0;

    cout << PROMPT_FIRST;
    getline(cin, transfer);

    for (int i=0; i<transfer.length(); i++) {
        char c = transfer.at(i);
        if (isupper(c)) {
            counter++;
        }
    }
    cout << endl << PROMPT_LAST << counter << endl;
    return 0;
}
