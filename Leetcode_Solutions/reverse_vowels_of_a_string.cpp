
/*
leetcode 345 -- Reverse Vowels of a String.


*/
#include <cstring>
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;


class Solution {
    public:
        string reverseVowels(string s) {
            // We must use a char vector as we have to swap individual characters in the string, which are char types no longer string types.
            // We save all vowels in a list, this is used as reference to ID if a char is a vowel or not.
            vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

            int left = 0;
            int right = s.size() - 1;

            while (left < right) {
                cout << "Left value is: " << left << endl;
                cout << "Right value is: " << right << endl;
                char l_char;
                char r_char;

                // Iterate left pointer until we find a vowel.
                bool l_loop = true;
                while (l_loop == true) {



                    // check if s[left] is in vowels.
                    int in_l = 0;
                    for (int x = 0; x < vowels.size(); x++) {
                        // If we converting a char to upper/lower we must do so in a variable declaration 
                        // rather than within an if statement. If it is done in an IF it will lead to the char being 
                        // converted into its integer ASCII representation.
                        char lower_char = tolower(s[left]);
                        if (lower_char == vowels[x]) {
                            in_l++;
                        } 
                    }
                    
                    // If the char is not in vowels, we move the left pointer up a spot.
                    if (in_l == 0) {
                        left++;
                    }
                    
                    // If it is, we break the while loop and move onto the right pointer.
                    else {
                        cout << "The vowel found at the left pointer is: " << s[left] << endl;
                        l_loop = false;
                    }
                }

                cout << "Finished the left loop!" << endl;

                // Iterate right pointer until we find a vowel.
                bool r_loop = true;
                while (r_loop == true) {
                    int in_r = 0;
                    for (int x = 0; x < vowels.size(); x++) {
                        char lower_char = tolower(s[right]);
                        if (lower_char == vowels[x]) {
                            in_r--;
                        } 
                    }

                    if (in_r == 0) {
                        right--;
                    }
                    
                    else {
                        cout << "The vowel found at the right pointer is: " << s[right] << endl;
                        r_loop = false;
                    }
                }

                // Swap vowels
                cout << "Vowels being swapped, left: " << s[left] << " and right: " << s[right] << endl;
                cout << "S b4 swap: " << s << endl;
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                cout << "S after swap: " << s << endl;

                left++;
                right--;
            }

            return s;
        }
};

int main () {
    Solution solution; 

    string s = "IceCream";

    string reversed_string = solution.reverseVowels(s);

    cout << "The string after having its vowels reversed is: " << reversed_string << endl;

    return 0;
}