#include <iostream>
#include <string>

using namespace std;

const int SHIFT = 10;
const int ALL_ALPHABETS = 26;

string encrypt(string s) {
    for (int i=0; i<s.length(); i++) {
        s.at(i) = 'a' + (s.at(i) - 'a' + SHIFT) % ALL_ALPHABETS;
    }
    return s;
}

string decrypt(string s) {
    for (int i=0; i<s.length(); i++) {
        int k = (s.at(i) - 'a' - SHIFT) > 0 ? (s.at(i) - 'a' - SHIFT) % ALL_ALPHABETS : (ALL_ALPHABETS + (s.at(i) - 'a' - SHIFT)) % ALL_ALPHABETS;
        s.at(i) = 'a' + k;
    }
    return s;
}

int main() {
    cout << encrypt("hello there everyone how are you doing") << endl;
    return 0;
}
