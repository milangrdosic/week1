#include "Inchworm.hpp"

int main() {
    Inchworm inchworm;

    int branch = 1000;
    int rest = 7;
    int leaf = 3;
    
    cout << "" << inchworm.lunchtime(branch, rest, leaf) << endl;

    return 0;
}