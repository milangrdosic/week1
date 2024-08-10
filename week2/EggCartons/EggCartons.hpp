#include <iostream>

using namespace std;

class EggCartons {
    public:
        int minCartons(int n) {
            int sum = 0;

            // 6 loop
            for (int i = 0; i <= n / 6; i++) {
                sum = 6*i;
                for (int j = 1; j < n / 6; j++) {
                    sum += 8;
                    cout << "sum: " << sum << endl;
                    cout << "i: " << i << "j: " << j << endl;
                    if(sum == n) {
                        cout << sum << endl;
                        return i+j;
                    }
                }
                sum = 0;
            }
            
            // 8 loop
            for (int i = 0; i <= n / 8; i++) {
                sum = 8*i;
                for (int j = 1; j < n / 8; j++) {
                    sum += 6;
                    cout << "sum" << sum << endl;
                    cout << "i: " << i << "j: " << j << endl;
                    if(sum == n) {
                        cout << sum << endl;
                        return i+j;
                    }
                }

                sum = 0;
            }

            // if that doesnt work, check direct division
            if (n % 8 == 0) {
                return n / 8;
            }
            if (n % 6 == 0) {
                return n / 6;
            }

            return -1;

        }
};