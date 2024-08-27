#include "Multiples.hpp"

int main() {
    Multiples mult;
    signed long long int min = -75312;
    signed long long int max = 407891;
    int factor = 14;

    cout << mult.numbers(min, max, factor) << endl;
    return 0;
}