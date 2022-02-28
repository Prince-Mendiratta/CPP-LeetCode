/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (67.93%)
 * Likes:    2516
 * Dislikes: 1853
 * Total Accepted:    622.4K
 * Total Submissions: 908.3K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two integer arrays nums1 and nums2, return an array of their
 * intersection. Each element in the result must be unique and you may return
 * the result in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * Explanation: [4,9] is also accepted.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 * 
 * 
 */


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


// @lc code=start
//////////////////////////////////
//////      APPROACH 1      //////
//////////////////////////////////
// Bruteforce
// HashTable
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        
        vector<int> res;
        
        for(int i = 0; i < nums1.size(); i++){
            m1[nums1[i]]++;
        }
        
        for(int i = 0; i < nums2.size(); i++){
            m2[nums2[i]]++;
        }
        
        for(int i = 0; i < nums1.size(); i++){
            if(m1[nums1[i]] > 0 && m2[nums1[i]] > 0){
                res.push_back(nums1[i]);
                m1[nums1[i]] = 0;
            }
        }
        
        return res;
    }
};
// @lc code=end
