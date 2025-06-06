/*

Leetcode Q 217 -- Contains Duplicates


*/



#include <iostream> 
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            // Init a hashmap to hold values we have seen prior
            unordered_map<int, int> seen;

            // Iterate through nums and add vals to seen as we come across them.
            for (int x = 0; x < nums.size(); x++) {
                // If we have seen the value b4.
                if (seen.find(nums[x]) != seen.end()) {
                    return true;
                }
                // If we haven't seen the value before.
                else {
                    // Since .find() returns the value of a given key
                    seen.insert({nums[x], nums[x]});
                }
            }
            // If we can loop through the nums vector without finding a duplicate we return true.
            return false;
        }
};

int main() {
    vector<int> nums = {1,2,3,1};

    Solution solution;

    bool contains_duplicate = solution.containsDuplicate(nums);

    if (contains_duplicate == false) {
        cout << "The given vector does not contain a duplicate!" << endl;
    } else {
        cout << "The given vector does contain a duplicate!" << endl;
    }

    return 0;
}
