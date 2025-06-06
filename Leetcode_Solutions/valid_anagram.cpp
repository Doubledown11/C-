/*
Leetcode Q 242 -- Valid Anagram

*/

#include <iostream> 
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        bool isAnagram(string s, string t) {
            unordered_map<char, int> seen;

            // Iterate through string 1, and add each char and its occurrence count to the hashmap.
            for (int x = 0; x < s.size(); x++) {
                // If we have seen the char before increment its value 
                if (seen.find(s[x]) != seen.end()) {
                    seen[s[x]]++;
                }

                // If we have not seen the char before, add it to the dict.
                else {
                    seen.insert({s[x], 1});
                }
            }

            // Now iterate through string 2, and check each char to make sure it appears in s, 
            // and it appears the same number of times.
            for (int y = 0; y < t.size(); y++) {
                // If we have seen the char before, decrement its value. 
                // But if it is in the list and equal to 0, we return false.
                if (seen.find(t[y]) == seen.end() || seen[t[y]] == 0) {
                    return false;
                }
               
                seen[t[y]]--;
            } 

            // If we can get through the loop of the 2nd string, they must be anagrams!
            return true;

        }
};

int main() {
    string s = "anagram";
    string t = "nagaram";

    Solution solution;
    bool is_anagram = solution.isAnagram(s, t);

    if (is_anagram == true) {
        cout << "The given strings are anagrams!" << endl;
    } else {
        cout << "The given strings are not anagrams!" << endl;
    }

    return 0;
}