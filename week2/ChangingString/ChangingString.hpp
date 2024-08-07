#include <iostream>
#include <stdlib.h>
#include <cstdlib> 
#include <vector>

using namespace std;

class ChangingString {
public:
    int distance(string A, string B, int K) {
        int len = A.length();
        vector<int> differences(len);

        for (int j = 0; j < len; ++j) {
            differences[j] = abs(A[j] - B[j]);
        }

        sort(differences.begin(), differences.end(), greater<int>());

        if (differences[1] == 0 && K > 0) {
            return K * 1;  
        }

        for (int i = 0; i < K; ++i) {
            differences[i] = 0;
        }

        int totalDistance = 0;
        for (int diff : differences) {
            totalDistance += diff;
        }

        return totalDistance;
    }
};