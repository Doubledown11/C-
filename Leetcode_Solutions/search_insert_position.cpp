/*
Leetcode Q 35 -- Search Insert Position 
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            
            int prior = 0;
            
            for (int x = 0; x < nums.size(); x++) {
                // Case: Target is found.
                if (nums[x] == target) {
                    return x;
                } 

                // If our target is larger, we assign the current idx to the prior var.
                if (target > nums[x]) {
                    // Case: Target is larger then all values in nums
                    if (x == nums.size() - 1) {
                        // We have to add 1 to the idx as the addition 
                        // of the new val would increase nums size by 1.
                        return x + 1;
                    }
                    prior = x;
                }

                // If our current val is larger, our prior idx must be the return val.
                if (target < nums[x]) {
                    return x;
                }
            }
        }
};

int main() {
    vector<int> nums = {1,3,5,6};
    int target = 7;
    Solution solution;
    int idx = solution.searchInsert(nums, target);
    cout << "The index where we would find target in nums is " << idx << endl;
    return 0;
}