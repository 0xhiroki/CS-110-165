/*
    #1 Palindrome integer
    Hiroki Hori & Satoru Sasozaki
*/

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

// Return the reversal of an integer,
// i.e., reverse(456) returns 654
int reverse(int number) {
    int quotient = number;
    int base = 1;
    int total = 0;

    // Find the first base
    int copied_number = number;
    int index = 0;
    do {
        copied_number /= 10;
        if (index != 0) base *= 10;
        index++;
    } while (copied_number);

    do {
        int remainder = quotient % 10;
        total += (remainder * base);

        base /= 10;
        quotient /= 10;

    } while (quotient);

    return total;
}

// Return true if number is a palindrome
bool isPalindrome(int number) {
    cout << number << " " << reverse(number) << endl;
    if (number == reverse(number)) {
        return true;
    }
    return false;
}

int main() {
    string transfer;
    int number;

    cout << "Enter the number: ";
    getline(cin, transfer);
    stringstream(transfer) >> number;

    if (isPalindrome(number)) {
        cout << "Your number is palindrome." << endl;
    } else {
        cout << "Your number is not palindrome." << endl;
    }

    return 0;
}
