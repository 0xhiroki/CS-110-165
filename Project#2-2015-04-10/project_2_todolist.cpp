#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

const string RIGHT_ARROW = " ==> ";
const string INPUT_FILE_NAME = " Please input the file name: ";
const string ERROR_OPENING_FILE = "Error opening file...";
const string NO_ITEM = "There's no items in the list!";

void RemoveTopItem(vector<string> &todolist) {
    vector<string> dummy = {};
    int size = todolist.size();
    for (int i=0; i<size; i++) {
        dummy.push_back(todolist.back());
        todolist.pop_back();
    }

    dummy.pop_back();

    vector<string> newVec = {};
    size = dummy.size();
    for (int i=0; i<size; i++) {
        newVec.push_back(dummy.back());
        dummy.pop_back();
    }

    todolist = newVec;
}

void AddToList(vector<string> &todolist) {
    string transfer;
    cout << " Please add an item on the To Do list\n"
         << RIGHT_ARROW;
    getline(cin, transfer);
    todolist.push_back(transfer);
}

void ShowNextItem(vector<string> &todolist) {
    if (!todolist.empty()) {
        cout << " The next item on the To Do list is\n"
             << RIGHT_ARROW
             << todolist.at(0) << endl;
    } else {
        cout << NO_ITEM << endl;
    }
}

void ListAllItems(vector<string> &todolist) {
    cout << " All items in the list is\n"
         << RIGHT_ARROW
         << endl;
    for (string itemRef : todolist) {
        cout << " " << itemRef << endl;
    }
}

void DoThis(vector<string> &todolist) {
    if (!todolist.empty()) {
        cout << " OK, time to do this list item:"
             << endl
             << RIGHT_ARROW
             << todolist.at(0)
             << endl;
        RemoveTopItem(todolist);
    } else {
        cout << NO_ITEM << endl;
    }
}

void Save(vector<string> &todolist) {
    string transfer;
    cout << " We will save all the items into the file.\n"
         << INPUT_FILE_NAME;
    getline(cin, transfer);
    fstream file;
    file.open(transfer, ios::out);
    if (file) {
        for (string s : todolist) {
            file << s << endl;
        }
        file.close();
    } else {
        cout << ERROR_OPENING_FILE << endl;
    }
}

void Load(vector<string> &todolist) {
    string transfer;
    cout << " We will load items from file and populates the todo list\n"
         << INPUT_FILE_NAME;
    getline(cin, transfer);
    fstream file;
    file.open(transfer, ios::in);
    string line;
    if (file) {
        // remove the contents and add new todos.
        todolist.clear();
        while (getline(file, line)) {
            todolist.push_back(line);
        }
        file.close();
    } else {
        cout << ERROR_OPENING_FILE << endl;
    }
}

void AllDone(vector<string> &todolist) {
    cout << " Goodbye for now." << endl;
}

int main() {
    vector<string> todolist = {};
    string transfer;
    int number;
    bool done;

    do {
        cout << "What to do?\n"
             << "1 Add to the list\n"
             << "2 Show the next item on the list\n"
             << "3 Do the next item on the list and remove it\n"
             << "4 List all items\n"
             << "5 Save list\n"
             << "6 Load list\n"
             << "7 All done with this To Do List!\n"
             << RIGHT_ARROW;

        // Input number
        getline(cin, transfer);
        stringstream(transfer) >> number;
        cout << endl;

        switch (number) {
            case 1:
                AddToList(todolist);
                break;
            case 2:
                ShowNextItem(todolist);
                break;
            case 3:
                DoThis(todolist);
                break;
            case 4:
                ListAllItems(todolist);
                break;
            case 5:
                Save(todolist);
                break;
            case 6:
                Load(todolist);
                break;
            case 7:
                AllDone(todolist);
                done = true;
                break;
        }
        cout << endl;
    } while(!done);

    return 0;
}
