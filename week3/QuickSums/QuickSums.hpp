#include <iostream>
#include <string>
#include <climits>

using namespace std;

class QuickSums {
public:
    int minSums(string numbers, int sum) {
        return helper(numbers, sum);
    }

private:
    int helper(const string& numbers, int target) {
        int n = numbers.size();
        long num = stol(numbers);
        if (num == target) {
            return 0;
        }
        
        if (n == 1) {
            return -1;
        }

        int minAdds = -1;  

        for (int i = 1; i < n; ++i) {
            string left = numbers.substr(0, i);
            string right = numbers.substr(i);

            long leftNum = stol(left);
            
            if (leftNum > target) continue; 

            int rightResult = helper(right, target - leftNum);

             
            if (rightResult != -1) {
                int totalAdds = 1 + rightResult;
                if (minAdds == -1 || totalAdds < minAdds) { 
                    minAdds = totalAdds;
                }
            }
        }

        return minAdds; 
    }
};