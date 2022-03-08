/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (49.21%)
 * Likes:    18886
 * Dislikes: 902
 * Total Accepted:    2.1M
 * Total Submissions: 4.3M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * A subarray is a contiguous part of an array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
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
  //////      APPROACH 2      //////
  //////////////////////////////////
  // Time Complexity - O(n)
  // Kadane's Algo
  // Reset subarray once sum goes negative.
  int maxSubArray(vector<int> &nums) {
    int max = nums[0];
    int n = nums.size();
    int curr = 0;
    for (int i = 0; i < n; i++) {
      curr += nums[i];
      if (curr > max) {
        max = curr;
      }
      if (curr < 0) {
        curr = 0;
      }
    }
    return max;
  }
};
// @lc code=end
