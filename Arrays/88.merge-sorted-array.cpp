/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (42.72%)
 * Likes:    4548
 * Dislikes: 441
 * Total Accepted:    1.4M
 * Total Submissions: 3.2M
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing
 * order, and two integers m and n, representing the number of elements in
 * nums1 and nums2 respectively.
 *
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 *
 * The final sorted array should not be returned by the function, but instead
 * be stored inside the array nums1. To accommodate this, nums1 has a length of
 * m + n, where the first m elements denote the elements that should be merged,
 * and the last n elements are set to 0 and should be ignored. nums2 has a
 * length of n.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * Output: [1,2,2,3,5,6]
 * Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
 * The result of the merge is [1,2,2,3,5,6] with the underlined elements coming
 * from nums1.
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [1], m = 1, nums2 = [], n = 0
 * Output: [1]
 * Explanation: The arrays we are merging are [1] and [].
 * The result of the merge is [1].
 *
 *
 * Example 3:
 *
 *
 * Input: nums1 = [0], m = 0, nums2 = [1], n = 1
 * Output: [1]
 * Explanation: The arrays we are merging are [] and [1].
 * The result of the merge is [1].
 * Note that because m = 0, there are no elements in nums1. The 0 is only there
 * to ensure the merge result can fit in nums1.
 *
 *
 *
 * Constraints:
 *
 *
 * nums1.length == m + n
 * nums2.length == n
 * 0 <= m, n <= 200
 * 1 <= m + n <= 200
 * -10^9 <= nums1[i], nums2[j] <= 10^9
 *
 *
 *
 * Follow up: Can you come up with an algorithm that runs in O(m + n) time?
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
  // Time Complexity - O(n+m)
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int x = nums1.size() - 1, i = m - 1, j = n - 1;
    vector<vector<int>> m1(5);
    m1[0] = {2, 3};
    while (j >= 0) {
      if (i >= 0 && nums1[i] > nums2[j]) {
        nums1[x] = nums1[i];
        i--;
        x--;
      } else {
        nums1[x] = nums2[j];
        j--;
        x--;
      }
    }
  }
};
// @lc code=end
