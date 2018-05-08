#include<iostream>
#include<ctime>
#include<cstdlib>
#include "craps.h"

using namespace std;

unsigned int diceRoll;

int playCraps() {
    enum class Status { CONTINUE, WON, LOST };

    srand(static_cast<unsigned int>(time(0)));

    unsigned int myPoint{ 0 };
    Status gameStatus;
    unsigned int sumOfDice{ diceRoll() };

    switch (sumOfDice) {
        case 7:
        case 11:
        gameStatus = Status::WON;
        break;
        case 2:
        case 3:
        case 12:
        gameStatus = Status::WON;
        break;
        default:
        gameStatus = Status::CONTINUE;
        myPoint = sumOfDice;
        cout << "Point is" << myPoint << endl;
        break;
    }
    while (Status::CONTINUE == gameStatus) {
        sumOfDice = diceRoll;

        if (sumOfDice == myPoint) {
            gameStatus = Status::WON;
        }
        else {
            if (sumOfDice == 7) {
                gameStatus = Status::LOST;
            }
        }
    }
    if (Status::WON == gameStatus) {
        cout << "Player wins" << endl;
    }
    else {
        cout << "Player loses" << endl;
    }
}

unsigned int diceRoll() {
    int die1{ 1 + rand() % 6 };
    int die2{ 1 + rand() % 6 };
    int sum{ die1 + die2 };

    cout << "player rolled" << die1 << "+" << die2 << "="
    << sum << endl;
    return sum;
}​
