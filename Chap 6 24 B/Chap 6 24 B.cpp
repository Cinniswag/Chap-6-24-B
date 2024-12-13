// Chap 6 24 B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string input;
double object;
string input2;
double Ywin; //your win
double Cwin; //computer's win
int main()
{
    int cpi;
    cout << "Choose rock, paper, or scissors." << endl;
    replay:
    // menu selector and validator
    do {
        object = -1; // object set to -1 as an invalid state
        cin >> input;
        if (input == "rock") {
            object = 0;
        }
        else if (input == "paper") {
            object = 1;
        }
        else if (input == "scissors") {
            object = 2;
        }
        else if (input == "leave") {
            cout << "Goodbye." << endl;
            return 0; // typing "leave" ends the game if necessary
        }
        else {
            cout << "INVALID. please spell with lowercase." << endl;
        }
    } while (object < 0);
    cout << "You selected: " << input << endl;
    // computer decides
    srand(time(0));
    cpi = rand() % 2;
    if (cpi == 0) {
        input2 = "rock";
    }
    else if (cpi == 1) {
        input2 = "paper";
    }
    else if (cpi == 2) {
        input2 = "scissors";
    }
    cout << "I selected: " << input2 << endl << endl;
    // computer win
    if (cpi == 0 && object == 2) {
        ++Cwin;
        cout << "Rock beats scissors. I win." << endl;
    }
    else if (cpi == 1 && object == 0) {
        ++Cwin;
        cout << "Paper beats rock. I win." << endl;
    }
    else if (cpi == 2 && object == 1) {
        ++Cwin;
        cout << "Scissors beats paper. I win." << endl;
    }
    // you win
    else if (cpi == 2 && object == 0) {
        ++Ywin;
        cout << "Rock beats scissors. You win." << endl;
    }
    else if (cpi == 0 && object == 1) {
        ++Ywin;
        cout << "Paper beats rock. You win." << endl;
    }
    else if (cpi == 1 && object == 2) {
        ++Ywin;
        cout << "Scissors beats paper. You win." << endl;
    }
    else if (cpi == object) {
        cout << "We chose the same. Looks like it's a draw." << endl;
    }
   // scores
    cout << "Me " << Cwin << " and You " << Ywin << "." << endl;
    cout << "Go again." << endl;
    goto replay; // restarts the game but maintain scores
}