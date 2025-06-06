/*
Leetcode 15 - 3Sum

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> triplets;

            for (int x = 0; x < nums.size(); x++) {
                for (int y = 0; y < nums.size(); y++) {
                    for (int z = 0; z < nums.size(); z++) {
                        vector<int> triplet;
                        if (x != y && x != z && y != z) {
                            if (nums[x] + nums[y] + nums[z] == 0) {
                                triplet.push_back(nums[x]);
                                triplet.push_back(nums[y]);
                                triplet.push_back(nums[z]);
                            }
                        }
                    
                        // If we found a triplet we add it to the triplets metrix vector 
                        if (!triplet.empty()) {
                            // First have to see if already added the triplet to the matrix.
                            bool added = false;
                            for (int a = 0; a < triplets.size(); a++) {
                                if (triplet == triplets[a]) {
                                    added = true; 
                                }
                            }

                            if (!added) {
                                triplets.push_back(triplet);
                            }
                        }
                    }
                }
            }
            return triplets;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {0,0,0};

    vector<vector<int>> triplets = solution.threeSum(nums);

    cout << "The triplets are as follows: " << endl;
    for (int x = 0; x < triplets.size(); x++) {
        cout << "Triplet " << x+1 << " : ";
        for (int y = 0; y < triplets[x].size(); y++) {
            cout << triplets[x][y] << " ";
        }
        cout << endl;
    }
    return 0;
}