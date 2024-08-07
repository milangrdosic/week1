#include <iostream>
#include <stdlib.h>
#include <cstdlib> 
#include <vector>

using namespace std;

class ChangingString {
    public:
        int distance(string A, string B, int K) {

            int len = A.length();
            vector<int> differences(len);

            for (int j = 0; j < len; ++j) {
                differences[j] = abs(A[j] - B[j]);
            }

            while (K > 0) {
                int maxDiff = 0;
                int lenIndx = -1;

                for (int j = 0; j < len; ++j) {
                    if (differences[j] > maxDiff) {
                        maxDiff = differences[j];
                        lenIndx = j;
                    }
                }

                // If the maximum difference is zero, we must make changes to increase the distance
                if (maxDiff == 0) {
                    for (int j = 0; j < len; ++j) {
                        if (A[j] == B[j]) {
                            differences[j] = 1;  // Minimum increase by changing 'a' to 'b' or vice versa
                            lenIndx = j;
                            break;
                        }
                    }
                }

                // Set the difference at lenIndx to 0 if it was not zero initially
                if (lenIndx != -1 && maxDiff != 0) {
                    differences[lenIndx] = 0;
                }
                K--;
            }

            // Calculate the total distance after making the changes
            int totalDistance = 0;
            for (int diff : differences) {
                totalDistance += diff;
            }

            return totalDistance;
        }
};
