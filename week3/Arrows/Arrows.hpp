#include <iostream>
#include <stdlib.h>

using namespace std;

class Arrows {
    public:
        int longestArrow(string s) {
            int size = s.length();
            int leftIndex = -1;
            int rightIndex = -1;
            int arrowCounter = 0;
            int length = -1;
            

            // left arrows
            for (int i = 0; i <= size; i++) {
                for (int j = i; j <= size; j++) {
                    if (s[j] == '<') {
                        leftIndex = j;
                        arrowCounter++; // arrows found and counter incremented
                        break;
                    }
                }

                // if statement to check if arrows was found
                if(leftIndex != -1) {
                    for (int j = leftIndex+1; j <= size; j++) {
                        if (s[j] == '-') {
                            arrowCounter++;
                        
                        }
                        else {
                            break;
                        }
                    }

                    if (arrowCounter > length) {
                        length = arrowCounter;
                    }
                    arrowCounter = 1; // reset back to 1 (as '<' was counted)

                    for (int j = leftIndex+1; j <= size; j++) {
                        if (s[j] == '=') {
                            arrowCounter++;
                        }
                        else {
                            break;
                        }
                    }

                    if (arrowCounter > length) {
                        length = arrowCounter;
                    }
                    arrowCounter = 0;
                }
                
            }

            // right arrows
            for (int i = 0; i <= size; i++) {
                for (int j = i; j <= size; j++) {
                    if (s[j] == '>') {
                        rightIndex = j;
                        arrowCounter++;
                        break;
                    }
                }
                if(rightIndex != -1) {
                    for (int j = rightIndex-1; j >= 0; j--) {
                        if (s[j] == '-') {
                            arrowCounter++;
                        }
                        else {
                            break;
                        }
                    }

                    if (arrowCounter > length) {
                        length = arrowCounter;
                    }
                    arrowCounter = 1;

                    for (int j = rightIndex-1; j >= 0; j--) {
                        if (s[j] == '=') {
                            arrowCounter++;
                        }
                        else {
                              
                            break;
                        }
                    }

                    if (arrowCounter > length) {
                        length = arrowCounter;
                    }
                    arrowCounter = 0;
                }
                
            }

            return length;
        }
};