/* 
Leetcode Q 14 -- Longest Common Prefix 


*/

#include <iostream>
#include <cstring> 
#include <vector>

using namespace std; 


class Solution {
    public:


        int longestPrefixCommon(vector<string>& strs) {


            // Iterate through list 
            // Save num of common chars to int
            int count_common = 0;
            int x = 0;
            for (int i = 0; i < strs.size(); i++) {
                // Get the current char we are checking for.     
                char current = strs[i][x];
                cout << current << " current in func" << endl;
        
                for (int j = 0; j < strs[i].size(); j++) {
                    if (current != strs[i][x] ) {
                        cout << "Mismatch found on word " << strs[i] << " and letter " << strs[i][x] << endl;
                    } 
                    

                }
                
                // Move x up to check  
                x++;
                // Inc count_common
                count_common++;
            }
            return count_common;
        }



        string longestCommonPrefix(vector<string>& strs) {
            
            // Init a string to hold the current longest prefix.
            string current_prefix_match = ""; 


            // Edge Case: Empty Vector 
            if (strs.empty()) {
                current_prefix_match = "empty";
                return current_prefix_match;
            }

            // Start with the first strings first character as the prefix
            string prefix = strs[0];

            // Iterate through the remaining strings in the vector
            for (int i = 1; i < strs.size(); i++) {
                // Compare the current prefix with the current string
                int j = 0;
                while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
                    j++;
                }

                // Update prefix to the common part
                prefix = prefix.substr(0, j);

                // If prefix becomes empty, no common prefix exists
                if (prefix.empty()) {
                    return "";
                }            
            }
        }
};



int main() {
    /* 
    Main Function.
    */

    // Initialize the Solution class instance
    Solution solution;

    // Initialize the string vector which we will be iterating through.
    vector<string> strs = {"flower", "flow", "flight"}; 

    
    int count_common = solution.longestPrefixCommon(strs);
    cout << count_common << " is the total common chars in the given vector of strings." << endl;
    
    
    
    
    // string current_prefix_match = solution.longestCommonPrefix(strs);



    // if (current_prefix_match == "") {
    //     // There is no prefix match
    //     cout << "There is no prefix match for the characters in the given string." << endl;
    // } 

    // else if (current_prefix_match == "empty") { 
    //     // If the given string vector is empty.
    //     cout << "The string vector is empty!" << endl;
    // }

    // else {
    //     // Display the longest prefix match
    //     cout << "The longest prefix match is: " << current_prefix_match << endl;
    // }

    return 0;
}


