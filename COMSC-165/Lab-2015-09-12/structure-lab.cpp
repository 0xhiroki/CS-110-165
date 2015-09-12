#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

const int NUM_OF_PC = 4;

struct BaseInfo {
    string serialNum;
    string model;
    string brand;
    string name;
};

struct Keyboard {
    BaseInfo base;
};

struct Mouse {
    BaseInfo base;
};

struct Core {
    BaseInfo base;
};

struct CPU {
    BaseInfo base;
    vector<Core> cores;
    int numberOfcore;
    double speed;
};

struct GraphicCard {
    BaseInfo base;
};

struct HDD{
    BaseInfo base;
    int capacity;
    string interface;
};

struct Size {
    int height;
    int width;
};

struct Monitor {
    BaseInfo base;
    double resolution;
    Size screenSize;
};

struct PC {
    BaseInfo base;
    Keyboard keyboard;
    Mouse mouse;
    CPU cpu;
    GraphicCard graphicCard;
    HDD hdd;
    Monitor monitor;
};

int searchPC(int num, string keyword, PC pcs[NUM_OF_PC], bool& isFound) {

    int result;
    switch (num) {
        case 1: for (int i=0; i<NUM_OF_PC; i++) {
                    if (pcs[i].base.name == keyword) {
                        result = i;
                        isFound = true;
                    }
                }
                break;
        case 2: for (int i=0; i<NUM_OF_PC; i++) {
                    if (pcs[i].base.serialNum == keyword) {
                        result = i;
                        isFound = true;
                    }
                }
                break;
        case 3: for (int i=0; i<NUM_OF_PC; i++) {
                    if (pcs[i].base.brand == keyword) {
                        result = i;
                        isFound = true;
                    }
                }
                break;

        case 4: for (int i=0; i<NUM_OF_PC; i++) {
                    if (pcs[i].base.model == keyword) {
                        result = i;
                        isFound = true;
                    }
                }
                break;
    }

    return result;

}

int chooseMenu() {
    string transfer;
    int num;
    cout << "Which element do you want to use?\n"
         << "1. computer name\n"
         << "2. serial number\n"
         << "3. brand\n"
         << "4. model\n"
         << "Input the number: ";
    getline(cin, transfer);
    stringstream(transfer) >> num;
    return num;
}


string getInput() {
    string keyword;
    cout << "Input the keyword: ";
    getline(cin, keyword);
    return keyword;
}

void displayResult(int i, PC pcs[NUM_OF_PC]) {
    cout << "General info-------------------------------\n"
         << "computer name: " << pcs[i].base.name << endl
         << "brand: " << pcs[i].base.brand << endl
         << "model: " << pcs[i].base.model << endl
         << "serial num: " << pcs[i].base.serialNum << endl;

    cout << "CPU info-----------------------------------\n"
         << "# of core: " << pcs[i].cpu.numberOfcore << endl
         << "speed: " << pcs[i].cpu.speed << endl
         << "serial num: " << pcs[i].cpu.base.serialNum << endl;

    cout << "Graphics card------------------------------\n"
         << "brand: " << pcs[i].graphicCard.base.brand << endl
         << "model: " << pcs[i].graphicCard.base.model << endl
         << "serial num: " <<pcs[i].graphicCard.base.serialNum << endl;

    cout << "HDD----------------------------------------\n"
         << "capacity: " << pcs[i].hdd.capacity << endl
         << "interface: " << pcs[i].hdd.interface << endl
         << "serial num: " << pcs[i].hdd.base.serialNum << endl;

    cout << "Monitors-----------------------------------\n"
         << "height: " << pcs[i].monitor.screenSize.height << endl
         << "width: "  << pcs[i].monitor.screenSize.width << endl
         << "resolution: " << pcs[i].monitor.resolution << endl
         << "serial num: " << pcs[i].monitor.base.serialNum << endl;

    cout << "Mouse--------------------------------------\n"
         << "serial num: " << pcs[i].mouse.base.serialNum << endl;

}

int main () {
    PC pcs[NUM_OF_PC];
    bool isFound = false;

    pcs[0] = {{"c001","model1","acer","c1"}, {{"keyboard001"}}, {{"mouse001"}}, {{"cpu001"},{{{"core1-001"}}, {{"core1-002"}}, {{"core1-003"}}, {{"core1-004"}} }, 4, 300},{{"graphics001","model1","GForce"}}, {{"Hdd001"}, 125, "Sata"}, {{"monitor001"}, 1000, {1000, 800}}};
    pcs[1] = {{"c002","model2","DELL","c2"}, {{"keyboard002"}}, {{"mouse002"}}, {{"cpu002"},{{{"core2-001"}}, {{"core2-002"}}, {{"core2-003"}}, {{"core2-004"}} }, 4, 300},{{"graphics002","model2","GForce"}}, {{"Hdd002"}, 125, "Sata"}, {{"monitor002"}, 1000, {1000, 800}}};
    pcs[2] = {{"c003","model3","HP","c3"  }, {{"keyboard003"}}, {{"mouse003"}}, {{"cpu003"},{{{"core3-001"}}, {{"core3-002"}}, {{"core3-003"}}, {{"core3-004"}} }, 4, 300},{{"graphics003","model3","GForce"}}, {{"Hdd003"}, 125, "Sata"}, {{"monitor003"}, 1000, {1000, 800}}};
    pcs[3] = {{"c004","model4","ASUS","c4"}, {{"keyboard004"}}, {{"mouse004"}}, {{"cpu004"},{{{"core4-001"}}, {{"core4-002"}}, {{"core4-003"}}, {{"core4-004"}} }, 4, 300},{{"graphics004","model4","GForce"}}, {{"Hdd004"}, 125, "Sata"}, {{"monitor004"}, 1000, {1000, 800}}};

    int num = chooseMenu();
    string keyword = getInput();
    int resultIndex = searchPC(num,keyword,pcs,isFound);
    cout << resultIndex << endl;
    displayResult(resultIndex,pcs);

    return 0;
}



