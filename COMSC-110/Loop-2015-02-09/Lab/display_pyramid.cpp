/*
    Lab Part 1
    #2 Display pyramid
    Hiroki Hori & Satoru Sasozaki
*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

const string PROMPT = "Enter the number of of lines: ";
const string SPACE = " ";
const string ONE_WITH_SPACES = " 1 ";

int main() {
    string transfer;
    int number_of_lines;
    int numbers_in_one_line;

    // Prompt
    cout << PROMPT << endl;

    // Get number of lines
    getline(cin, transfer);
    stringstream(transfer) >> number_of_lines;

    // Number of digit in one line
    numbers_in_one_line = 2 * number_of_lines - 1;

    // Split the pyramid horizontally and iterate each line
    for (int j=1; j<=number_of_lines; j++) {
        string buffer_left = "";
        string buffer_right = "";

        // Split the pyramid into three parts: left, "1", and right.

        // Left side of the pyramid
        for (int k=j; k>1; k--) {
            buffer_left += to_string(k);
            buffer_left +=  k == 2 ? "" : SPACE;
        }

        // Right side of the pyramid
        for (int l=2; l<=j; l++) {
            buffer_right += to_string(l);
            buffer_right += l == j ? "" : SPACE;
        }

        // Calculate half width with space
        int half_width_with_space = (numbers_in_one_line * 2 - ONE_WITH_SPACES.length())/2;

        // Output with formatting
        cout << setw(half_width_with_space) << right << buffer_left
             << setw(ONE_WITH_SPACES.length()) << ONE_WITH_SPACES
             << setw(half_width_with_space) << left << buffer_right << endl;
    }

    return 0;
}


