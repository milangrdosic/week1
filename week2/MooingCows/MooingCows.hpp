#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class MooingCows {
public:
    int dissatisfaction(vector<string> farmland) {
        int n = farmland.size();
        int m = farmland[0].size();
        int min_dissatisfaction = INT_MAX;

        // Iterate through each cow
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (farmland[x][y] == 'C') {
                    int total_dissatisfaction = 0;

                    // Calculate dissatisfaction caused to all other cows
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (farmland[i][j] == 'C' && !(i == x && j == y)) {
                                int dist_squared = (x - i) * (x - i) + (y - j) * (y - j);
                                total_dissatisfaction += dist_squared;
                            }
                        }
                    }

                    // Update the minimum dissatisfaction
                    if (total_dissatisfaction < min_dissatisfaction) {
                        min_dissatisfaction = total_dissatisfaction;
                    }
                }
            }
        }

        return min_dissatisfaction;
    }
};