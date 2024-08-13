#include "SecondChild.hpp"

int main() {
    SecondChild Name;
    string Father = "Mohammad Reza";
    string Mather = "Yasaman Sadat";
    string Child1 = "Baqer Ali";
    string Gender = "Girl";

    cout << Name.chooseName(Father, Mather, Child1, Gender) << endl;
}