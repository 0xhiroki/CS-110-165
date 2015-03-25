#include <vector>
#include <iostream>

using namespace std;

// use only push_back(), back(), pop_back() to access elements.

void inQueue(vector<char> &v, char c) {
    vector<char> dummy = {};
    int size = v.size();
    for (int i=0; i<size; i++) {
        dummy.push_back(v.back());
        v.pop_back();
    }

    dummy.push_back(c);

    vector<char> newVec = {};
    size = dummy.size();
    for (int i=0; i<size; i++) {
        newVec.push_back(dummy.back());
        dummy.pop_back();
    }

    v = newVec;
}

void deQueue(vector<char> &v) {
    vector<char> dummy = {};
    int size = v.size();
    for (int i=0; i<size; i++) {
        dummy.push_back(v.back());
        v.pop_back();
    }
    dummy.pop_back();

    vector<char> newVec = {};
    size = dummy.size();
    for (int i=0; i<size; i++) {
        newVec.push_back(dummy.back());
        dummy.pop_back();
    }
    v = newVec;
}

int main() {
    vector<char> vec = {'a', 'b', 'c', 'd', 'e'};

    inQueue(vec, 't');
    deQueue(vec);

    // Debug
    for (char itemRef : vec) {
        cout << itemRef << endl;
    }
    return 0;
}
