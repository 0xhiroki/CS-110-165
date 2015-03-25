/*
    2 sentences are anagrams if they contain the same count of
    letters (example below).
    Write a program to ask the user for a file name, read from a file
    -lines-at-a-time and see if those two lines are anagrams.

    Examples Anagrams:

    The earthquakes
    That queer shake

    Debit card
    Bad credit

    Slot machine
    Cash lost in em

    School master
    The classroom
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int word_count(string line) {
    int count = 0;
    stringstream ss;
    ss << line;
    string s;
    while (ss >> s) {
        count += s.size();
    }
    return count;
}

void IsAnagrams(fstream &infile) {
    string line;
    while(getline(infile, line)) {
        string nextLine;
        getline(infile, nextLine);

        int lineCounter = word_count(line);
        int nextLineCounter = word_count(nextLine);

        string result = lineCounter == nextLineCounter ? " anagram!" : " not anagram!";

        cout << "\"" << line << "\""
             << " and " << "\"" << nextLine
             << "\"" << " are " << result << endl << endl;
    }
}

int main() {
    string transfer;

    cout << "Please input the file name: ";
    getline(cin, transfer);

    fstream infile;
    infile.open(transfer, ios::in);
    if (infile) {
        IsAnagrams(infile);
        infile.close();
    } else {
        cout << "Error opening..." << endl;
    }

    return 0;
}
