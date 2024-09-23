#include <string>
#include <vector>
#include <sstream>
#include <iostream>

class LostParentheses {
public:
    int minResult(const std::string& e) {
        std::vector<std::string> subtractParts = split(e, '-');

        int total = sumOfNumbers(subtractParts[0]);

        for (size_t i = 1; i < subtractParts.size(); ++i) {
            total -= sumOfNumbers(subtractParts[i]);
        }

        return total;
    }

private:

    std::vector<std::string> split(const std::string& s, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::stringstream ss(s);

        while (std::getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }

        return tokens;
    }

    int sumOfNumbers(const std::string& expression) {
        std::vector<std::string> addParts = split(expression, '+');
        int sum = 0;
        for (const std::string& numStr : addParts) {
            sum += std::stoi(numStr);
        }
        return sum;
    }
};
