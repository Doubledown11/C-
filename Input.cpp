#include <iostream>
using namespace std;
int main() {
    cout << "Please enter a number: " << endl; 
        // Ask the user to type a number. 

    int y;
    
    
    int x; 
        // Declare the var which will hold the user
        // defined value.


    cin >> x;
        // Get user defined value.

    cout << "Here is your number, plus 1: " << x+1 << endl;
    system("pause");
    std::cin.get(); // Clears the input buffer and then waits for the user 
    // to press enter.
    return 0;
}


// I got the idea for the system("pause") line from the following link:
// https://cplusplus.com/forum/beginner/207701/
   





