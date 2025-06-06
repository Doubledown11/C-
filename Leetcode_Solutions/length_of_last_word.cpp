/* 

Leetcode Q 58 -- Length of Last Word


Good question for string methods 

NOTE there is no .split() string method in C++ like there is in python!!!
I am going to use stringstream from here: 
    https://stackoverflow.com/questions/68396962/how-to-split-strings-in-c-like-in-python 
    https://www.geeksforgeeks.org/stringstream-c-applications/
    https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/ 

Stringstream is useful for parsing and manipulating strings 

RETURN TODO
AGAIN cant access last value in a vector with vector[-1], we MUST use .back(). 


https://www.geeksforgeeks.org/cpp-string-functions/
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
    public:
        vector<string> string_split(string str) {
            /*
            Splits an input string at the spaces within. 
            */
            
            vector<string> split_string;
            
            // Below breaks the string by creating a stringstream object called s.
            // Stringstream acts as an input stream, allows one to extract words. 
            stringstream s(str);

            // Vars holds extracted words.
            string s1;

            int count = 0;
            while (s >> s1) {
                split_string.push_back(s1);
            }
            
            return split_string;
        }


        int lengthOfLastWord(string str) {
            vector<string> split_string = string_split(str);

            // Use .back() to get the final value of a vector.
            int length = 0;

            return split_string.back().size();
        }
};


int main() {
    Solution solution;
    string str = "luffy is still joyboy ";

    int length = solution.lengthOfLastWord(str);
    cout << "Length of the last word in " << str << " is " << length << endl;

    return 0;    
}