#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

class Reppity {
    public:
    int longestRep(string input) {
        int maxLength = 0;
        int n = input.size();

        for (int len = 1; len <= n / 2; ++len) {
            for (int i = 0; i <= n - 2 * len; ++i) {
                string pat = input.substr(i, len);

                for (int j = i + len; j <= n - len; ++j) {
                    if (input.substr(j, len) == pat) {
                        maxLength = max(maxLength, len);
                        break;
                    }
                }
            }
        }
        return maxLength;
    }
};