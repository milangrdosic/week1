#include <iostream>
#include <stdlib.h>

using namespace std;

class StreetParking {
    int freeParks(string Street) {
        int count = 0;
        int size = sizeof(Street);

        for (int i = 0; i < size; i++) {
            if ( i = 0) {
                if ( Street[i] == 'B' ||  Street[i] == 'D' || Street[i] == 'S') {
                    break;
                }
                else {
                    if ( Street[i+3] == 'B' || Street[i+1] == 'S') {
                        break;
                    } else {
                        count++;
                    }
                }
            }
            else {
                if ( Street[i] == 'B' ||  Street[i] == 'D' || Street[i] == 'S') {
                    break;
                }
                else {
                    if ( Street[i+3] == 'B' || Street[i+1] == 'S') {
                        break;
                    } else {
                        if ( Street[i-1] == 'S' ) {
                            break;
                        } else {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};