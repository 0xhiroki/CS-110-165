#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	ifstream infile;
	ofstream outfile;

	infile.open("CodeBlocks/payroll.dat");
	outfile.open("CodeBlocks/payment.out");

	int hours;
	float payRate;
	float net;

	outfile << fixed << setprecision(2);
    outfile << "Hours     Pay Rate   Net Pay" << endl;
    infile >> hours;

    while (!infile.eof()) {
        infile >> payRate;
        net = hours * payRate;
        outfile << hours << setw(10) << "$ " << setw(6) << payRate << setw(5) << "$ " << setw(7) << net << endl;
        infile >> hours;
    }

    /*
    while (infile) {
        infile >> payRate;
        net = hours * payRate;

        outfile << hours << setw(10) << "$ " << setw(6)
                << payRate << setw(5) << "$ " << setw(7)
                << net << endl;

        infile >> hours;
    }
    */

    infile.close();
    outfile.close();

	return 0;
}
