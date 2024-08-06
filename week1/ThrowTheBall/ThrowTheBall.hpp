#include <iostream>
#include <stdlib.h>

using namespace std;

class ThrowTheBall {
    public:
        int timesThrown(int N, int M, int L) {
            int friends[N-1];
            int index = 0;
            int counter = 0;

            // ensure parameters are met
            if (N < 3 || N > 50) {
                return 0;
            }
            if (M < 1 || M > 50) {
                return 0;
            }
            if (L < 1 || L > N-1) {
                return 0;
            }
            
            // initialize empty array 
            for (int i = 0; i <= N; i++) {
                friends[i] = 0;
            }

            // main game loop handling incrementing, times player held the ball and tracking throws
            while (true) {
                friends[index] += 1;

                if (friends[index] == M) { // handles game over
                    return counter;
                }

                // handles whether to pass left or right
                if (friends[index] % 1 == 0) {
                    index = (index - L + N) % N;
                } else if (friends[index] % 2 == 0) {
                    index = (index + L) % N;
                }
                counter++;
            }
            
            return counter;
        }
};