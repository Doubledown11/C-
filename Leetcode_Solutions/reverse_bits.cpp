/*
Leetcode Q 190 -- Reverse Bits

*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            // Convert to string 
            string bin_str = to_string(n);
            cout << "The string bin is: " << bin_str << endl;

            // Iterate through string char by char add to a vector 
            for (int x = 0; x < bin_str.size(); x++) {
                cout << "The current char in bin_str: " << bin_str[x] << endl;
                if (bin_str[x] == '1') {
                    bin_str[x] = '0';
                } else {
                    bin_str[x] = '1';
                }
            } 
            
            // Convert back to int type here.
            int bin_reversed = stoi(bin_str);
            return bin_reversed;
        }
};


int main() {
    int n = 000000101001010;

    Solution solution;
    int m = solution.reverseBits(n);

    cout << "The reversed integer is: " << m << endl;

    return 0;
}