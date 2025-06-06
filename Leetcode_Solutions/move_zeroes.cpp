/*
Leetcode 283 - Move Zeroes 

Move all 0s to the end of the vector while maintaining the relative order of the non-zero elements.
*/
#include <iostream>
#include <vector>

using namespace std;


class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            // Used to hold the position of the last non-zero found.
            // When we meet a zero with the loop pointer, we swap the val at the loop pointer
            // with the last none zero val.
            int left = 0;
            

            for (int x = 0; x < nums.size(); x++) {
                if (nums[x] != 0) {
                    int temp;
                    temp = nums[left];
                    nums[left] = nums[x];
                    nums[x] = temp;
                    left++;
                }
            }
        }
};

int main() {
    Solution solution;
    vector<int> nums = {0,1,0,3,12};
    solution.moveZeroes(nums);
    return 0;
}