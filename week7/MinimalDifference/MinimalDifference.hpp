#include <iostream>
#include <stdlib.h>
#include <climits>
#include <cmath>

using namespace std;

class MinimalDifferen {
    public:
        int findNumber(int A, int B, int C) {
            int sumC = digitSum(C);
            int minDifference = INT_MAX;
            int resultX = A;

            for (int X = A; X <= B; X++) {
                int sumX = digitSum(X);
                int difference = abs(sumX - sumC);
                cout << sumC << " : " << sumX << endl;

                if (difference < minDifference || (difference == minDifference & X < resultX)) {
                    minDifference = difference;
                    resultX = X;
                }
            }
            return resultX;
        }

        int digitSum(int n) {
            int sum = 0;
            while (n != 0) {
                sum += n % 10;
                n /= 10;
            }
            return abs(sum);
        }

};