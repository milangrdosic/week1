#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

class SecondChild {
    public:
        string chooseName(string Father, string Mather, string Child1, string Gender) {
            string Child1Gender = "";
            string Child2 = "";
            string firstName, lastName;

            if (Child1[0] == 'A' || Child1[0] == 'E' || Child1[0] == 'E' || Child1[0] == 'O' || Child1[0] == 'U' || Child1[0] == 'Y' ) {
                Child1Gender = "Girl";
            } else {
                Child1Gender = "Boy";
            }

            if (Child1Gender != Gender) {
                if(Gender == "Boy") {
                    stringstream ssF(Father);
                    ssF >> firstName;
                    ssF >> lastName;
                    Child2 = lastName + " " + firstName;
                }else {
                    stringstream ssM(Mather);
                    ssM >> firstName;
                    ssM >> lastName;
                    Child2 = lastName + " " + firstName;
                }
            } else {
                if(Child1Gender == "Boy") {
                    stringstream ssF(Father);
                    stringstream ssC(Child1);
                    ssF >> firstName;
                    ssC >> lastName;
                    ssC >> lastName;

                    Child2 += firstName + " " + lastName; 
                }else {
                    stringstream ssM(Mather);
                    stringstream ssC(Child1);
                    ssM >> firstName;
                    ssC >> lastName;
                    ssC >> lastName;

                    Child2 += firstName + " " + lastName; 
                }
            }
            return Child2;
        }
};