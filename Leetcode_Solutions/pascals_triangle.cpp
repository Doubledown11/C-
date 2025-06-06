/*
Leetcode Q 118 -- Pascal's Triangle

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> triangle;
            
            for (int x = 0; x < numRows; x++) {
                // Create a row with all elements set to 1.
                int values = x + 1;            
                vector<int> row;
                for (int y = 0; y < values; y++) {
                    row.push_back(1);
                }

                // Fill in the internal values of the row.
                for (int z = 1; z < x; z++) {
                    row[z] = triangle[x-1][z-1] + triangle[x-1][z];
                }

                // Add the row to the triangle vector.
                // This creates a matrix.
                triangle.push_back(row);
            }
            return triangle;
        }
};


int main() {
    Solution solution;
    int numRows = 5;

    vector<vector<int>> pascals; 
    pascals = solution.generate(numRows);

    // Print out the triangle matrix.
    for (int x = 0; x < pascals.size(); x++) {
        for (int y = 0; y < pascals[x].size(); y++) {
            cout << pascals[x][y]; 
        }
        cout << "\n";
    }

    return 0;
}