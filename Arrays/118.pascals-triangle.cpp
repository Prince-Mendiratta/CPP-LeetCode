/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (61.65%)
 * Likes:    5741
 * Dislikes: 211
 * Total Accepted:    794.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '5'
 *
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it as shown:
 *
 *
 * Example 1:
 * Input: numRows = 5
 * Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * Example 2:
 * Input: numRows = 1
 * Output: [[1]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= numRows <= 30
 *
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  //////////////////////////////////
  //////      APPROACH 1      //////
  //////////////////////////////////
  // Time Complexity - O(n^2)
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> out(numRows);
    out[0] = {1};
    for (int i = 1; i < numRows; i++) {
      vector<int> temp(i + 1, 1);
      for (int j = 1; j < i; j++) {
        temp[j] = out[i - 1][j - 1] + out[i - 1][j];
      }
      out[i] = temp;
    }
    return out;
  }
};
// @lc code=end
