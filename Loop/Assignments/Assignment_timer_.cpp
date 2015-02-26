#include <iostream>
#include <string>
#include <thread>
#include <sstream>
#include <chrono>
#include <iomanip>

using namespace std;

const int MINUTE_IN_AN_HOUR = 60;
const int SECOND_IN_A_MINUTE = 60;

int main() {
    string transfer;
    int seconds;
    int minutes;
    int hours;
    char colon;
    int totalInSec;

    cout << "Please input time as hh:mm:ss ";
    getline(cin, transfer);
    stringstream(transfer) >> hours >> colon >> minutes >> colon >> seconds;

    totalInSec = hours * MINUTE_IN_AN_HOUR * SECOND_IN_A_MINUTE + minutes * SECOND_IN_A_MINUTE + seconds;

    for (; seconds > 0 || minutes > 0 || hours > 0; seconds--) {
        this_thread::sleep_for(chrono::seconds(1));
        cout << hours << minutes << seconds << endl;
        if (seconds == 0 && (minutes > 0 || hours > 0)) {
            seconds = 59;
            minutes--;
        }
    }

    /*
    for (; totalInSec>=0; totalInSec--) {
        // Convert second, minute, and hour from the current totalInSec
        int second = totalInSec % SECOND_IN_A_MINUTE;
        int hour   = totalInSec / MINUTE_IN_AN_HOUR / SECOND_IN_A_MINUTE;

        // Calculate total in min and then calculate minute
        int totalInMin = totalInSec / SECOND_IN_A_MINUTE;
        int minute = totalInMin % MINUTE_IN_AN_HOUR;

        // Wait 1sec
        this_thread::sleep_for(chrono::seconds(1));

        // Numbers' width should be 2 & right aligned
        cout << setfill('0') << setw(2) << right << hour << ":"
             << setfill('0') << setw(2) << right << minute << ":"
             << setfill('0') << setw(2) << right << second
             << flush << '\r';
    }
    */
    cout << "Timer is up!" << endl;
    return 0;
}

