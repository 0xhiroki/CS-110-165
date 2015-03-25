#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Print 4 5 9 14 23 37 60 97 without using vector, array, or recursion

using namespace std;

int main() {
    int prevTemp = 1;
    int temp = 4;

    cout << temp << endl;
    for (int i=0; i<7; i++) {
        int current = prevTemp + temp;
        cout << current << endl;

        prevTemp = temp;
        temp = current;
    }
    return 0;
}
