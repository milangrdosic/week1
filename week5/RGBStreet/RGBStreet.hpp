#include <iostream>
#include <vector>
#include <sstream>
#include <climits>

using namespace std;

class RGBStreet {
private:
    vector<vector<int>> memo;
    vector<vector<int>> costs;

    int minCost(int house, int lastColor) {
        if (house >= costs.size()) return 0;  
        if (memo[house][lastColor] != -1) return memo[house][lastColor];

        int result = INT_MAX;
  
        for (int color = 0; color < 3; color++) {
            if (color != lastColor) {
                result = min(result, costs[house][color] + minCost(house + 1, color));
            }
        }
        memo[house][lastColor] = result;
        return result;
    }

public:
    int estimateCost(vector<string> houses) {
        int n = houses.size();
        costs.resize(n, vector<int>(3));
        memo.assign(n, vector<int>(4, -1)); 

        for (int i = 0; i < n; i++) {
            stringstream ss(houses[i]);
            ss >> costs[i][0] >> costs[i][1] >> costs[i][2];
        }

        return minCost(0, 3);
    }
};

