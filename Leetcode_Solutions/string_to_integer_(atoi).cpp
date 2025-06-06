/*
Leetcode 8 - String to Integer (atoi)

I used if (char < 33) to ID if a char was a whitespace character. 
    As all whitespace chars are found below 33, this should work.

Source: 
    https://www.sololearn.com/en/Discuss/2121802/c-how-to-find-a-space-in-a-string 

*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
    public:
        int myAtoi(string s) {
            // Remove any leading whitespaces:
            int start_idx = 0;
            while (true) {
                // Below checks if the char's ASCII integer is below 33. 
                // As all whitespace chars are found below 33, this should work. 
                if (s[start_idx] < 33) {
                    start_idx++;
                } else {
                    break;
                }
            }

            // Check the sign:
            bool is_neg = false;
            if (s[start_idx] == '-') {
                // If negative, we will move past the sign for now.
                is_neg = true;
                start_idx++;
            }

            // Convert the remaing string to its integer form:
            string convert;
            for (int x = start_idx; x < s.size(); x++) {
                convert.push_back(s[x]);
            } 
            int converted = stoi(convert);

            // Perform rounding to the 32 bit integer range.
            if (converted > 2147483648) {
                converted = 2147483648;
            } 

            
            if (is_neg) {
                converted = stoi(to_string(converted).insert(0, "-"));
                return converted;
            } 

            else {
                return converted;
            }
        
        }
};


int main() {
    Solution solution;
    string s = "42";

    int int_result = solution.myAtoi(s);

    cout << "The result of the string to integer function is: " << int_result << endl;

    return 0;
}