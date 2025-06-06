/*
Leetcode Q 205 -- Isomorphic Strings

Strings are isomorphic if all chars in 1 string can be replaced 
to get all the chars in another.

Isomorphic:
bed -- cat. b>c, e>a, d>t 
fee -- wii. f>w, e>i, e>i

Non-Isomorphic:
beet -- bell. b>b, e>e, e>l, t>l. 

*/
#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            // Case: S and T are different lengths
            if (s.size() != t.size()) {
                return false;
            }
 
            unordered_map<char, char> characters_s_to_t; 
            unordered_map<char, char> characters_t_to_s;

            // Iterate through string s.
            for (int x = 0; x < s.size(); x++) {
                char s_char = s[x];
                char t_char = t[x];

                // Check if there is an existing mapping for s->t 
                if (characters_s_to_t.find(s_char) != characters_s_to_t.end()) {
                    if (characters_s_to_t[s_char] != t_char) {
                        return false;
                    } 
                } 

                // if there is no mapping:
                else {
                    characters_s_to_t[s_char] = t_char;
                }



                // Check for a mapping from t to s.
                if (characters_t_to_s.find(t_char) != characters_t_to_s.end()) {
                    if (characters_t_to_s[t_char] != s_char) {
                        return false;
                    }
                } 

                // If there is no mapping:
                else {
                    characters_t_to_s[t_char] = s_char;
                }
            }
            return true;
        }
};


int main() {
    Solution solution; 
    string s = "egg";
    string t = "add";

    bool is_iso = solution.isIsomorphic(s,t);

    if (is_iso == true) {
        cout << "The given strings are isomorphic!" << endl;
    } else {
        cout << "The given strings are not isomorphic!" << endl;
    }

    return 0;
}