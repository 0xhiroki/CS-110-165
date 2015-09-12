#include <iostream>
#include <string>

using namespace std;

void timesTen(int number)
{
    cout << number * 10 << endl;
}

int main() {
    cout << "timesTen(4): " << endl;
    timesTen(4);
    return 0;
}
