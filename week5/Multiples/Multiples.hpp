#include <iostream> 

using namespace std;

class Multiples {
    public:
        int number(signed long long int min, signed long long int max, int factor) {
            int count = 0;
            for(auto i = min; i <= max; i++) {
                if ( i % factor == 0) {
                    count++;
                }
            }
            return count;
        }
};