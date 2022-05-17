/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (59.92%)
 * Likes:    9145
 * Dislikes: 244
 * Total Accepted:    1.7M
 * Total Submissions: 2.7M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an integer array nums, move all 0's to the end of it while maintaining
 * the relative order of the non-zero elements.
 * 
 * Note that you must do this in-place without making a copy of the array.
 * 
 * 
 * Example 1:
 * Input: nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * Example 2:
 * Input: nums = [0]
 * Output: [0]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you minimize the total number of operations done?
 */


#include <iostream>
#include <shared_mutex>
#include <string>
#include <vector>
using namespace std;


// @lc code=start
class Solution {
public:
    //////////////////////////////////
    //////      APPROACH 1      //////
    //////////////////////////////////
    // Brute Force
    // Time Complexity - O(n^2)
    // In place solution
    void moveZeroes(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0){
                for (int j = i + 1; j < nums.size(); j++) {
                    if(nums[j] != 0){
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
    }

    //////////////////////////////////
    //////      APPROACH 2      //////
    //////////////////////////////////
    // Brute Force
    // Time Complexity - O(n)
    // Space Complexity - O(n)
    void moveZeroes2(vector<int>& nums) {
        vector<int> out(nums.size());
        int zeroes = 0;
        int i = 0, x = 0;
        while(i < nums.size()){
            if(nums[i] == 0){
                zeroes++;
            }else{
                out[x] = nums[i];
                x++;
            }
            i++;
        }
        while (x < nums.size()) {
            out[x] = 0;
            x++;
        }
        nums = out;
    }

    //////////////////////////////////
    //////      APPROACH 3      //////
    //////////////////////////////////
    // Elegant Two pointer
    // Time Complexity - O(n)
    void moveZeroes3(vector<int>& nums) {
        int i = 0, j = 1, n = nums.size();
        while(j < n){
            if (nums[i] == 0 && nums[j] == 0) {
                j++;
            }else if(nums[i] == 0 && nums[j] != 0){
                swap(nums[i], nums[j]);
                i++;
                j++;
            }else{
                i++;
                j++;
            }
        }
    }
};
// @lc code=end
