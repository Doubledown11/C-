/*
Leetcode Q 367 -- Valid Perfect Square

Given an integer return true if it is a perfect square. 
    Perfect Square: 
        An integer that is the square of an integer. 
        IE) Results from the product of an integer with itself.

This solution was to be done with no built in library functions.


I had to use the long long integer modification for the mid variable.
Integers in C++ can be modified by:
    Signedness: Signed, Unsigned.
    Size: Long, Short. 

Long integers have width of at least 32 bits.
Long Long? At least 64 bits. 

So, since long long is still an integer there is no need to make
conversions for operations between the various variables.

Source:
    https://en.cppreference.com/w/cpp/language/types
    https://leetcode.com/problems/valid-perfect-square/solutions/4523995/beats-100-binary-search-easiest-approach/

*/
#include <iostream>
using namespace std;

class Solution {
    public:
        bool isPerfectSquare(int num) {
    
            int low = 0;
            int high = num;

            while (low <= high) {
                cout << "High: " << high << endl;
                cout << "Low: " << low << endl;
                
                // C++ Auto truncates the result of the division.
                long long mid = low + (high - low) / 2;
                cout << "Mid+ " << mid << endl;

                // Check if mid*mid == num.
                if (mid * mid == num) {
                    return true;
                }

                // If mid*mid is lower then num.
                else if (mid * mid < num) {
                    // Reassign high and continue to the next loop.
                    low = mid + 1;
                }

                else if (mid * mid > num) {
                    high = mid - 1;
                }
            }
            return false;
        }
};

int main() {
    int num = 16;
    Solution solution; 

    bool is_perf_sq = solution.isPerfectSquare(num);

    if (is_perf_sq == true) {
        cout << "The given integer is a perfect square!" << endl;
    } else {
        cout << "The given integer is not a perfect square!" << endl;
    }

    return 0;
}