#include "StreetParking.hpp"

int main() {
    StreetParking streetParking;
    string Street = "---B--S-D--S--";

    cout << streetParking.freeParks(Street) << endl;
    return 0;
}