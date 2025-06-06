/*
Leetcode 392 -- Is subsequence

Return true is s is a subsequence of t.

Are the chars in 1 string found in another string with the same relative order.

bus is subsequence of abacus, for ex.

*/

#include <iostream>
#include <cstring>

using namespace std;

class Solution {
    public:
        bool isSubsequence(string s, string t) {
            // Init 2 pointers 1 for each string.
            int s_pointer = 0;
            int t_pointer = 0;

            while (s_pointer < s.size() || t_pointer < t.size()) {
                // If we found a letter in s, that is in t.
                if (s[s_pointer] == t[t_pointer]) {
                    s_pointer++;
                    t_pointer++;
                } 

                // if not, we move t up until we find a letter that matches
                // the current letter at s_pointer.
                else {
                    t_pointer++;
                }
            }

            if (s_pointer == s.size()) {
                return true;
            } else {
                return false;
            }
        }
};

int main() {
    Solution solution;

    string s = "abc";
    string t = "ahbgdc";

    bool is_sub = solution.isSubsequence(s, t);

    if (is_sub == true) {
        cout << "S is a subsequence of t" << endl;
    } else {
        cout << "S is not a subsequence of t" << endl;
    }

    return 0;
}