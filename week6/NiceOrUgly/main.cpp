#include "NiceOrUgly.hpp"

int main() {
    NiceOrUgly game;
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    cout << game.describe(s) << endl;
    return 0;
}