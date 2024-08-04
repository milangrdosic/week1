#include <iostream>
#include <stdlib.h>

using namespace std;

class StreetParking {
    public:
        int freeParks(string Street) {
            int count = 0;
            int size = Street.length();
            cout << size << endl;

            for (int i = 0; i < size; i++) {
                if ( i == 0) { // check if its at the start of the street
                    if ( Street[i] == 'B' ||  Street[i] == 'D' || Street[i] == 'S') { // check if the driver is infornt of a bus stop, side street or driveway
                    }
                    else {
                        if ( Street[i+2] == 'B' || Street[i+1] == 'B' || Street[i+1] == 'S') { // check if they are too close to a bustop or side street
                        } else {
                            count++;
                        }
                    }
                }
                else {
                    if ( Street[i] == 'B' ||  Street[i] == 'D' || Street[i] == 'S') { // check if the driver is infornt of a bus stop, side street or driveway
                    }
                    else {
                        if ( Street[i+2] == 'B' || Street[i+1] == 'B' || Street[i+1] == 'S') { // check if they are too close to a bustop or side street
                        } else {
                            if ( Street[i-1] == 'S' ) { // check if the driver is 5m front side street
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