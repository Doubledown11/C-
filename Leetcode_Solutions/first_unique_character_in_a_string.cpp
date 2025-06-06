/*
Leetcode 387 - First Unique Character in a string.

*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
    public:
        int firstUniqChar(string s) {
            unordered_map<char, int> seen;

            // Create a hashmap with each char and their occurrence count from the string.
            for (int x = 0; x < s.size(); x++) {
                // If the char has been added to the list before.
                if (seen.find(s[x]) != seen.end()) {
                    seen[s[x]]++;
                }

                else {
                    seen.insert({s[x], 1});
                }
            }

            // Iterate through the string again, and check if it has a value of 1 in the hashmap.
            // We return the first char with a value of 1.
            for (int x = 0; x < s.size(); x++) {
                if (seen.at(s[x]) == 1) {
                    return x;
                }
            }

            // If no values have a count of 1, we return -1.
            return -1;
        }
};

int main() {

    string s = "aabb";

    Solution solution; 

    int first_unique_idx = solution.firstUniqChar(s);

    if (first_unique_idx == -1) {
        cout << "Theres no unique chars in the string" << endl;
    } else {    
        cout << "The first unique char idx from the given string is: " << first_unique_idx << endl;
    }
    
    return 0;
}