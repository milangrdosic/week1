#include <iostream>
#include <stdlib.h>

using namespace std;

class NiceOrUgly {
    public:
        string describe(string s) {
            bool ugly = false, canBeNice = true;
            int size = s.length();

            int totalCases = 1 << count(s.begin(), s.end(), '?');
            for (int mask = 0; mask < totalCases; mask++) {
                string testStr = s;
                int questionIndex = 0;
                for (int i = 0; i < size; i++) {
                    if (s[i] == '?') {
                        if (mask & (1 << questionIndex)) {
                            testStr[i] = 'O'; 
                        } else {
                            testStr[i] = 'Z'; 
                        }
                        questionIndex++;
                    }
                }
                if (isUgly(testStr)) {
                    ugly = true;
                } else {
                    canBeNice = false; 
                }
            }

            if (ugly && !canBeNice) {
                return "UGLY";
            } else if (!ugly && canBeNice) {
                return "NICE";
            } else {
                return "42"; 
            }
        }

    private:
        bool isUgly(const string& str) {
            int vowelCount = 0;
            int consonantCount = 0;
            for (char ch : str) {
                if (isVowel(ch)) {
                    vowelCount++;
                    consonantCount = 0;
                } else {
                    consonantCount++;
                    vowelCount = 0;
                }
                if (vowelCount == 3 || consonantCount == 5) {
                    return true;
                }
            }
            return false;
        }

        bool isVowel(char c) {
            return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        }
};