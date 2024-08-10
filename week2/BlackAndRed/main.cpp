#include "BlackAndRed.hpp"

int main() {
    BlackAndRed br;
    cout << br.cut("BRBRBR") << endl;       
    cout << br.cut("RBRBRB") << endl;       
    cout << br.cut("BBBRRRRB") << endl;    
    cout << br.cut("BR") << endl;           
    cout << br.cut("RBRBBRRRRBBBRBBRRBRBBRRRBRBBBRBRBRBRBRRB") << endl; 
    return 0;
}