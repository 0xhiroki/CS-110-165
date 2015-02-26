#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string transfer;
    int first;
    int second;
    char y_or_n;

    do {
        cout << "Enter two numbers: ";
        getline(cin, transfer);
        stringstream(transfer) >> first >> second;

        int sum = first + second;
        cout << "Total is: " << sum << endl;

        cout << "Do you want to perform the operation again? (Y/N): ";
        getline(cin, transfer);
        stringstream(transfer) >> y_or_n;
    } while (y_or_n == 'Y');
    return 0;
}

