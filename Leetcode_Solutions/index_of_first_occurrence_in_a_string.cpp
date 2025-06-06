/*
Leetcode Q 28 -- Find the Index of the First Occurrence in a String 

*/


#include <iostream>
#include <cstring>
using namespace std;
class Solution {
    public:
        int strStr(string haystack, string needle) {
            // Case: Needle is too big to fit inside of the haystack
            if (needle.size() > haystack.size()) {
                cout << "Needle is too long to fit inside of haystack!" << endl;
                return 0;
            }
            
            // Remember RANGE in python will check up to, but not including the
            // value in the 2nd half of the range def range(0,2)  
            for (int x = 0; x < (haystack.size() - needle.size()) + 1; x++) {
                // We are using haystack.size() - needle.size() as the max
                // index as a range of chars to check from inside of haystack
                // No point in checking any more values.
                // BUT WHY? RETURN LATER TO ANSWER 


                // To extract substrings in C++, it is a little bit different 
                // from python. We cant use haystack[x:x+needle.size() but we 
                // must use substr() 
                if (haystack.substr(x, x+needle.size()) == needle)  {
                    cout << "Needle is in the haystack!" << endl;
                    return 1;
                } 
            }

            cout << "Needle is not in the haystack!" << endl;
            return 1;
        }
};

int main() {

    Solution solution;

    string haystack = "sadbutsad";
    string needle = "sad";

    int index = solution.strStr(haystack, needle);
    return 0;
}
