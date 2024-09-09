#include <iostream>
#include <stdlib.h>

using namespace std;

class NiceOrUgly {
    public:
        string describe(string s) {
            bool ugly = 0, nice = 0, question = 0;
            int vowel = 0; int consonant = 0;
            int qCount = 0;
            int size = s.length();
            string sVow = s;
            string sCon = s;

            // ? check and string initialization
            for(int i = 0; i < size; i++) {
                if(s[i] == '?') {
                    qCount++;
                    question = true;
                    sVow[i] = 'O';
                    sCon[i] = 'Z';
                }
            }
            if  (qCount == size && size > 3) {
                return "42";
            }

            // checking for consonants and vowels strings 
            if(question == true) {
                for(int i = 0; i < size; i++) {
                    if( sVow[i] == 'A' || sVow[i] == 'E' || sVow[i] == 'I' || sVow[i] == 'O' || sVow[i] == 'U') {
                        vowel++;
                        consonant = 0;
                    } else {
                        consonant++;
                        vowel = 0;
                    }
                    if(consonant == 5 || vowel == 3) {
                        ugly = true;
                        break;
                    }
                }

                if(consonant != 5 && vowel != 3) { // NICE check
                    nice = true;
                }

                consonant = 0;
                vowel = 0;

                for(int i = 0; i < size; i++) {
                    if( sCon[i] == 'A' || sCon[i] == 'E' || sCon[i] == 'I' || sCon[i] == 'O' || sCon[i] == 'U') {
                        vowel++;
                        consonant = 0;
                    } else {
                        consonant++;
                        vowel = 0;
                    }
                    if(consonant == 5 || vowel == 3) {
                        ugly = true;
                        break;
                    }
                }
                if(consonant != 5 && vowel != 3) {
                    nice = true;
                }
                consonant = 0;
                vowel = 0;
                
            } else {
                for(int i = 0; i < size; i++) {
                    if( s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                        vowel++;
                        consonant = 0;
                    } else {
                        consonant++;
                        vowel = 0;
                    }
                    if(consonant == 5 || vowel == 3) {
                        ugly = true;
                        break;
                    }
                }
            }

            if(ugly == true && nice == true) {
                return "42";
            } else if (ugly == true) {
                return "UGLY";
            }
            return "NICE";
        }
};