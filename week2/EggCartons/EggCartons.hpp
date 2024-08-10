#include <iostream>

using namespace std;

class EggCartons {
    public:
        int minCartons(int n) {
            int sum = 0;

            if (n % 8 == 0) {
                cout << "n % 8" << endl;
                return n / 8;
            }
            if (n % 6 == 0) {
                cout << "n % 6" << endl;
                return n / 6;
            }

            for (int i = 0; i <= n / 6; i++) {
                sum = 6;
                for (int j = 1; j < n / 6; j++) {
                    sum += 8*i;
                    if(sum == n) {
                    return i+j;
                    }
                }
                sum = 0;
            }
            
            for (int i = 0; i <= n / 6; i++) {
                sum = 8;
                for (int j = 1; j < n / 6; j++) {
                    sum += 6*i;
                    if(sum == n) {
                    return i+j;
                    }
                }

                sum = 0;
            }

            return -1;

        }
};