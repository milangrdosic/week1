#include <iostream>
#include <stdlib.h>

using namespace std;

class NiceOrUgly {
    public:
        string describe(string s) {
            bool ugly = 0, nice = 0, question = 0, perf = 1;
            int vowel = 0; int consonant = 0;
            int qCount = 0;
            int size = s.length();
            string sVow = s;
            string sCon = s;
            string sPerf = s;

            // ? check and string initialization
            for(int i = 0; i < size; i++) {
                if( s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                    vowel++;
                    consonant = 0;
                } else if (s[i] == '?') {
                    if(vowel >= 1) {
                        sPerf[i] = 'Z';
                        consonant++;
                    } else if (consonant > 1) {
                        sPerf[i] = 'O';
                        vowel++;
                    } else {
                        perf = 0;
                    }
                    qCount++;
                    question = true;
                    sVow[i] = 'O';
                    sCon[i] = 'Z';
                } else {
                    consonant++;
                    vowel = 0;
                }
            }
            
            vowel = 0;
            consonant = 0;
            if  (qCount == size && size > 3) {
                return "42";
            }

            // checking for consonants and vowels strings 
            if(question == true) {
                // vowel check
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

                // consonant check
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

                // // perfect s check
                // if (perf == true && nice != true) {
                //     for(int i = 0; i < size; i++) {
                //         if( sVow[i] == 'A' || sVow[i] == 'E' || sVow[i] == 'I' || sVow[i] == 'O' || sVow[i] == 'U') {
                //             vowel++;
                //             consonant = 0;
                //         } else {
                //             consonant++;
                //             vowel = 0;
                //         }
                //         if(consonant == 5 || vowel == 3) {
                //             ugly = true;
                //             break;
                //         }
                //     }

                    
                //     if(consonant != 5 && vowel != 3) { // NICE check
                //         nice = true;
                //     }
                // }

                
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
            if(nice != 1 && perf == 1) {
                nice = 1;
            }
            
            if(ugly == true && nice == true) {
                return "42";
            } else if (ugly == true) {
                return "UGLY";
            }
            return "NICE";
        }
};