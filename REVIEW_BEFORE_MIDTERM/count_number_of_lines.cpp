#include <iostream>
#include <fstream>

using namespace std;

int CountNumberOfLines(fstream &inFile) {
    string line;
    int counter = 0;
    while (getline(inFile, line)) {
        counter++;
    }
    return counter;
}

int main() {
    fstream inFile("sample.txt", ios::in);
    if (!inFile.fail()) {
        cout << "Number of lines: " << CountNumberOfLines(inFile) << endl;
    } else {
        cout << "Error opening..." << endl;
    }
    return 0;
}
