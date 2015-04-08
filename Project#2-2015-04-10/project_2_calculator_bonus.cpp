#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

const string SQUARE_ROOT_STRING = "sqrt";
const string EXIT_STRING = "exit";
const string HEX = "Hex: ";
const string OCT = "Oct: ";
const string BIN = "Bin: ";
const string EQUAL = " = ";
const string RESULT = "Result: ";
const string FAILED_OPEN_FILE = "Failed to open file...";
const string WELCOME = "Welcome to Extended Calculator-110";
const string PROMPT_FIRST = "Please input Operation: ";
const string PROMPT_LAST = "Good Bye!";
const string TAB = "    ";
const int WIDTH = 30;
const int THREE_DECIMAL_POINTS = 3;
vector<char> FIRST_EVALUATION_OPERATORS = {'/', '*', '^'};

// Convert from decimal to binary
int decimalToBinary(int decimal) {
    int total = 0;
    int base = 1;

    while (decimal > 0) {
        total += (decimal%2) * base;
        decimal /= 2;
        base *= 10;
    }
    return total;
}

// Print the result in the specific format.
void printAndWriteFormattedLine(string operation, double result) {
    int roundedResult = result;

    // Console output
    stringstream ss;
    ss << RESULT << operation << EQUAL << fixed << setprecision(THREE_DECIMAL_POINTS) << result;
    // Conversion to string
    string resultString = ss.str();
    cout << setw(WIDTH) << left
         << resultString
         << HEX << hex << roundedResult << TAB
         << OCT << oct << roundedResult << TAB
         << dec
         << BIN << decimalToBinary(result)
         << endl;

    // Write to file
    fstream file;
    file.open("calc.txt", ios::out | ios::app);
    if (file) {
        file << setw(WIDTH) << left
             << resultString
             << HEX << hex << roundedResult << TAB
             << OCT << oct << roundedResult << TAB
             << dec
             << BIN << decimalToBinary(result)
             << endl;
        file.close();
    } else {
        cout << FAILED_OPEN_FILE << endl;
    }
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
int findOperandInSquareRoot(string s) {
    int firstIndex = 0;
    int lastIndex = 0;

    char prev = s.at(0);
    for (int i=0; i<s.length(); i++) {
        if (!isdigit(prev) && isdigit(s.at(i))) {
            // digit starts
            firstIndex = i;
        } else if (isdigit(prev) && !isdigit(s.at(i))) {
            // digit ends
            lastIndex = i-1;
        }
        prev = s.at(i);
    }
    string operandString = s.substr(firstIndex, lastIndex - firstIndex + 1);
    return stoi(operandString);
}

int findElementIndex(vector<char> v, char c) {
    int found = -1;
    int i = 0;
    for (char element : v) {
        if (element == c) found = i;
        i++;
    }
    return found;
}

double doComplexCalculation(string s) {
    // ex.) 5 + 40 / 3
    stringstream stream(s);
    vector<double> doubleV = {};
    vector<char> charV = {};

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
            int operand = findOperandInSquareRoot(transfer);
            printAndWriteFormattedLine(transfer, sqrt(operand));
        } else if (isQueryIncluded(transfer, EXIT_STRING)) {
            // exit operation
            exit = true;
            cout << endl << PROMPT_LAST << endl;
        } else {
            printAndWriteFormattedLine(transfer, doComplexCalculation(transfer));
        }
    } while(!exit);

    return 0;
}
