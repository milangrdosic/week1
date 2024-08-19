#include <iostream>
#include <string>
#include <climits>
#include <map>

using namespace std;

class QuickSums {
    public:
        unordered_map<string, unordered_map<int, int>> memo; 

        int minSums(string numbers, int sum) {
            int result = helper(numbers, sum);
            return result; 
        }

    private:
        int helper(const string& numbers, int target) {
            cout << "num: " << numbers << " target: " << target << endl;
            if (memo[numbers].count(target))
                return memo[numbers][target];

            int n = numbers.size();
            long num = stol(numbers);
            if (num == target) 
                return memo[numbers][target] = 0;
            
            if (n == 1)
                return memo[numbers][target] = -1; 

            int minAdds = -1;

            for (int i = 1; i < n; ++i) {
                string left = numbers.substr(0, i);
                string right = numbers.substr(i);

                long leftNum = stol(left);
                
                if (leftNum > target) continue; 

                int rightResult = helper(right, target - leftNum);
                cout << leftNum << " | " << rightResult << endl;
                 
                if (rightResult != -1) { 
                    int totalAdds = 1 + rightResult;
                    if (minAdds == -1 || totalAdds < minAdds) 
                        minAdds = totalAdds;
                }
            }

            return memo[numbers][target] = minAdds; 
        }
};
