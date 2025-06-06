/*
Leetcode 3 - Longest substring without repeating characters.
*/

#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            
            // Init a vector to hold all substrings found.
            vector<string> substrings;
            int start_idx = 0;

            while (start_idx < s.size() - 1) {
                unordered_map<char, int> seen;
                string curr_substr;
                cout << "Start_idx " << start_idx << endl;
                bool done = false;

                // Iterate through s and add vals to seen as we go, 
                // if we come across a val we have seen before, 
                // we add the current substring to substrings vector. 
                for (int x = start_idx; x < s.size(); x++) {
                    // If we have seen the char before.
                    if (seen.find(s[x]) != seen.end()) {
                        // We consider this substring to be done,
                        // so we add it to the vector and move the substring start pointer up 1.
                        substrings.push_back(curr_substr);
                        cout << "Current sub str added to vector: " << curr_substr << endl;
                        start_idx++;
                        done = true;
                        break;
                    }

                    // If we haven't seen the char before.
                    else {
                        seen.insert({s[x], 1});
                        curr_substr.push_back(s[x]);
                        cout << "Curre substr after char add " << curr_substr << endl;
                    }
                }
                if (done) {
                    continue;
                }
            }

            int biggest_size = 0;
            // Now we have to find the largest substring in the substrings vector.
            for (int x = 0; x < substrings.size(); x++) {
                if (substrings[x].size() > biggest_size) {
                    biggest_size = substrings[x].size();
                }
            }

            return biggest_size;
        }
};


int main() {
    Solution solution;

    string s = "abcabcbb";

    int length = solution.lengthOfLongestSubstring(s);

    cout << "The len of the longest substring of non repeating chars " << length << endl;

    return 0;
}
