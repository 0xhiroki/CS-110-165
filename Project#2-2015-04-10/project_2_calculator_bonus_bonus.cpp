#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <cctype>

using namespace std;

const string SQUARE_ROOT_STRING = "sqrt";
const string EXIT_STRING = "exit";
const string HEX = "Hex: ";
const string OCT = "Oct: ";
const string BIN = "Bin: ";
const string EQUAL = " = ";
const string RESULT = "Result: ";
const string FAILED_OPEN_FILE = "Failed to open file...";
const string WELCOME = "Welcome to Super Extended Calculator-110";
const string PROMPT_FIRST = "Please input Operation: ";
const string PROMPT_LAST = "Good Bye!";
const int WIDTH30 = 30;
const int WIDTH15 = 15;
const int BASE = 10;
const int THREE_DECIMAL_POINTS = 3;
vector<char> FIRST_EVALUATION_OPERATORS = {'/', '*', '^'};

// Convert from decimal to binary
int decimalToBinary(int decimal) {
    int total = 0;
    int base = 1;

    while (decimal > 0) {
        total += (decimal%2) * base;
        decimal /= 2;
        base *= BASE;
    }
    return total;
}

void writeToFile(string outPutString) {
    fstream file;
    file.open("calc.txt", ios::out | ios::app);
    if (file) {
        file << outPutString;
        file.close();
    } else {
        cout << FAILED_OPEN_FILE << endl;
    }
}

// Print the result in the specific format.
void printAndWriteFormattedLine(string operation, double result) {
    int roundedResult = result;

    // Console output
    stringstream ss1, ss2, hectSS, octSS, binSS;

    // Save operation string + decimal result as one string for later setw and left manipulation.
    ss1 << RESULT
        << operation << EQUAL << fixed << setprecision(THREE_DECIMAL_POINTS)
        << result;

    // Put hex, oct, bin values to each stringstream object in order to manipulate width later.
    hectSS << HEX << hex << roundedResult;
    octSS << OCT << oct << roundedResult;
    binSS << BIN << decimalToBinary(result);

    // Save the entire result string
    ss2 << setw(WIDTH30) << left
        << ss1.str()
        << setw(WIDTH15) << hectSS.str()
        << setw(WIDTH15) << octSS.str()
        << dec
        << setw(WIDTH15) << binSS.str()
        << endl;

    string outPutString = ss2.str();

    // Output to console
    cout << outPutString;

    // Write to file
    writeToFile(outPutString);
}

// Determine whether specified query is included in the string given.
bool isQueryIncluded(string original, string query) {
    return original.find(query) != string::npos;
}

// Do basic math operation (+, -, /, *, ^)
double doEasyCalculation(char operand, double number1, double number2) {
    double result = 0;
    switch (operand) {
        case '+':
            result = number1 + number2;
            break;
        case '-':
            result = number1 - number2;
            break;
        case '/':
            result = number1 / number2;
            break;
        case '*':
            result = number1 * number2;
            break;
        case '^':
            result = pow(number1, number2);
            break;
    }
    return result;
}

// Find the operand from the operation string
double findOperandInSquareRoot(string s) {
    int firstIndex = 0;
    int lastIndex = 0;
    double result;

    char prev = s.at(0);
    for (int i=0; i<s.length(); i++) {
        // 255.32
        // This handles decimal point too.
        if (prev != '.' && !isdigit(prev) && isdigit(s.at(i))) {
            // digit starts
            firstIndex = i;
        } else if (isdigit(prev) && s.at(i) != '.' && !isdigit(s.at(i))) {
            // digit ends
            lastIndex = i-1;
        }
        prev = s.at(i);
    }
    string operandString = s.substr(firstIndex, lastIndex - firstIndex + 1);
    stringstream(operandString) >> result;
    return result;
}

int findElementIndex(vector<char> v, char c) {
    // Find the specified (first) element index from the vector
    int found = -1;
    int i = 0;
    bool done = false;
    for (char element : v) {
        if (element == c && !done) {
            found = i;
            done = true;
        }
        i++;
    }
    return found;
}

double calculateFromString(string s) {
    stringstream stream(s);
    vector<double> doubleV = {};
    vector<char> charV = {};
    // Divide string into char vector & double vector.
    while(!stream.eof()) {
        double n;
        char c;
        if (!stream.eof()) {
            stream >> n;
            doubleV.push_back(n);
        }
        if (!stream.eof()) {
            stream >> c;
            charV.push_back(c);
        }
    }

    // Do multiplication, power, or division first.
    for (char ope : FIRST_EVALUATION_OPERATORS) {
        while (findElementIndex(charV, ope) != -1) {
            int i = findElementIndex(charV, ope);
            doubleV.at(i) = doEasyCalculation(ope, doubleV.at(i), doubleV.at(i+1));
            doubleV.erase(doubleV.begin()+i+1);
            charV.erase(charV.begin()+i);
        }
    }

    // Do addition or subtraction
    for (char c : charV) {
        doubleV.at(0) = doEasyCalculation(c, doubleV.at(0), doubleV.at(1));
        doubleV.erase(doubleV.begin()+1);
    }
    return doubleV.at(0);
}

double calculateInsideParenthesisAndRest(string s) {
    // Calculate inside the parenthesis first if any.
    // Multiple inner parentheses are hendled as well.
    // ex.) (3*(2+1)) or (3 * (2 * (2+1)))
    while (isQueryIncluded(s, "(")) {
        int startIndex = 0;
        int endIndex = 0;
        bool endDone = false;

        for (int i=0; i<s.length(); i++) {
            if (s.at(i) == '(') {
                // startIndex should be whatever it finds last.
                startIndex = i;
            }
            if (s.at(i) == ')' && !endDone) {
                // endIndex should be the first one it finds.
                endIndex = i;
                endDone = true;
            }
        }
        double r = calculateFromString(s.substr(startIndex+1, endIndex - startIndex - 1));
        s = s.erase(startIndex, endIndex - startIndex + 1);
        s.insert(startIndex, to_string(r));
    }
    return calculateFromString(s);
}

int main() {
    string transfer;
    int number1;
    int number2;
    char ope;
    bool exit;

    cout << WELCOME << endl;

    do {
        cout << endl << PROMPT_FIRST;
        getline(cin, transfer);

        if (isQueryIncluded(transfer, SQUARE_ROOT_STRING)) {
            // sqrt operation
            printAndWriteFormattedLine(transfer, sqrt(findOperandInSquareRoot(transfer)));
        } else if (isQueryIncluded(transfer, EXIT_STRING)) {
            // exit operation
            exit = true;
        } else {
            // Operation other than sqrt or exit.
            printAndWriteFormattedLine(transfer, calculateInsideParenthesisAndRest(transfer));
        }
    } while(!exit);

    cout << endl << PROMPT_LAST << endl;

    return 0;
}

