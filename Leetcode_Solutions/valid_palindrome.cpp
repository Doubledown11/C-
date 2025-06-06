/*
Leetcode 125 -- Valid Palindrome

Need to ID if characters are in upper/lowercase
to do so I used the cctype header files isupper() function.
If in uppercase I then had to convert them to lowercase with the tolwer() function.
I also need to filter out non-alphanumeric characters and I use the isalnum() function.
    BUT to use isalnum() we need to convert the char to an uppercase character for the function to work properly.

Source: 
    https://docs.vultr.com/cpp/standard-library/cctype/isupper
    https://cplusplus.com/reference/cctype/#google_vignette

*/
#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>
using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            
            vector<char> letters;

            // Iterate through the string and add each character to a char vector 
            for (int x = 0; x < s.size(); x++) {            
                // Need to filter for non-alphanumeric characters
                if (isalnum(toupper(s[x])) == 1) {
                    letters.push_back(s[x]);
                } 
            }

            // Need to convert all uppercase letters in the string vector to uppercase.
            for (int y = 0; y < letters.size(); y++) {
                if (isupper(letters[y])) {
                    letters[y] = tolower(letters[y]);
                }
            }

            // Use 2 pointers to iterate from start and end to ID if palindrome.
            int start = 0;
            int end = letters.size() - 1;

            while (start < end) {
                if (letters[start] != letters[end]) {
                    return false;
                }
                start++;
                end--;
            }
            return true;
        }
};


int main() {

    string s = "A man, a plan, a canal: Panama";

    Solution solution;

    bool ispalindrome = solution.isPalindrome(s);

    if (ispalindrome == true) {
        cout << "The string is a palindrome" << endl;
    } else {
        cout << "The string is not a palindrome" << endl;
    }

    return 0;
}
