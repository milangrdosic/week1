#include "NiceOrUgly.hpp"

int main() {
    NiceOrUgly game;
    string s = "AA?QQQ?A?QQQ?A?QQQ?A??QQQ?A?QQQ?A?QQQ?A?QQQ?A?QQQQ";

    cout << game.describe(s) << endl;
    return 0;
}