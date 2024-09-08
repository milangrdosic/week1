#include "BlackAndWhiteSolitaire.hpp"

int main() {
    BlackAndWhiteSolitaire game;
    string cardFront = "BWWW";

    cout << game.minimumTurns(cardFront) << endl;
    return 0;
}