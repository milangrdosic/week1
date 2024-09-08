#include <iostream>
#include <string>

using namespace std;

class BlackAndWhiteSolitaire {
    public:
        int minimumTurns(string cardFront) {
            int N = cardFront.length();
            string cardFront2 = cardFront;
            string curr = "";
            string prev = "";
            string next = "";
            int flips1 = 0;
            int flips2 = 0;

            for(int i = 0; i <= N; i++) {
                curr = cardFront[i];
                if(curr == prev) {
                    if(curr == "B") {
                        cardFront[i] += 21;
                        curr = cardFront[i];
                        flips1++;
                    } else {
                        cardFront[i] -= 21;
                        curr = cardFront[i];
                        flips1++;
                    }
                }
                prev = curr;
            }

            if(cardFront2[0] == 'B') {
                cardFront2[0] += 21;
                flips2++;
            } else {
                cardFront2[0] -= 21;
                flips2++;
            }

                

            for(int i = 0; i < N; i++) {
            curr = cardFront2[i];

            if(curr == prev) {
                if(curr == "B") {
                    cardFront2[i] += 21;
                    curr = cardFront2[i];
                    flips2++;
                } else {
                    cardFront2[i] -= 21;
                    curr = cardFront2[i];
                    flips2++;
                }
            }
            prev = curr;
            }



            if(flips2 < flips1) {
                return flips2;
            } else {
                return flips1;
            }
        }
};
