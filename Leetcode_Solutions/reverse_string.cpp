/*
Leetcode Q 344 -- Reverse String

*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        void reverseString(vector<char>& s) {
            int left = 0;
            int right = s.size() - 1;

            while (left < right) {
                // Could have used swap() from <algorithm> to swap
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp; 

                left++;
                right--;
            }

            cout << "The vector after being reversed is:" << endl;
            for (int x = 0; x < s.size(); x++) {
                cout<<s[x]<<" ";
            }
            cout<<endl;
        }
};

int main() {
    Solution solution;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    cout << "The vector b4 being reversed is:" << endl;
    for (int x = 0; x < s.size(); x++) {
        cout << s[x] << " ";
    }
    cout << endl;

    solution.reverseString(s);

    return 0;
}