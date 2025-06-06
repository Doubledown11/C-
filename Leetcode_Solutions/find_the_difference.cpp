/*
Leetcode 389 -- Find the Difference  

Find the char that was added to string t.

*/
#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        char findTheDifference(string s, string t) {

            // Case: Strimg s is empty
            if (s.size() == 0) {
                return t[0];
            }

            unordered_map<char,int> seen;

            // Count frequency of chars in s.
            for (int x = 0; x < s.size(); x++) {
                if (seen.find(s[x]) != seen.end()) {
                    seen[s[x]]++;
                } else {
                    seen.insert({s[x], 1});
                }
            }

            unordered_map<char, int> seen2;
            // Check chars in t 
            for (int x = 0; x < t.size(); x++) {
                // If a letter is not in the map.
                if (seen.find(t[x]) == seen.end()) {
                    return t[x];
                }

                // If there is an extra letter in t, for a letter that is in s.
                // But to ID this, I need to start a map for t too.
                else { 
                    // Add char to the seen2 map
                    seen2.insert({t[x], 1});

                    // check if count of current char is greater than the count in s map
                    if (seen2.at(t[x]) > seen.at(t[x])) {
                        return t[x];
                    }
                }
            }
        }
};



int main() {
    Solution solution;

    string s = "abcd";
    string t = "abcde";

    char diff_char = solution.findTheDifference(s,t);

    cout << "The letter that was added was: " << diff_char << endl;
 
    return 0;
}