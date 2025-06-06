/*

Leetcode Q 121 -- Best Time to Buy and Sell Stock

We given an array of prices where price[i] is the price of a stock on ith day.
Max profit by pick a single day to buy a stock and another day in the future to sell that stock.

*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int min_price = INT32_MAX;
            int max_profit = 0;

            for (int x = 0; x < prices.size(); x++) {
                if (prices[x] < min_price) {
                    // Update min price if current price is lower.
                    min_price = prices[x];
                }
                // Calc the profit if we sold at today.
                int profit = prices[x] - min_price; 
                if (profit > max_profit) {
                    // Update max_profit if current price is greater than it.
                    max_profit = profit;
                }
            }
            return max_profit;
        }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    Solution solution;
    int max_profit = 0;
    max_profit = solution.maxProfit(prices);

    cout << "The max profit that you can achieve with the given prices is: " << max_profit << endl;
    return 0;
}

