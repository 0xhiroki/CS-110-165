#include <iostream>
#include <string>

using namespace std;

float half(float number)
{
    return number / 2.0;
}

int main() {
    float number = 10.4;
    cout << "number: " << number << endl;
    float result = half(number);
    cout << "result: " << result << endl;
    return 0;
}
