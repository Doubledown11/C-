/*
Leetcode Q 136 -- Single Number

Every element appears twice except 1, find it and return it.
Must have linear runtime, and use only constant extra space.
    Constant extra space: I think means we cant create a new data structure to 
        hold data as we are trying to ID the single value. 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int singleNumber(vector<int>& nums) {

            // Case: Length of list == 1:
            if (nums.size() == 1) {
                return nums[0];
            }

            // I will a nest for loop to ID
            for (int x = 0; x < nums.size(); x++) {
                int single = 0;
                for (int y = 0; y < nums.size(); y++) {
                    if (nums[x] == nums[y] && x != y) {
                        single = 1;
                    }
                }

                if (single == 0) {
                    return nums[x];
                }
            }            

        }
};

int main() {

    vector<int> nums = {4,1,2,1,2};
    Solution solution;
    int single = solution.singleNumber(nums);
    cout << "The number which is single in the vector is: " << single << endl;

    return 0;
}