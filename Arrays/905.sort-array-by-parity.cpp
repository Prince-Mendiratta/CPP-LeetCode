/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 *
 * https://leetcode.com/problems/sort-array-by-parity/description/
 *
 * algorithms
 * Easy (74.79%)
 * Likes:    2507
 * Dislikes: 111
 * Total Accepted:    420.1K
 * Total Submissions: 561.7K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an integer array nums, move all the even integers at the beginning of
 * the array followed by all the odd integers.
 * 
 * Return any array that satisfies this condition.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,1,2,4]
 * Output: [2,4,3,1]
 * Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be
 * accepted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0]
 * Output: [0]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5000
 * 0 <= nums[i] <= 5000
 * 
 * 
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;


// @lc code=start

//////////////////////////////////
//////      APPROACH 1      //////
//////////////////////////////////
// Double Pointer
// Time Complexity - O(n)

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while(i < j){
            bool f1 = false, f2 = false;
            if(nums[i]%2 == 0){
                i++;
            }else{
                f1 = true;
            }
            if(nums[j]%2 == 1){
                j--;
            }else{
                f2 = true;
            }
            if(f1 && f2){
                swap(nums[i++], nums[j--]);
            }
        }
        return nums;
    }
};
// @lc code=end
