/*
Leetcode Q 202 -- Happy Number.  

A number is happy if it folows the process:
Starting with a positive integer, replace the number of the sum of the squares of its digits.
Repeat the process until the number equals 1, or it loops endlessly in a cycle that does not include 1.
Those numbers for which this process ends in 1 are happy.



*/
#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        bool isHappy(int n) {
            unordered_map<int, int> seen;
            int prior = n;

            while (true) {

                // Get sum of squares of n
                string n_str = to_string(prior); 
                int sum_sqs = 0;
                for (int x = 0; x < n_str.size(); x++) {
                    // First have to convert the char to an integer
                    int char_int = n_str[x] - '0';
                    sum_sqs += (char_int * char_int);
                }

                // Check if the number equals 1
                if (sum_sqs == 1) {
                    return true;
                }

                // If it doesn't equal 1, we have to check to see if the key-value pair
                // has been seen b4. With the key-value pair being comprised of the 
                // number b4 it was summed-squared 
                else{
                    // Check if the prior and sum-squared combo is in the hashmap currently.
                    // If so, it is a loop
                    if (seen.find(prior) != seen.end() && seen.at(prior) == sum_sqs) {
                        return false;
                    }
                    else {
                        seen.insert({prior, sum_sqs});
                        prior = sum_sqs;
                    }
                }
            }
        }
};


int main() {
    int n = 2;

    Solution solution;
    bool is_happy = solution.isHappy(n);
    
    if (is_happy == false) {
        cout << "The number is not happy" << endl;
    } else {
        cout << "The number is happy" << endl;
    }

    return 0;
}

