/*
    Lab Part 1
    #1 Random Number Guessing Game
    Hiroki Hori & Satoru Sasozaki
*/

#include <iostream>
#include <string>
#include <sstream>
#include <random>

using namespace std;

const int RANDOM_MAX = 100;
const int RANDOM_MIN = 1;

const string TOO_HIGH = "Too high, try again.";
const string TOO_LOW = "Too low, try again.";
const string CORRECT = "Whooray! Your guess is correct! The number of your guesses is: ";

int main() {
    string transfer;
    int guessed_number;
    int guesses = 0;

    // Generate random number between 1...100
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(RANDOM_MIN, RANDOM_MAX);
    int random_number = distribution(generator);

    // Do while until the user's guess is correct.
    do {
        guesses++;
        cout << "Guess the number: ";
        getline(cin, transfer);
        stringstream(transfer) >> guessed_number;

        if (guessed_number > random_number) {
            cout << TOO_HIGH << endl;
        } else if (guessed_number < random_number) {
            cout << TOO_LOW << endl;
        }
    } while (guessed_number != random_number);

    cout << CORRECT << guesses << endl;

    return 0;
}
