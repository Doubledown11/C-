/*
Leetcode Q 263 -- Ugly Number

Ugly number is a number that does not have a prime factor other than 2,3, and 5.

Return true if it is an ugly number!
*/
#include <iostream>
using namespace std;

class Solution {
    public:
        bool isUgly(int n) {
            
        }
};


int main() {
    int n = 6;
    Solution solution;
    bool is_ugly = solution.isUgly(n);

    if (is_ugly == true) {
        cout << "The given integer is an ugly number!" << endl;
    } else {
        cout << "The given integer is not an ugly number!" << endl;
    }

    return 0;
}