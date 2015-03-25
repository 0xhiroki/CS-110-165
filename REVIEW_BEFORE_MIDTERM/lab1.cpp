// Find the sum of
// 1/3 + 3/5 + 5/7 + ... + 97/99

#include <iostream>

using namespace std;

int main() {
    double total = 0;
    for (int i=1; i<=97; i+=2 ) {
        total += i / (i+2.0);
    }
    cout << total << endl;
    return 0;
}
