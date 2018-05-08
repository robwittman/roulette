#include<iostream>
#include<array>
#include<cstdlib>

using namespace std;

int roll = 0;
int bet, winnings, balance;
int won = 0;
char choice, red, black, choice2, color, number;



int main() {

    balance = 1000;

    cout << "Pick a bet amount" << endl;
    cin >> bet;
    cout << "Choose a Bet\n1.Color\t2.Number" << endl;
    cin >> choice;
    balance = 1000 - bet;
    // Check wether they want to bet on a color or number,
    // and set variables equal to their choice
    if (choice == '1') { // Betting on color
        cout << "Choose between Red or black" << endl;
        cin >> color;
    } else if (choice == '2') { // Betting on number
        cout << "Choose a number between 0 and 36" << endl;
        cin >> number;
    } else {
        cout << "Invalid Choice. Please pick 1 or 2" << endl;
        return 0;
    }

    cout << "Spinning the wheel..." << endl;
    // Roll the ball baby...
    roll = rand() % 36;

    cout << "The ball landed on " << roll << endl;
    // If they selected a color
    if (choice == '1') {
        // Add validation for checking their color choice was correct or not.
    } else {
        // Validate their number choice
        if (number == roll) {
            // They chose the correct number, so mark that they won
            won = 1;
        }
    }

    // If they won or lost, modify their balance accordingly.
    if (won == 1) {
        cout << "Congratulations, you won!" << endl;
        // Add their winnings to balance!
    } else {
        cout << "Shame, you lost..." << endl;
    }

    // Exit
    return 0;
}
