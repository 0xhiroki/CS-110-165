/*
    Write a function that finds and returns the
    smallest element in an array of numbers it
    receives (write appropriate parameters accordingly.)
*/

#include <iostream>
#include <vector>

using namespace std;

int FindSmallest(const vector<int> &numbers) {
    int temp = 0;
    if (!numbers.empty()) {
            temp = numbers.at(0);
            for (int itemRef : numbers) {
                temp = itemRef < temp ? itemRef : temp;
            }
    }
    return temp;
}

int main() {
    vector<int> numbers = {5, 3, 3, 4, 5, 6, 7, 8, 9};
    cout << "Smallest number of an array: " << FindSmallest(numbers) << endl;
    return 0;
}
