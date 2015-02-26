#include <iostream>
#include <string>
#include <sstream>

const int MAX_VALUE = 100;

using namespace std;

int main() {
    for (int i=0; i<=MAX_VALUE; i++) {
        cout << i * 10;
        if (i != MAX_VALUE) cout << ", ";
    }
    return 0;
}
