#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

// int, bool, double, long, while, for, void, static, else, if, return
/*
int occurs 15 times
bool occures 9 times
double occurs 3 times
long occurs 2 times
while occurs 9 times
for occurs 2 times
void occurs 2 times
static occurs 2 times
else occurs 2 times
if occurs 2 times
case occurs 2 times
return occurs 2 times
*/

using namespace std;

int word_count(string line, string s) {
    int counter = 0;
    size_t pos = 0;
    while(string::npos != (pos = line.find(s, pos))) {
        counter++;
        pos += s.size();
    }
    return counter;
}

int word_count

int main() {
    ifstream inputFile;
    inputFile.open("samplecode.cpp");

    vector<string> keywords = {"int", "bool", "double", "long", "while", "for", "void", "static", "else", "if", "case", "return"};
    vector<int> keywordsCount(keywords.size());

    if (inputFile) {
        string line;
        while (getline(inputFile, line)) {
            stringstream as;
            for (int i=0; i<keywords.size(); i++) {
                keywordsCount.at(i) += word_count(line, keywords.at(i));
            }
        }
        inputFile.close();

        for (int i=0; i<keywords.size(); i++) {
            cout << setw(10) << keywords.at(i) << " occurs " << keywordsCount.at(i) << " times." << endl;
        }

    } else {
        cout << "Error opening..." << endl;
    }

    return 0;
}
