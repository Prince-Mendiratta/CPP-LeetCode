/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (68.19%)
 * Likes:    9254
 * Dislikes: 326
 * Total Accepted:    1.6M
 * Total Submissions: 2.3M
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers nums, every element appears twice except
 * for one. Find that single one.
 * 
 * You must implement a solution with a linear runtime complexity and use only
 * constant extra space.
 * 
 * 
 * Example 1:
 * Input: nums = [2,2,1]
 * Output: 1
 * Example 2:
 * Input: nums = [4,1,2,1,2]
 * Output: 4
 * Example 3:
 * Input: nums = [1]
 * Output: 1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * -3 * 10^4 <= nums[i] <= 3 * 10^4
 * Each element in the array appears twice except for one element which appears
 * only once.
 * 
 * 
 */


#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


// @lc code=start
class Solution {
public:
    //////////////////////////////////
    //////      APPROACH 1      //////
    //////////////////////////////////
    // Bruteforce
    // Time - O(n)
    // Space - O(n)

    int singleNumber(vector<int>& nums) {
        unordered_map<int, int>f;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            f[nums[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if(f[nums[i]] == 1){
                return nums[i];
            }
        }

        return -1;
    }

    //////////////////////////////////
    //////      APPROACH 2      //////
    //////////////////////////////////
    // Sorting the array
    // Time - O(n)
    // Space - O(1)

    int singleNumber1(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != nums[i+1]) {
                return nums[i];
            }
            i += 2;
        }
        return -1;
    }
};
// @lc code=end
