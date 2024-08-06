#include <iostream>
#include <vector>
using namespace std;

class CircularLine {
public:
    int longestTravel(vector<int> t) {
        int size = t.size(); // Get the size of the vector
        int slowest_time = 0;

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size + i; j++) {
                int clockwiseTime = 0;

                for (int k = i; k < j; k++) {
                    clockwiseTime += t[k % size];
                }

                int counterClockTime = 0;
                for (int k = j % size; k != i; k = (k + 1) % size) {
                    counterClockTime += t[k];
                }

                int shortest_time = (clockwiseTime < counterClockTime) ? clockwiseTime : counterClockTime;

                if (shortest_time > slowest_time) {
                    slowest_time = shortest_time;
                }
            }
        }

        return slowest_time;
    }
};