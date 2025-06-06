/*
Leetcode Q 169 -- Majority Element 


Return the majority element, which appears more than n/2 times.

I used a hashmap to solve this problem. 
To do so, I had to include the <unordered_map> header file.

Sources:
    https://www.geeksforgeeks.org/traversing-a-map-or-unordered_map-in-cpp-stl/
    https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/
    https://www.geeksforgeeks.org/how-to-use-hashmap-in-cpp/

*/


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std; 


class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            // Below creates a dict with keys of type int, and values of type int.
            unordered_map<int, int> elements;

            for (int x = 0; x < nums.size(); x++) {
                // ID if the element is in the hash map
                if (elements.find(nums[x]) != elements.end()) {
                    // Increment the value by 1.
                    elements[nums[x]] == elements[nums[x]]++;
                } 
                // If it isn't, we add it.
                else {
                    elements.insert({nums[x], 1});
                }
            }

            int maj_element = 0;
            int maj_count = 0;

            // Now iterate through the hashmap and ID which key has 1 for a value.
            for (auto i : elements) {
                if (i.second > maj_count) {
                    maj_count = i.second;
                    maj_element = i.first;
                }
            }

            return maj_element;
        }
};

int main() {

    vector<int> nums = {2,2,1,1,1,2,2};

    Solution solution;
    int maj_elem = solution.majorityElement(nums);

    cout << "The majority element is: " << maj_elem << endl;

    return 0;
}