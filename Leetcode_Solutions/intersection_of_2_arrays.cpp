/*
Leetcode Q 349 -- Intersection of Two Arrays.


*/





#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            
            /*
            We will build 2 hashmaps with the element as a key, and the value the number of times it occurs in each list. 
            */

            // Below is for nums1
            unordered_map<int, int> seen;
            for (int x = 0; x < nums1.size(); x++) {
                if (seen.find(nums1[x]) != seen.end()) {
                    seen[nums1[x]]++;
                } else {
                    seen.insert({nums1[x], 1});
                }
            }

            // Below is for nums2
            unordered_map<int, int> seen2;
            for (int y = 0; y < nums2.size(); y++) {
                if (seen2.find(nums2[y]) != seen2.end()) {
                    seen2[nums2[y]]++;
                } else {
                    seen2.insert({nums2[y], 1});
                }
            }

            // Now iterate through one of the hashmaps and check to see if there is a matching sequence of 
            // key:value pairs. If so, that is our intersection.
            vector<int> result;
            for (auto x = seen.begin(); x != seen.end(); x++) {
                for (auto y = seen2.begin(); y != seen2.end(); y++) {
                    if (x->first == y->first && x->second == y->second) {
                        result.push_back(x->first);
                    }
                }
            }

            return result;
        }
};




int main() {

    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};

    Solution solution;

    vector<int> answer_vector = solution.intersection(nums1, nums2); 

    cout << "The intersection vector is as follows: " << endl;
    for (int x = 0; x < answer_vector.size(); x++) {
        cout << answer_vector[x] << " ";
    }
    cout << endl;
    return 0;
}