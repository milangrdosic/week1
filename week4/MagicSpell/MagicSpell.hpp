#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm> 

using namespace std;

class MagicSpell {
    public:
        string fixTheSpell(string spell) {
            vector<char> az;
            for (char c : spell) {
                if (c == 'A' || c == 'Z') {
                    az.push_back(c);
                }
            }

            reverse(az.begin(), az.end());

            size_t j = 0; 

            string result = "";

            for (char c : spell) {
                if (c == 'A' || c == 'Z') {
                    result += az[j++];
                } else {
                    result += c;
                }
            }

            return result;
        }
};
