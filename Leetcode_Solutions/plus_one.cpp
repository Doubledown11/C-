/*
Leetcode Q 66 -- Plus One

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            
            // Case: When last val is a 9.
            if (digits.back() == 9) {

                // Make sure to check if prior vals are also a 9
                int x = 1;
                while (true) {
                    // ID how many 9s are present at the end of the vector.
                    if (digits.at(digits.size() - 1 - x) == 9) {
                        x++;
                    } else {
                        int nines = 0;
                        // Flip all 9s to 0s.

                        for (int y = 0; y < x; y++) {
                            digits.at(digits.size() - 1 - y) = 0;
                            nines++;
                        }

                        
                        // Flip the value to the left of the sequence of 9s up 1 value.
                        digits.at(digits.size() - 1 - nines)++;                         
                       
                        return digits;
                    }
                }
            }
            // Case: just have to increment the final index in the list 
            else {
                digits.back()++;
            }
            return digits;
        }
};

int main() {
    Solution solution;
    vector<int> digits = {1,1,9,9,9};
    // Vector b4 plusOne().
    for (int x = 0; x < digits.size(); x++) {
        cout << digits[x] << ' ';
    }
    cout << "\n\n";
    vector<int> digit_plus_one = solution.plusOne(digits);
    // Vector after plusOne().
    for (int x = 0; x < digit_plus_one.size(); x++) {
        cout << digit_plus_one[x] << ' ';
    }
    return 0;
}