#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string transfer;
    int total = 0;

    for (int i=0; i<10; i++) {
        cout << "Input a number: ";
        getline(cin, transfer);
        int number;
        stringstream(transfer) >> number;
        total += number;
    }

    cout << "Running total is: " << total << endl;

    return 0;
}

