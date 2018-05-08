#include<iostream>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<array>
#include<iomanip>
#include<algorithm>
#include<random>
#include<ctime>

using namespace std;

int game;

int playRoulette() {

    int roll = 0;
    int bet, winnings, balance;
    int won = 0;
    char choice, red, black, choice2, color, number;

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


int playCraps() {
    enum class Status { CONTINUE, WON, LOST };

    unsigned int diceRoll;

    srand(static_cast<unsigned int>(time(0)));

    unsigned int myPoint = 0;
    Status gameStatus;
    unsigned int sumOfDice;

    sumOfDice = diceRoll();

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
    int die1 = 1 + rand() % 6;
    int die2 = 1 + rand() % 6;
    int sum = die1 + die2;

    cout << "player rolled" << die1 << "+" << die2 << "="
    << sum << endl;
    return sum;
}

int playBlackjack() {

    const size_t suit = 4;
    const size_t ranks = 13;

    // int main() {
        srand(time(0));
        int player = 0;
        int computer = 0;

        array<array<int, ranks>suit>deck = { 2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11};
        deal(player, computer, deck);
        for (auto suit : deck)
        {
            for (auto : ranks)
            cout << ranks << " ";
            cout << endl;
        }
        cout << "Player has" << player << endl;
        cout << "Computer has" << computer << endl;
    // }
}


int main() {
    cout << "Pick a game\n1.Blackjack\n2.Craps\n3.Roulette" << endl;
    cin >> game;

    if (game == 1) {
        // Let's play blackjack
        // playBlackjack();
    } else if (game == 2) {
        // Let's play craps
        // playCraps();
    } else if (game == 3) {
        // Let's play roulette
        playRoulette();
    } else {
        cout << game << endl;
        cout << "Invalid game chosen" << endl;
    }

    return 0;
}

int hit(array<array<int, ranks>, suit>&d) {
    int card;
    int suit = rand() % 4;
    int ranks = rand() % 13;

    card = d[suit][ranks];
    if (card == 0)
    hit(d);
    d[suit][ranks] = 0;
    cout << suit << " " << ranks << " " << card << endl;
    if (suit == 0)
    cout << ranks + 2 << "of clubs" << endl;
    if (suit == 1)
    cout << ranks + 2 << "of hearts" << endl;
    if (suit == 2)
    cout << ranks + 2 << "of diamonds" << endl;
    if (suit == 3)
    cout << ranks + 2 << "of spades" << endl;
    return card;
}
void deal(int &player, int &computer, array<array<int, ranks>suit>&d) {
    player = player + hit(d);
    computer = computer + hit(d);
    player = player + hit(d);
    computer = computer + hit(d);
}
