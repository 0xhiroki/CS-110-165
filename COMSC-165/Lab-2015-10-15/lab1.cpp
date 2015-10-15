/***************************************************************
Problem: Lab1
Description: This program defines a function f which takes a vector argument,
and then copies the element of the passed vector into local vector and prints its each element.
Name: Hiroki Hori
ID: 1496802
Date: 10/15/2015
Status: complete
****************************************************************/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void f(const vector<int> &v) {
    vector<int> lv(v.size());
    for (int i=0; i<v.size(); i++) {
        lv.at(i) = v.at(i);
    }

    for (int elem : lv) {
        cout << elem << endl;
    }

    cout << endl;

    vector<int> lv2(v);
    for (int elem : lv2) {
        cout << elem << endl;
    }

    cout << endl;
}

int getFactorial(int n) {
    int v = 1;
    if (n > 1) {
        do {
            v *= n;
        } while(--n != 0);
    }
    return v;
}

int main() {
    vector<int> gv(10);
    for (int i=0; i<gv.size(); i++) {
        gv.at(i) = pow(2, i);
    }
    f(gv);

    vector<int> vv(10);
    for (int i=1; i<=vv.size(); i++) {
        vv.at(i-1) = getFactorial(i);
    }
    f(vv);

    return 0;
}
