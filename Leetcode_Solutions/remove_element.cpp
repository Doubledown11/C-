/*
Leetcode Q 27 -- Remove Element

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {

            // Holds the pos of the last non target value
            int non_dupe = 0;

            int x = 0;
            while (x < nums.size()) {
                // If we have moved.
                if (nums[x] != val) {
                    nums[non_dupe] = nums[x];
                    non_dupe++;
                }
                x++;
            }

            return non_dupe;
            // We have to swap the values at non_dupe and x each time
            // we find a non target value.
            // Otherwise x increments, then we later swap the non target vals following
            // target with target, until target is at the end.
        }
};


int main() {
    Solution solution;

    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;


    int element = solution.removeElement(nums, val);
    cout << "The number of unique elements is " << element << endl;

    return 0;
}
