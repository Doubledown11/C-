/*
Leetcode 17 - Letter Combinations of a Phone Number

It is a backtracking / iterative breath-first-search-like algorithm, 
according to Microsoft Co-Pilot at 2025-05-11. 

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            // Map to hold numbers to letter combos.
            unordered_map<char, string> Phone_combos = {
                {'2', "abc"}, 
                {'3', "def"}, 
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
            };

            cout << "Letter combinations function called!" << endl;

            // Case: Digits is empty
            if (digits.empty()) {
                return {}; 
            }

            cout << "Digits is not empty!" << endl;

            vector<string> combos = {""};

            // Kinda like for digit in digits from Python.
            for (char digit : digits) {
                if (Phone_combos.find(digit) == Phone_combos.end()) {
                    // We skip wrong characters in the map.
                    continue;
                } 

                vector<string> temp;
                for (string combination : combos) {
                    for (char letter : Phone_combos[digit]) {
                        temp.push_back(combination + letter);
                    }
                }
                combos = temp;
            }
            return combos;
        }
};


int main() {
    Solution solution; 
    string digits = "23";
    vector<string> letter_combos = solution.letterCombinations(digits);

    if (letter_combos.empty()) {
        cout << "The input string was empty!" << endl;
    }
    else {
        cout << "The combos of possible letters given the digits is: " << endl;
        for (int x = 0; x < letter_combos.size(); x++) {
            cout << letter_combos[x] << endl;
        }
    }
    return 0;
}

