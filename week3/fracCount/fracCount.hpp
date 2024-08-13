#include <iostream>
#include <stdlib.h>
#include <numeric>

using namespace std;

class fracCount {
    public:
        int position(int numerator, int denominator) {
            int count = 0;

            if (numerator == 1 && denominator == 2) {
                return 1;
            }

            for (int i = 2; i <= denominator; i++) {
                for (int j = 1; j <= i; j++) {
                    int gcdVal = gcd(j, i);
                    if (gcdVal == 1) {
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