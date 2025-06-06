/*
Leetcode Q  70 -- Climb Stairs


A great question as an introduction to recursion. 


How is this problem defined as being/needing a recursive solution?
    1) Problem can be broken down
        step down 1 or 2 steps.
         
    2) Repeatedly solving the same sub problem.
        At each step we need to see how many possible combos of stepping 

    3) When represented graphically, it forms a hierarchy/tree.
     
    4) Need to backtrack:  
        need to undo steps. A branch from the 2nd last step has finally reached the bottom? 
        It will eventually have to move all the way back up so it can do the same from the 
        3rd last step.


*/


#include <iostream>

using namespace std;


class Solution {
    public:
        int climbStairs(int n) {
            // Base Case: From the bottom step (n==1) there is only 1 way to climb down.
            if (n <= 1) {
                return 1;
            }

            else {
                return climbStairs(n-2) + climbStairs(n-1);
            }
        }
};

int main() {

    Solution solution;
    int n = 3;

    int answer = solution.climbStairs(3);
    cout << "The answer is " << answer << endl;

    return 0;
}