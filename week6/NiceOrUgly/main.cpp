#include "NiceOrUgly.hpp"

int main() {
    NiceOrUgly game;
    string s = "AAOQQQOAOQQQOAOQQQOAOOQQQOAOQQQOAOQQQOAOQQQOAOQQQQ";

    cout << game.describe(s) << endl;
    return 0;
}