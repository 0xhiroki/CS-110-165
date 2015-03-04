#include <iostream>
#include <string>

using namespace std;

int cube(int num) {
    return num * num * num;
}

int main() {
    int result = cube(4);
    cout << "int result = cube(4)" << endl;
    cout << "result: " << result << endl;
    return 0;
}
