#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <sstream>
#include <vector>

/*
    Count the number of appearance of each keyword.
*/

using namespace std;

int word_count(string line, string keyword) {
    int counter = 0;
    stringstream as;
    for (int i=0; i<line.size(); i++) {
        if ( !isalpha(line.at(i)) ) line.at(i) = ' ';
    }

    as << line;
    string s;
    while (as >> s) {
        if (s == keyword) counter++;
    }

    return counter;
}

int main() {

    vector<string> k = {"int", "bool", "double", "long", "while", "for", "void", "static", "else", "if", "case", "return"};
    vector<int> counts(k.size());

    ifstream inputFile;
    inputFile.open("samplecode.cpp");
    if (!inputFile.fail()) {
        string line;
        while (getline(inputFile, line)) {
            for (int i=0; i<k.size(); i++) {
                counts.at(i) += word_count(line, k.at(i));
            }
        }

        for (int item : counts) {
            cout << item << endl;
        }
    }
    return 0;
}
