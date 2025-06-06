/*
Leetcode Q 20 -- Valid Parentheses

*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            
            //If first val is a closed, it cant be valid 
            if (s[0] == ')' || s[0] == '}' || s[0] == ']') {
                return false;
            }
            
            // Init vector to hold open brackets found. 
            // NOTE: vector must be in type char since we are using it to hold characters gathered from inside of a string.
            // could have also used stacks for this by using #include <stack>
            vector<char> open;
        

            // Iterate through the string.
            for (int x = 0; x < s.size(); x++) {        
                
                cout << "We check in s " << s[x] << endl;
                if (open.size() > 0) {
                    cout << "Open last val at start loop " << open.back() << endl;
                }
                
                // Check for open 
                if (s[x] == '{' || s[x] == '[' || s[x] == '(') {
                    // Find an open push_back to open 
                    open.push_back(s[x]);
                    continue;
                } 


                // Find a close bracket
                else {
                    if (s[x] == '}') {
                        if (open.back() != '{') {
                            return false;
                        } else {
                            open.pop_back();
                            continue;
                        }
                    }


                    else if (s[x] == ']') {
                        if (open.back() != '[') {
                            return false;
                        } else {
                            open.pop_back();
                            continue;
                        }
                    }


                    else if (s[x] == ')') {
                        if (open.back() != '(') {
                            return false;
                        } else {
                            open.pop_back();
                            continue;
                        }
                    }
                }
            }
            // if we can iterate through the whole string it must be true.
            return true;
        }
};


int main() {
    string s = "()[{()}]{}";
    string s2 = "()[]{}";
    string s3 = "([])";

    Solution solution;

    bool valid = solution.isValid(s);
    if (valid == 1) {
        cout << "The given string is valid" << endl;
    } else {
        cout << "The given string is not valid"  << endl;
    }
    
    return 0;
}