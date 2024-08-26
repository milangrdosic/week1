#include <iostream>
#include <cmath>

class RugSizes {
public:
    int rugCount(int area) {
        int count = 0;
        for (int width = 1; width <= sqrt(area); ++width) {
            if (area % width == 0) {
                int length = area / width;
                if (width != length && (width % 2 == 0 && length % 2 == 0)) {
                    continue; 
                }
                count++;
            }
        }
        return count;
    }
};