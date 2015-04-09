/*
    1. Account for the space character when decrypting
    2. Encrypt (and later decrypt) messages containing any characters and numbers. [a..z][A..Z][0..9]
    3. Ask the user to input the desired key and operation. (1. encrypt, 2. decrypt)
    4. Encrypt: Use file “message.txt” to read messages to be encrypted, output encrypted lines to screen & file “encrypted.txt”
    5. Decrypt: read from file “encrypted.txt” and output to screen and file “decrypted.txt”
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

const int ALL_NUMBERS = 10; // [0..9]
const int ALL_ALPHABETS = 26; // [a..z] or [A..Z]

string encrypt(string s, int shift) {
    for (int i=0; i<s.length(); i++) {
        if (isdigit(s.at(i))) {
            s.at(i) = '0' + (s.at(i) - '0' + shift) % ALL_NUMBERS;
        } else if (isupper(s.at(i))) {
            s.at(i) = 'A' + (s.at(i) - 'A' + shift) % ALL_ALPHABETS;
        } else {
            if (s.at(i) != ' ') {
                s.at(i) = 'a' + (s.at(i) - 'a' + shift) % ALL_ALPHABETS;
            }
        }
    }
    return s;
}

string decrypt(string s, int shift) {
    for (int i=0; i<s.length(); i++) {
        if (isdigit(s.at(i))) {
            int k = (s.at(i) - '0' - shift) > 0 ? (s.at(i) - '0' - shift) % ALL_NUMBERS : (ALL_NUMBERS + (s.at(i) - '0' - shift)) % ALL_NUMBERS;
            s.at(i) = '0' + k;
        } else if (isupper(s.at(i))) {
            int k = (s.at(i) - 'A' - shift) > 0 ? (s.at(i) - 'A' - shift) % ALL_ALPHABETS : (ALL_ALPHABETS + (s.at(i) - 'A' - shift)) % ALL_ALPHABETS;
            s.at(i) = 'A' + k;
        } else {
            if (s.at(i) != ' ') {
                int k = (s.at(i) - 'a' - shift) > 0 ? (s.at(i) - 'a' - shift) % ALL_ALPHABETS : (ALL_ALPHABETS + (s.at(i) - 'a' - shift)) % ALL_ALPHABETS;
                s.at(i) = 'a' + k;
            }
        }
    }
    return s;
}

int main() {
    string transfer;
    int key;
    char period;
    string operation;
    cout << "Please input the desired key and operation: ";
    getline(cin, transfer);
    stringstream(transfer) >> key >> period >> operation;

    if (operation == "encrypt") {
        ifstream inFile;
        inFile.open("message.txt");
        if (inFile) {
            string line;
            while(getline(inFile, line)) {
                string encrypted = encrypt(line, key);

                // Output to screen
                cout << encrypted << endl;

                // Output to file
                ofstream outFile;
                outFile.open("encrypted.txt");
                if (outFile) {
                    outFile << encrypted << endl;
                    outFile.close();
                }
            }
            inFile.close();
        } else {
            cout << "Error opening file..." << endl;
        }
    } else if (operation == "decrypt") {
        ifstream inFile;
        inFile.open("encrypted.txt");
        if (inFile) {
            string line;
            while(getline(inFile, line)) {
                string decrypted = decrypt(line, key);

                // Output to screen
                cout << decrypted << endl;

                // Output to file
                ofstream outFile;
                outFile.open("decrypted.txt");
                if (outFile) {
                    outFile << decrypted << endl;
                    outFile.close();
                }
            }
            inFile.close();
        } else {
            cout << "Error opening file..." << endl;
        }
    } else {
        cout << "Invalid operation..." << endl;
    }
    return 0;
}
