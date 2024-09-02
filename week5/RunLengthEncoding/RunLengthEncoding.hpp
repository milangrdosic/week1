#include <iostream>
#include <sstream>
#include <cctype>  

using namespace std;

class RunLengthEncoding {
public:
    string decode(string text) {
        string result;
        string numStr; 
        int currentNum = 0;
        bool collectingDigits = false; 

        for (char c : text) {
            if (isdigit(c)) { 
                numStr += c;
                collectingDigits = true;
            } else { 
                if (collectingDigits) { 
                    currentNum = stoi(numStr);
                    numStr = ""; 
                    collectingDigits = false;
                } else {
                    currentNum = 1; 
                }

                if (result.length() + currentNum > 50) { 
                    return "TOO LONG";
                }
                result.append(currentNum, c);
            }
        }

        return result;
    }
};