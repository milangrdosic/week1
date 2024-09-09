#include "NiceOrUgly.hpp"

int main() {
    NiceOrUgly game;
    string s = "EI?RQQ?A?WWQ?I?QRQ?A?QRQ?I?WQR?A?RWR?E?WQR?E?QRR";

    cout << game.describe(s) << endl;
    return 0;
}