#include <iostream>
using namespace std;

 
 
class Inchworm
{
  public:
  int lunchtime(int branch, int rest, int leaf)
  {

    if( branch > 1000000 || rest > 1000 || leaf > 1000) {
        return 0;
    }
    // your code for the problem
    int rests[1000] = {};
    int restSize = 0; // to ensure propper handling of leaf eaten counting 
    int leaves[1000] = {};
    int leaveSize = 0;

    rests[0] = 0;
    leaves[0] = 0;

    // initialize rests array
    for (int i = 1; i <= branch; i++) {
        if ( rest * i > branch ) {
            break;
        } else { 
            rests[i] = i * rest;
            restSize++;
        }
    }


    // initialize leaves array
    for (int i = 1; i <= branch; i++) {
        if ( leaf * i > branch ) {
            break;
        } else { 
            leaves[i] = i * leaf;
            leaveSize++;
        }
    }


    int res = 0;

    // find leaves eaten
    for (int i = 0; i <= restSize; i++) {
        for (int j = 0; j <= leaveSize; j++) {
            if ( rests[i] == leaves[j] ) {
                res++;
            }
        }   
    }

    return res;  // return your result
  }
};


