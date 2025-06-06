/*
Leetcode Q 326 -- Power of Three

Note:
    Have to be careful with the values returned from the pow() function.
        Pow() from <cmath> returns a double type, so we need to convert it to an int before performing operations with it on an int. 
    
    2147483647 is the max integer value. I had to keep the value resulting from the pow() function below this for my conversion from double to int 
    to work properly.  
        IE) Program works at 3^17 but not at 3^25!
        Integers in C++ work in a 32 bit integer range.
*/
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
    public:
        bool isPowerOfThree(int n) {  
            // We use an arbitrarily high number that is a power of 3 
            // as a reference point to ID if a given number is a power of 3.
            
            // BUT since pow() returns a double object, we need to convert it to an int 
            // to see if it will work with the given integer.
            double high_power = pow(3,17);
            cout << "is high power b4 conversion " << high_power << endl;
            // Method 1 of converting a double to an int -- type cast
            int higher_power = (int)high_power;
            // Method 2 of converting a double to an int -- rounding
            int highest_power = round(high_power);

            cout << "is the higher power val after conversion" << higher_power << endl;

            if (higher_power % n == 0) {
                return true;
            } else {
                return false;
            }
        }
};


int main() {

    int n = 27;
    Solution solution;
    bool is_pow3 = solution.isPowerOfThree(n);

    if (is_pow3 == true) {
        cout << "The value is a power of 3" << endl;
    } else {
        cout << "The value is not a power of 3" << endl;
    }

    return 0;
}