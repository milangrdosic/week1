#include "RGBStreet.hpp"

int main() {
    RGBStreet obj;
    vector<string> houses = {"71 39 44", "32 83 55", "51 37 63", "89 29 100", 
        "83 58 11", "65 13 15", "47 25 29", "60 66 19"};
    cout << "Minimum cost to paint all houses: " << obj.estimateCost(houses) << endl;
    return 0;
}