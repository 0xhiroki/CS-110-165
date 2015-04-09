#include <iostream>
#include <string>

using namespace std;

const int SHIFT = 10;

string encrypt(string s) {
    // a->c, z->b
    for (int i=0; i<s.length(); i++) {
        s.at(i) = 'a' + (s.at(i) - 'a' + SHIFT) % 26;
    }
    return s;
}

string decrypt(string s) {
    // b->z, c->a
    for (int i=0; i<s.length(); i++) {
        int k = (s.at(i) - 'a' - SHIFT) > 0 ? (s.at(i) - 'a' - SHIFT) % 26 : (26 + (s.at(i) - 'a' - SHIFT)) % 26;
        s.at(i) = 'a' + k;
    }
    return s;
}

int main() {
    cout << encrypt(decrypt("world")) << endl;
    return 0;
}
