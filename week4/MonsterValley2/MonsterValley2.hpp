#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int minimumPrice(vector<int> dread, vector<int> price) {
    int n = dread.size();
    map<long long, int> manao; 

    manao[dread[0]] = price[0];

    for (int i = 1; i < n; ++i) {
        map<long long, int> newMonster;

        for (auto &[scariness, cost] : manao) {
            long long new_scariness = scariness + dread[i];
            int new_cost = cost + price[i];

            if (!newMonster.count(new_scariness) || newMonster[new_scariness] > new_cost) {
                newMonster[new_scariness] = new_cost;
            }

            if (scariness > dread[i]) {
                if (!newMonster.count(scariness) || newMonster[scariness] > cost) {
                    newMonster[scariness] = cost;
                }
            }
        }

        manao.swap(newMonster);
    }

    int min_cost = INT_MAX;
    for (auto &[scariness, cost] : manao) {
        if (cost < min_cost) {
            min_cost = cost;
        }
    }

    return min_cost;
}
