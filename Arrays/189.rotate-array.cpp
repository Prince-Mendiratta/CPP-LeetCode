/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Medium (37.47%)
 * Likes:    8180
 * Dislikes: 1196
 * Total Accepted:    984K
 * Total Submissions: 2.6M
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,4,5,6,7], k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-1,-100,3,99], k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * 0 <= k <= 10^5
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * Try to come up with as many solutions as you can. There are at least three
 * different ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
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
    //////      APPROACH 0      //////
    //////////////////////////////////
    // TLE!!
    // Brute force way to rotate array
    void rotateRight(vector<int> &nums, int k){
        int i = 0, j=nums.size()-1;
        while (i!=j) {
            swap(nums[i], nums[j]);
            i++;
        }
    }

    void rotate0(vector<int>& nums, int k) {
        while (k) {
            rotateRight(nums, k);
            k--;
        }
    }
    
    //////////////////////////////////
    //////      APPROACH 1      //////
    //////////////////////////////////
    // Efficient Method
    void reverse(vector<int>& nums, int begin, int end){
        while(begin < end){
            int temp = nums[end];
            nums[end] = nums[begin];
            nums[begin] = temp;
            begin++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
};
// @lc code=end
