#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void getNumber(int& number)
{
    string transfer;
    int inputValue;
    cout << "Enter a number from 1 to 100: ";
    getline(cin, transfer);
    stringstream(transfer) >> inputValue;

    if (inputValue >= 1 && inputValue <= 100) {
        number = inputValue;
    } else {
        cout << "The input number is not in the range of 1 through 100." << endl;
    }
}

int main() {
    int number = 10;
    cout << "number before: " << number << endl;
    getNumber(number);
    cout << "number after: " << number << endl;
    return 0;
}
