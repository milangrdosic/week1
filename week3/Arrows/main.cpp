#include "Arrows.hpp"

int main() {
    Arrows arrows;
    string s = "<--->--==>";

    cout << arrows.longestArrow(s) << endl;

    return 0;
}