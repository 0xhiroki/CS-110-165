/***************************************************************
Problem: Project #1 Problem#3
Description: This program will ask the user to input the diameter
of the crystal ball then calculate the size of the shipping box and
volume of popcorns to protect the ball, followed by displaying them.
Name: Hiroki Hori
ID: 1496802
Date: 02/20/2015
Status: complete
****************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

const double PI = 3.14159265;
const int POPCORN_WIDTH = 4;
const string CUBIC_INCHES = " cubic inches";
const string INCHES = " inches";

int main() {
    string transfer;

    float ball_diameter;
    float ball_radius;
    float box_width;

    float volume_of_ball;
    float volume_of_box;
    float volume_of_popcorn;

    cout << "Welcome to the future!" << endl;
    cout << "What is the diameter in inches?" << endl;
    getline(cin, transfer);
    stringstream(transfer) >> ball_diameter;

    ball_radius = ball_diameter / 2.0;
    volume_of_ball = 4/3*PI*pow(ball_radius, 3);

    box_width = ball_diameter + POPCORN_WIDTH * 2;
    volume_of_box = box_width * box_width * box_width;

    // Volume of popcorn is obtained by subtracting the volume of ball from the volume of box
    volume_of_popcorn = volume_of_box - volume_of_ball;

    cout << "Dimensions of the crystal ball (diameter): " << ball_diameter << INCHES << endl;
    cout << "Dimensions of the box (width): " << box_width << INCHES << endl;
    cout << "Volume of the popcorns: " << volume_of_popcorn << CUBIC_INCHES << endl;

    return 0;
}
