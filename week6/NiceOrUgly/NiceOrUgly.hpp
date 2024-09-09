#include <iostream>
#include <string>

using namespace std;

class NiceOrUgly {
public:
    string describe(string s) {
        string allVowels = replaceQuestionMarks(s, true);
        string allConsonants = replaceQuestionMarks(s, false);
        string adaptiveReplace = adaptiveQuestionMarks(s);
        string adaptiveEndReplace = adaptiveQuestionMarksFromEnd(s);
        

        bool isAllVowelsUgly = isUgly(allVowels);
        bool isAllConsonantsUgly = isUgly(allConsonants);
        bool isAdaptiveUgly = isUgly(adaptiveReplace);
        bool isAdaptiveEndUgly = isUgly(adaptiveEndReplace);
        
        if (isAllVowelsUgly && isAllConsonantsUgly && isAdaptiveUgly && isAdaptiveEndUgly) {
            return "UGLY";
        } else if (!isAllVowelsUgly && !isAllConsonantsUgly && !isAdaptiveUgly && !isAdaptiveEndUgly) {
            return "NICE";
        } else {
            return "42";
        }
    }

private:
    string adaptiveQuestionMarksFromEnd(string s) {
        int vowelCount = 0, consonantCount = 0;
        // Traverse from the end to the start
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '?') {
                if (vowelCount >= 2) { 
                    s[i] = 'Z';
                    vowelCount = 0; 
                    consonantCount = 1;
                } else if (consonantCount >= 4) { 
                    s[i] = 'A';
                    consonantCount = 0;
                    vowelCount = 1;
                } else {

                    s[i] = 'Z';
                    consonantCount++;
                    vowelCount = 0;
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
    string replaceQuestionMarks(const string& s, bool useVowel) {
        string result = s;
        for (char& c : result) {
            if (c == '?') {
                c = useVowel ? 'A' : 'Z';
            }
        }
        return result;
    }

    string adaptiveQuestionMarks(string s) {
        int vowelCount = 0, consonantCount = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '?') {
                if (vowelCount >= 2) {
                    s[i] = 'Z';
                    vowelCount = 0;
                    consonantCount = 1;
                } else if (consonantCount >= 4) { 
                    s[i] = 'A';
                    consonantCount = 0;
                    vowelCount = 1;
                } else {
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

