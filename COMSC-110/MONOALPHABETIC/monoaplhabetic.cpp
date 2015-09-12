#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

string encrypt(string message, string key) {
    for (int i=0; i<message.length(); i++) {
        int index = tolower(message.at(i)) - 'a';
        if (message.at(i) != ' ') message.at(i) = key.at(index);
    }
    return message;
}

string decrypt(string message, string key) {
    for (int i=0; i<message.length(); i++) {
        int index = key.find(tolower(message.at(i)));
        if (message.at(i) != ' ') message.at(i) = 'a' + index;
    }
    return message;
}

int main() {
    ifstream file;
    file.open("key.txt");
    if (file) {
        // Team Name
        // Key (26 character string)
        string line1;
        string line2;
        string teamname;
        string key;
        while (getline(file, line1) && getline(file, line2)) {
            stringstream(line1) >> teamname;
            stringstream(line2) >> key;
        }
        string transfer;
        cout << "Input message: ";
        getline(cin, transfer);
        cout << "Encrypted: " << encrypt(transfer, key) << endl;
    } else {
        cout << "Error" << endl;
    }
    return 0;
}

