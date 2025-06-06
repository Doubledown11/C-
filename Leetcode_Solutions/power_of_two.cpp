/*
Leetcode Q 231 -- Power of Two

Given an integer n, return true if it is a power of 2.
Which is when there exists an integer that n == 2^x

This question has 2 solution methods below 
    1) A recursive method 
    2) Another an iterative method
*/

#include <iostream>
#include <cmath>

using namespace std;


class Solution {
    public:
        bool isPowerOfTwo_recursive(int n) {
            // Base Cases: If our n value has decreased to 0 or 1.
            if (n <= 0) {
                return false;
            } else if (n == 1) {
                return true;
            }

            return ((n % 2 == 0) && isPowerOfTwo_recursive(n/2));   
        }


        bool isPowerOfTwo_iterative(int n) {
            int n_ = 0;
            while (n_ <= n) {
                if (pow(2, n_) == n) {
                    return true;
                }
                else {
                    n_++;
                }
            }  

            // If we are able to iterate through all numbers from n/2 until 1, 
            // we return false.
            return false;
        }
};
int main() {

    int n = 1;
    Solution solution;
    bool is_pow_recurs = solution.isPowerOfTwo_recursive(n);
    bool is_pow_iter = solution.isPowerOfTwo_iterative(n);

    cout << "From recursive function: " << endl;
    if (is_pow_recurs == true) {
        cout << "The value is a power of 2!" << endl;
    } else {
        cout << "The value is not a power of 2!" << endl;
    }
    cout << "\n\n" << endl;

    cout << "From iterative function: " << endl;
    if (is_pow_iter == true) {
        cout << "The value is a power of 2!" << endl;
    } else {
        cout << "The value is not a power of 2!" << endl;
    }

    return 0;
}