/*
Leetcode Q 9 -- Palindrome Number

*/
#include <iostream>
using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {

            // get 2 strings one iter forwards other iter backwards

            // use 2 pointers at start and at back and compare each val 

            // Pointer for the start of the list.
            int y = 0;
            int z = to_string(x).size() - 1;

            while (y <= z) {
                cout << to_string(x)[y] << " is the y value " << endl;
                cout << to_string(x)[z] << " is the z value " << endl;
                    
                // Compare characters at both pointers.
                if (to_string(x)[y] != to_string(x)[z]) {
                    return false;
                }

                // Else we can inc/dec both of the pointers. 
                y++;
                z--;
            }

            return true;
        }
};




int main() {
    /*
    Main Function.
    */

    // Init the solution 
    Solution solution; 

    // Def the int variable.
    int x = 12233221;

    // TODO also need to implemented checks in solution function 
    // for when there is a negative sign.


    bool isP = solution.isPalindrome(x);
    if (isP) {
        cout << "The given integer is palindrome!" << endl;
    } else {
        cout << "The given integer is not a palindrome!" << endl;
    }

    return 0;
}



