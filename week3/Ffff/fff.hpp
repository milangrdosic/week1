#include <iostream>
#include <stdlib.h>
#include <numeric>

using namespace std;

class FracCount {
    public:
        int position(int numerator, int denominator) {
            int count = 0;

            for (int i = 2; i <= denominator; i++) {
                for (int j = 1; j <= i; j++) {
                    if (gcd(j, i) == 1) {
                        count++;
                    }

                    if (i == denominator && j == numerator) {
                        return count;
                    }

                }
            }
            return -1;
        }
};