/* 

Leetcode Q 217 -- Contains Duplicates 2

Had to use the cmath header file to use the abs() function to ID a numbers absolute value.

*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            
            for (int x = 0; x < nums.size(); x++) {
                for (int y = 0; y < nums.size(); y++) {
                    if (x != y) {
                        if (nums[x] == nums[y] && abs(x-y) <= k) {
                            return true;
                        }
                    }
                }
            }
            
            return false;
        }
};
int main() {

    vector<int> nums = {1,2,3,1};
    int k = 3;
    Solution solution;

    bool contains_dupe = solution.containsNearbyDuplicate(nums, k);

    if (contains_dupe == false) {
        cout << "The given vector does not containt a duplicate!" << endl;
    } else {
        cout << "The given vector does contain a duplicate!" << endl;
    }


    return 0;
}