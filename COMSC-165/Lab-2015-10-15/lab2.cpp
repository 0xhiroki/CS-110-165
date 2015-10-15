/***************************************************************
Problem: Lab2
Description: This program defines a function which takes two vector arguments and then
adds the elements of one vector to the elements of another.
Name: Hiroki Hori
ID: 1496802
Date: 10/15/2015
Status: complete
****************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void f(vector<int> &v1, const vector<int> &v2) {
    if (v1.size() >= v2.size()) {
        for (int i=0; i<v2.size(); i++) {
            v1.at(i) += v2.at(i);
        }
    } else {
        for (int i=0; i<v1.size(); i++) {
            v1.at(i) += v2.at(i);
        }
    }
}

int main() {
    vector<int> v1 = {1, 2, 3, 4, 4, 5};
    vector<int> v2 = {2, 3, 4, 5, 6};
    f(v1, v2);

    for (int elem : v1) {
        cout << elem << endl;
    }
    return 0;
}
