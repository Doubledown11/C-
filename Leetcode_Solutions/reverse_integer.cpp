/*
Leetcode 7 - Reverse Integer

Reverse the digits of an integer, but if it goes above 32-bit int range, return 0.
So, no values above 2,147,483,647 or below -2,147,483,647.

I had to use string stream to convert a char type to a string.   

*/
#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

class Solution {
    public:
        int reverse(int x) {
            string n = to_string(x);
            cout << "X: " << x << endl;
            cout << "n: " << n << endl;

            int left = 0;
            int right = n.size() - 1;

            // Check if int is signed.
            if (n[0] == '-') {
                left++;
            } 

            while (left < right) {
                char temp = n[left];
                n[left] = n[right];
                // I used stringstream to convert the char at temp to a string.
                // Create stringstream object.
                stringstream ss;
                
                // Insert the temp char into the ss object.
                ss << temp;

                // Extract the string from the ss object.
                ss >> temp;  

                n[right] = temp;


                left++;
                right--;
            }

            // Check if bigger/smaller then 32 bit int range.
            if (stoi(n) > INT32_MAX) {
                return 0;
            } else {
                return stoi(n);
            }
        }
};

int main() {
    Solution solution;
    int x = 457; 

    int reversed = solution.reverse(x);
    cout << "The reversed integer is: " << reversed << endl;

    return 0;
}