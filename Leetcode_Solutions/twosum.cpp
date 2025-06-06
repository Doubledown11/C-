/*
Leetcode Q 1 -- TwoSum

*/
#include <iostream>
#include <vector>

using namespace std;


class Solution {
    public:
        // & in the below code repr's a reference. 
        // This means that nums is not a copy of the vector,
        // it is a reference to it. Thus any changes made to nums 
        // inside the function will have the same affect to the 
        // original vector. 
        // References are useful as they allow us to avoid making
        // copies of the object. This saves memory and processing time,

        vector<int> twoSum(vector<int>& nums, int target) {

            // Iterate through list
            for (int i = 0; i < nums.size(); i++) {
                // Init pointer to track the current sum
                int tot = 0; 

                // Add the number in the first loop to tot to be checked with the second number 
                // in the other loop. 
                tot += nums[i];

                // Iterate through the list again. 
                for (int j = 0; j < nums.size(); j++) {
                    int sum = nums[j] + tot;

                    if (sum == target) {
                        vector<int> answer = {i, j};
                        return answer;
                    } 
                } 
            }   
        }
};



int main() {
    /* 
    Main Class.
    */

    // Initialize the Solution Class.
    Solution solution; 

    // Init the nums vector 
    vector<int> nums = {2,7,11,15};

    // Init the target value to be added too
    int target = 9; 

    // Call the solution class with the nums vector and target as arguments.
    vector<int> answer = solution.twoSum(nums, target);

    // Check if there were two valid indexes returned by Soution.twoSum()
    if (answer[0] == 0 && answer[1] == 0) {
        cout << "Sorry, there are no 2 indices in the given array which sum to the target index" << endl;
    } else { 
        cout << "The 2 indexes which sum to target are " << answer[0] << ' ' << answer[1] << endl;
    }

    return 0;
} 

