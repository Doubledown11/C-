/*
Leetcode Q 258 -- Add Digits

Given an integer num, repeatedly add all the digits until the result has 
only 1 digit and return it!

*/
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
    public:
        int addDigits(int num) {
            int number = num;

            while (true) {
                // Turn the num into a string.
                string num_str = to_string(number);
                int counter = 0;
                
                // iterate through each digit in str_num:
                for (int x = 0; x < num_str.size(); x++) {
                    // turn each char back into an integer.
                    int char_to_int = num_str[x] - '0';
                    counter += char_to_int;
                }

                if (to_string(counter).size() == 1) {
                    return counter;
                }

                number = counter;
            }
        }
};

int main() {
    int num = 38;
    Solution solution;
    int sum = solution.addDigits(num);
    
    cout << "The result of the process is: " << sum << endl;

    return 0;
}