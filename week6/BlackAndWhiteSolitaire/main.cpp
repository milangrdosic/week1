#include "BlackAndWhiteSolitaire.hpp"

int main() {
    BlackAndWhiteSolitaire game;
    string cardFront = "WBBWBWB";

    cout << game.minimumTurns(cardFront) << endl;
    return 0;
}