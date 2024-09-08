#include "BlackAndWhiteSolitaire.hpp"

int main() {
    BlackAndWhiteSolitaire game;
    string cardFront = "BBWBWWBWBWWBBBWBWBWBBWBBW";

    cout << game.minimumTurns(cardFront) << endl;
    return 0;
}