#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int product;
    string transfer;
    do {
        cout << "Input a number: ";
        getline(cin, transfer);

        int input_from_user;
        stringstream(transfer) >> input_from_user;
        product = input_from_user * 10;
    } while (product < 100);
    return 0;
}
