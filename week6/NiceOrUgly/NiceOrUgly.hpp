#include <iostream>
#include <string>

using namespace std;

class NiceOrUgly {
public:
    string describe(string s) {
        string allVowels = replaceQuestionMarks(s, true);
        string allConsonants = replaceQuestionMarks(s, false);
        string adaptiveReplace = adaptiveQuestionMarks(s);

        bool isAllVowelsUgly = isUgly(allVowels);
        bool isAllConsonantsUgly = isUgly(allConsonants);
        bool isAdaptiveUgly = isUgly(adaptiveReplace);

        if (isAllVowelsUgly && isAllConsonantsUgly && isAdaptiveUgly) {
            return "UGLY";
        } else if (!isAllVowelsUgly && !isAllConsonantsUgly && !isAdaptiveUgly) {
            return "NICE";
        } else {
            return "42";
        }
    }

private:
    // Replace all '?' with vowels or consonants uniformly
    string replaceQuestionMarks(const string& s, bool useVowel) {
        string result = s;
        for (char& c : result) {
            if (c == '?') {
                c = useVowel ? 'A' : 'Z';
            }
        }
        return result;
    }

    // Adaptively replace '?' based on the context to prevent sequences of vowels or consonants
    string adaptiveQuestionMarks(string s) {
        int vowelCount = 0, consonantCount = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '?') {
                if (vowelCount >= 2) { // already 2 vowels, place a consonant
                    s[i] = 'Z';
                    vowelCount = 0;
                    consonantCount = 1;
                } else if (consonantCount >= 4) { // already 4 consonants, place a vowel
                    s[i] = 'A';
                    consonantCount = 0;
                    vowelCount = 1;
                } else {
                    // place a vowel by default if not in danger of becoming ugly
                    s[i] = 'A';
                    vowelCount++;
                    consonantCount = 0;
                }
            } else {
                if (isVowel(s[i])) {
                    vowelCount++;
                    consonantCount = 0;
                } else {
                    consonantCount++;
                    vowelCount = 0;
                }
            }
        }
        return s;
    }

    bool isUgly(string str) {
        int vowelCount = 0, consonantCount = 0;
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

