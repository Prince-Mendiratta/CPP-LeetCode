/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (61.78%)
 * Likes:    8940
 * Dislikes: 322
 * Total Accepted:    1.2M
 * Total Submissions: 1.9M
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array nums of size n, return the majority element.
 * 
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * You may assume that the majority element always exists in the array.
 * 
 * 
 * Example 1:
 * Input: nums = [3,2,3]
 * Output: 3
 * Example 2:
 * Input: nums = [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 5 * 10^4
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 * 
 * Follow-up: Could you solve the problem in linear time and in O(1) space?
 */


#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
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

    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int x = n/2;
        unordered_map<int, int>m;
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if(m[nums[i]] > x){
                return nums[i];
            }
        }
        return -1;
    }

    //////////////////////////////////
    //////      APPROACH 2      //////
    //////////////////////////////////
    // Sorting the Array fully
    // Using two iterators to keep track of frequency of number and once counter exceeds n/2, return.
    // Time - O(nlogn)
    // Space - O(1)

    int majorityElement1(vector<int>& nums) {
        int n = nums.size();
        int x = n/2;
        int cnt = 0;
        vector<int>::iterator f = nums.begin();
        vector<int>::iterator t = nums.begin();
        sort(nums.begin(), nums.end());
        while (f != nums.end()) {
            if(*t == *f){
                cnt++;
            }else{
                t = f;
                cnt = 0;
                cnt++;
            }
            if (cnt > x) {
                return *f;
            }
            f++;
        }
        return -1;
    }

    //////////////////////////////////
    //////      APPROACH 3      //////
    //////////////////////////////////
    // Partial Sort till n/2 element and return it
    // Time - O(n)
    // Space - O(1)

    int majorityElement2(vector<int>& nums) {
        int n = nums.size();
        int x = n/2;
        nth_element(nums.begin(), nums.begin() + x, nums.end());
        return nums[nums.size()/2];
    }
};
// @lc code=end
