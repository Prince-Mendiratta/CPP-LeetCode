/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (53.22%)
 * Likes:    16060
 * Dislikes: 540
 * Total Accepted:    2.2M
 * Total Submissions: 4M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day.
 *
 * You want to maximize your profit by choosing a single day to buy one stock
 * and choosing a different day in the future to sell that stock.
 *
 * Return the maximum profit you can achieve from this transaction. If you
 * cannot achieve any profit, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Note that buying on day 2 and selling on day 1 is not allowed because you
 * must buy before you sell.
 *
 *
 * Example 2:
 *
 *
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transactions are done and the max profit =
 * 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= prices.length <= 10^5
 * 0 <= prices[i] <= 10^4
 *
 *
 */

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  //////////////////////////////////
  //////      APPROACH 0      //////
  //////////////////////////////////
  // Store the profit from the right in aux space
  // Time Complexity - O(n)
  // Space Complexity - O(n)
  int maxProfit0(vector<int> &prices) {
    int n = prices.size() - 1;
    vector<int> maxProfits(n+1);
    maxProfits[n] = prices[n];
    int prof = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (prices[i] > maxProfits[i + 1]) {
        maxProfits[i] = prices[i];
      } else {
        maxProfits[i] = maxProfits[i + 1];
      }
    }
    for (int i = 0; i <= n; i++) {
      int curr = maxProfits[i] - prices[i];
      if (curr > prof) {
        prof = curr;
      }
    }
    return prof;
  }

  //////////////////////////////////
  //////      APPROACH 1      //////
  //////////////////////////////////
  // Time Complexity - O(n)
  // Space Complexity - O(1)
  int maxProfit(vector<int> &prices) {
    int currLow = INT32_MAX;
    int profit = 0;
    int highestProfit = 0;
    for (int i = 0; i < prices.size(); i++) {
      if (prices[i] < currLow) {
        currLow = prices[i];
        if (profit > highestProfit) {
          highestProfit = profit;
        }
        profit = 0;
      } else {
        int prof = prices[i] - currLow;
        if (prof > profit) {
          profit = prof;
        }
      }
    }
    if (profit > highestProfit) {
      highestProfit = profit;
    }
    return highestProfit;
  }

  //////////////////////////////////
  //////      APPROACH 2      //////
  //////////////////////////////////
  // Kadane
  // Time Complexity - O(n)
  // Space Complexity - O(1)
  int maxProfit2(vector<int> &prices) {
    int currLow = INT32_MAX;
    int profit = 0;
    for (int i = 0; i < prices.size(); i++) {
      if (prices[i] < currLow) {
        currLow = prices[i];
      } else {
        int prof = prices[i] - currLow;
        if (prof > profit) {
          profit = prof;
        }
      }
    }
    return profit;
  }

  //////////////////////////////////
  //////      APPROACH 4      //////
  //////////////////////////////////
  // Brute Force
  // Time Complexity - O(n^2)
  // Check all possible pairs and find out the highest profit
};
// @lc code=end
