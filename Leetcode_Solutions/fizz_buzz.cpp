/*
Leetcode 412 -- Fizzbuzz

*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


class Solution {
    public:
        vector<string> fizzBuzz(int n) {
            vector<string> answer;
            
            for (int x = 1; x < n+1; x++) {

                if (x % 3 == 0 && x % 5 == 0) {
                    answer.push_back("FizzBuzz");
                }

                else if (x % 3 == 0) {
                    answer.push_back("Fizz");
                }

                else if (x % 5 == 0) {
                    answer.push_back("Buzz");
                }

                else {
                    answer.push_back(to_string(x));
                }
            }
            
            return answer;
        }
};


int main() {
    int n = 3;

    Solution solution; 

    vector<string> answer_vector = solution.fizzBuzz(n);

    cout << "The answer vector elements are as follows: " << endl;

    for (int x = 0; x < answer_vector.size(); x++) {
        cout << answer_vector[x] << " ";
    }
    cout << endl;

    return 0;
}