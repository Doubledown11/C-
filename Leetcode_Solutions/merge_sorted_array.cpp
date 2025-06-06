/* 
Leetcode 88 -- Merge Sorted Array




Given 2 arrays in non-decreasing order and 2 vars m and n,
which represent the number of elements in each array.

Merge both arrays into a single sorted array in non-decreasing order. 

the final array should not be returned by the function, but rather it needs
to be stored inside the array nums1. 
Thus nums1 has a length of m + n, where the last n elements are set to 0.

How to sort a vector in ascending order? 
    Could have also used sort.
    But I implemented an inplace sorting algorithm to sort in ascending order.    
        I think this is a selection sort algorithm -- CHECK LATER.
                TODO RETURN STUDY L8TR.
    

Source: 
    https://www.geeksforgeeks.org/sorting-a-vector-in-c/
    https://www.geeksforgeeks.org/selection-sort-algorithm-2/
    Used the selection sort in your black duotang python notes --> cant remember where it was from REMOVE THIS LINE B4 POST TO GITHUB

*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            // Init var and set it to the last known 0 value. 
            int last_zero = m;

            // Iterate through nums2 and move each value to the last_zero 
            // idx in nums1.
            for (int x = 0; x < nums2.size(); x++) {
                nums1[last_zero] = nums2[x];
                last_zero++;
            } 

            // Now we just have to sort nums1 in non-decreasing order.
            // I think this is a selection sort algorithm
            int left = 0;
            while (left < nums1.size()) {
                int highest_digit = nums1[left];
                int high_idx = left;

                for (int x = 0; x < nums1.size(); x++) {
                    if (nums1[x] > highest_digit) {
                        highest_digit = nums1[x];
                        high_idx = x;
                    }
                    
                    int tmp = nums1[left];
                    nums1[left] = nums1[high_idx];
                    nums1[high_idx] = tmp;
                    left++;
                }
            }

            cout << "Reached end of selection alg" << endl;
            // Just to verify that nums1 is sorted. 
            for (int x = 0; x < nums1.size(); x++) {
                cout << "current val in nums1: " << nums1[x] << endl;
            }

        }
};


int main() {
    Solution solution;

    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int n = 3;
    int m = 3;

    solution.merge(nums1, m, nums2, n);
    return 0;
}