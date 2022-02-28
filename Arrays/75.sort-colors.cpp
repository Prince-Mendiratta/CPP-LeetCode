/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (53.35%)
 * Likes:    8744
 * Dislikes: 385
 * Total Accepted:    922.7K
 * Total Submissions: 1.7M
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array nums with n objects colored red, white, or blue, sort them
 * in-place so that objects of the same color are adjacent, with the colors in
 * the order red, white, and blue.
 * 
 * We will use the integers 0, 1, and 2 to represent the color red, white, and
 * blue, respectively.
 * 
 * You must solve this problem without using the library's sort function.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,0,1]
 * Output: [0,1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 300
 * nums[i] is either 0, 1, or 2.
 * 
 * 
 * 
 * Follow up: Could you come up with a one-pass algorithm using only constant
 * extra space?
 * 
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;


// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& a) {
        int ones = 0;
        int twos = 0;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if(a[i] == 1) ones++;
            else if(a[i] == 2) twos++;
        }
        // Approach 1
        for (int i = 0; i < n; i++) {
            if (i < (n - (ones + twos))) a[i] = 0;
            else if (i < (n - twos)) a[i] = 1;
            else a[i] = 2;
        }
        // Approach 2
        int zeros = n - (ones+twos);
        int x = 0;
        while(zeros--){
            a[x] = 0;
            x++;
        }
        while(ones--){
            a[x] = 1;
            x++;
        }
        while(twos--){
            a[x] = 2;
            x++;
        }
    }
};
// @lc code=end
