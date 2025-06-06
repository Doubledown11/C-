/*
Leetcode 5 - Longest Palindromic Substring.

Great question on analyzing substrings, subarrays, subsequences...  

Got my substring/subarray/subsequence method from 
Source:
    https://www.geeksforgeeks.org/generating-subarrays-using-recursion/

*/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


class Solution {
    public:
        string longestPalindrome(string s) {
            // Use two pointers 
            vector<string> substrings; 
            string longest_substring;

            // Iterate through the string and add the chars inside to a vector.
            vector<char> characters;
            for (int x = 0; x < s.size(); x++) {
                characters.push_back(s[x]);
            }

            cout << " the char vector is: " << endl;
            for (int x = 0; x<characters.size(); x++) {
                cout << characters[x] << " ";
            }
            cout << endl;

            // Iterate through the characters vector 
            // The outer loop IDs the start of a subarray.
            for (int x = 0; x < characters.size(); x++) {
                string substring;

                // The inner loop IDs the end of a subarray.
                for (int y = 0; y < characters.size(); y++) {
                    // If we have previously initiated the process from an inner letter, 
                    // we skip y ahead until we reach where the x pointer is at. 
                    if (y < x) {
                        continue;
                    } 

                    // Create a substring between where x and y pointers are.
                    substring.push_back(characters[y]);
                    cout << "After pushing char to substring: " << substring << endl;

                    // After creating a new substring, we check to see if it is palindromic.
                    int left = 0;
                    int right = substring.size() - 1;
                    bool is_pali = true; 

                    while (left < right) {
                        if (substring[left] != substring[right]) {
                            is_pali = false;
                            break;
                        }
                        left++;
                        right--;
                    }

                    if (is_pali == true) {
                        substrings.push_back(substring);
                    }
                }
            }

            // After we have found all palindromic substrings, we need to find the biggest one.
            int biggest_size = 0;
            string biggest_string;

            for (int x = 0; x < substrings.size(); x++) {
                if (substrings[x].size() > biggest_size) {
                    biggest_size = substrings[x].size();
                    biggest_string = substrings[x];
                }
            }
            return biggest_string;
        }
};

int main () {
    Solution solution; 

    string s = "racecar";

    string longest_pali_substr = solution.longestPalindrome(s);

    cout << "The longest palindromic substring is: " << longest_pali_substr << endl;

    return 0;
}