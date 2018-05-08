#include <iostream>
#include<cmath>
#include<array>
#include<iomanip>
#include<algorithm>
#include<random>

using namespace std;

const size_t suit = 4;
const size_t ranks = 13;

int main() {
    srand(time(0));
    int player = 0;
    int computer = 0;

    array<array<int, ranks>suit>deck = { 2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11 };
    deal(player, computer, deck);
    for (auto suit : deck) {
        for (auto : ranks)
        cout << ranks << " " << endl;
    }
    cout << "Player has" << player << endl;
    cout << "Computer has" << computer << endl;
}​

int hit(array<array<int, ranks>, suit>&d)
{
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

void deal(int &player, int &computer,d) {
    player = player + hit(d);
    computer = computer + hit(d);
    player = player + hit(d);
    computer = computer + hit(d);
}
