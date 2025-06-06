/*
Leetcode Q 26 -- Remove Duplicates from Sorted Array

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {

            // Case: Nums array is empty
            if (nums.empty()) {
                return 0;
            }


            // Init a pointer for the last non duplicate data point found.
            // Init at 1 since we assume there to be at least 1 unique value.
            // after moving all duplicates to the end, we will have a non_dupe increment for 
            // each unique val in the list. [1,1,2,3] has 3 unique vals
            int non_dupe = 1;


            // Iterate ahead and find a non duplicate to move to the pos ahead of 
            // the pos at the non_dupe index, BC we assume this pos holds a dupe.
            int checker = 1;
            
            while (checker < nums.size()) {
                // If we find a dupe, we iterate to the end of the duplicated data points.
                // As the list is sorted, any data with dupes will be presented one after another.
                if (nums[checker] == nums[non_dupe]) {
                    
                    checker++;
                
                
                } else {
                    nums[non_dupe] = nums[checker];
                    checker++;
                    non_dupe++;
                }

            }

            return non_dupe; 

        }
};


int main() {
    
    vector<int> nums = {1,1,2};

    // Display list b4 sort 
    cout << "list b4 sort" << endl;
    for (int x = 0; x < nums.size(); x++) {
        cout << nums[x];
    }
    cout << "\n\n" << endl;

    Solution solution;

    int num_non_dupe = solution.removeDuplicates(nums);
    cout << num_non_dupe << " is the num of non dupe" << endl;
}