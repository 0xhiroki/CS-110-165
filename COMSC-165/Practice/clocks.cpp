#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;
using namespace std::chrono;

void PrintCurrentTime(int totalInSec) {
    this_thread::sleep_for(chrono::seconds(1));

    int second = totalInSec % 60;
    int hour = totalInSec / 60 / 60;
    int minute = totalInSec / 60 % 60;

    cout << "Time now: " << setfill(' ') << setw(2) << hour << ":"
                         << setfill(' ') << setw(2) << minute << ":"
                         << setfill(' ') << setw(2) << second << flush << '\r';
}

int main() {
    system_clock::time_point t = system_clock::now();
    time_t tt = system_clock::to_time_t(t);

    char comma;
    int hour;
    int minute;
    int second;
    string others;
    stringstream ss;
    ss << ctime(&tt);
    ss >> others >> others >> others;
    ss >> hour >> comma >> minute >> comma >> second;

    int sec = hour * 60 * 60 + minute * 60 + second;

    for (int i=sec; ; i++) {
        PrintCurrentTime(i);
    }

    return 0;
}
