#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

const int TUITION_IN_STATE = 3000;
const int TUITION_OUT_OF_STATE = 4500;
const int ROOM_AND_BOARD_IN_STATE = 2500;
const int ROOM_AND_BOARD_OUT_OF_STATE = 3500;

int main () {
    char residency, roomAndBoardRequired;
    float tuition = 0;
    float roomAndBoard = 0;
    string transfer;

    // Prompt 1
    cout << "Please input \"I\" if you are in-state or \"O\" if you are out-of-state:" << endl;
    getline(cin, transfer);
    stringstream(transfer) >> residency;
    residency = toupper(residency);

    // Prompt 2
    cout << endl << "Please input \"Y\" if you require room and board and \"N\" if you do not:" << endl;
    getline(cin, transfer);
    stringstream(transfer) >> roomAndBoardRequired;
    roomAndBoardRequired = toupper(roomAndBoardRequired);

    // Conditional Statement
    // 1. do the tuition calculator using only 2 simple "if" statements
    // Set the default values.
    tuition = TUITION_IN_STATE;
    roomAndBoard = ROOM_AND_BOARD_IN_STATE;
    if (residency == 'O') {
        tuition = TUITION_OUT_OF_STATE;
        roomAndBoard = ROOM_AND_BOARD_OUT_OF_STATE;
    }
    if (roomAndBoardRequired == 'N') {
        roomAndBoard = 0;
    }
    cout << endl << "Your total bill for this semester is $" << tuition + roomAndBoard << endl;

    cout << endl;

    // 2. write the program without any conditional statments or operators
    // Subtract the char from 'O' or 'I'.
    tuition = static_cast<bool>('O' - residency) * TUITION_IN_STATE + static_cast<bool>('I' - residency) * TUITION_OUT_OF_STATE;
    int roomFee = static_cast<bool>('O' - residency) * ROOM_AND_BOARD_IN_STATE + static_cast<bool>('I' - residency) * ROOM_AND_BOARD_OUT_OF_STATE;
    roomAndBoard = static_cast<bool>('N' - roomAndBoardRequired) * roomFee;
    cout << endl << "Your total bill for this semester is $" << tuition + roomAndBoard << endl;

    return 0;
}
