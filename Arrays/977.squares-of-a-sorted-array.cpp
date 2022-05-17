/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 *
 * https://leetcode.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (71.43%)
 * Likes:    5295
 * Dislikes: 156
 * Total Accepted:    987.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * Given an integer array nums sorted in non-decreasing order, return an array
 * of the squares of each number sorted in non-decreasing order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * Explanation: After squaring, the array becomes [16,1,0,9,100].
 * After sorting, it becomes [0,1,9,16,100].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums is sorted in non-decreasing order.
 * 
 * 
 * 
 * Follow up: Squaring each element and sorting the new array is very trivial,
 * could you find an O(n) solution using a different approach?
 */


#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    //////////////////////////////////
    //////      APPROACH 1      //////
    //////////////////////////////////
    // Use two pointers and insert the absolute higher value's square
    // Time Complexity - O(n)
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0, j = nums.size()-1, x = nums.size()-1;
        vector<int>out(nums.size());
        while(i<=j){
            if(nums[i] < 0){
                if(abs(nums[i]) > nums[j]){
                    out[x] = pow(nums[i], 2);
                    i++;
                    x--;
                }else{
                    out[x] = pow(nums[j], 2);
                    j--;
                    x--;
                }
            }else{
                out[x] = pow(nums[j],2);
                x--;
                j--;
            }
        }
        return out;
    }

    //////////////////////////////////
    //////      APPROACH 2      //////
    //////////////////////////////////
    // Square and sort
    // Time Complexity - O(nlogn)
    vector<int> sortedSquares2(vector<int>& nums) {
        vector<int>out(nums.size());
        for(int i = 0; i < nums.size(); i++){
            out[i] = pow(nums[i], 2);
        }
        sort(out.begin(), out.end());
        return out;
    }
};
// @lc code=end
