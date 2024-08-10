#include <iostream>
#include <string>
using namespace std;

class BlackAndRed {
    public:
        int cut(string deck) {
            int size = deck.length();
            
            // Check each possible cut position
            for (int i = 0; i < size; i++) {
                int red = 0;
                int black = 0;
                bool valid = true;


                for (int j = 0; j < size; j++) {
                    int index = (i + j) % size; 
                    
                    if (deck[index] == 'R') {
                        red++;
                    } else if (deck[index] == 'B') {
                        black++;
                    }
                    
                    if (red > black) {
                        valid = false;
                        break;
                    }
                }
                

                if (valid) {
                    return i;
                }
            }
            

            return -1; 
        }
};