#include "ChangingString.hpp"

int main() {
    ChangingString cs;
    cout << cs.distance("aa", "aa", 2) << endl;  // Expected output: 2
    cout << cs.distance("aaa", "baz", 1) << endl;  // Another test case
    return 0;
}