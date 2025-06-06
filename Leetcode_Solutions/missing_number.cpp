/*
Leetcode 268 -- Missing Number

Given an array with n # of distinct integer elements in the 
range of [0,n], return the only number in the range that is 
missing from that array!
*/

#include <iostream>
#include <vector>
#include <unordered_map> 

using namespace std;


class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            // Create a dict which holds the range of the length of the input vector.
            unordered_map<int, int> range;

            for (int x = 0; x < nums.size(); x++) {
                // We then fill in a key for each value in the range of 1 to nums.size() + 1.
                range.insert({x+1, 0}); 
            }

            // Now we count the occurences of each value in nums, and update that count for each respective key already in the hashmap
            for (int x = 0; x < nums.size(); x++) {
                // If the value is already in the list.
                if (range.find(nums[x]) != range.end()) {
                    range[nums[x]]++;
                } 
            }

            // After this is done, our hashmap should have only 1 key with a value of 0. 
            for (auto x = range.begin(); x != range.end(); x++) {
                if (x->second == 0) {
                    return x->first;
                }
            }
        }
};

int main() {

    Solution solution;

    vector<int> nums = {3,0,1};

    int missing_num = solution.missingNumber(nums);

    cout << "The missing value from the list is: " << missing_num << endl;

    return 0;
}