#include <iostream>
#include <string>

using namespace std;

void display(int arg1, double arg2, char arg3)
{
    cout << "Here are the values: "
         << arg1 << " " << arg2 << " "
         << arg3 << endl;
}

int main() {
    int age = 40;
    double income = 100000;
    char initial = 'H';

    cout << "int age: " << age << endl;
    cout << "double income: " << income << endl;
    cout << "char initial: " <<  initial << endl;
    display(age, income, initial);
    return 0;
}
