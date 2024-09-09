#include "NiceOrUgly.hpp"

int main() {
    NiceOrUgly game;
    string s = "O?ZPB?I?FXR?I?QCL?E?NHJ?O?MQM?O?MWX?E?CYY?A?GCGL";

    cout << game.describe(s) << endl;
    return 0;
}