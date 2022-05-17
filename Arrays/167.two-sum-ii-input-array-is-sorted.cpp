/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (57.77%)
 * Likes:    5421
 * Dislikes: 942
 * Total Accepted:    966.1K
 * Total Submissions: 1.6M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given a 1-indexed array of integers numbers that is already sorted in
 * non-decreasing order, find two numbers such that they add up to a specific
 * target number. Let these two numbers be numbers[index1] and numbers[index2]
 * where 1 <= index1 < index2 <= numbers.length.
 * 
 * Return the indices of the two numbers, index1 and index2, added by one as an
 * integer array [index1, index2] of length 2.
 * 
 * The tests are generated such that there is exactly one solution. You may not
 * use the same element twice.
 * 
 * Your solution must use only constant extra space.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We
 * return [1, 2].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numbers = [2,3,4], target = 6
 * Output: [1,3]
 * Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We
 * return [1, 3].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: numbers = [-1,0], target = -1
 * Output: [1,2]
 * Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We
 * return [1, 2].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= numbers.length <= 3 * 10^4
 * -1000 <= numbers[i] <= 1000
 * numbers is sorted in non-decreasing order.
 * -1000 <= target <= 1000
 * The tests are generated such that there is exactly one solution.
 * 
 * 
 */


#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


// @lc code=start
class Solution {
public:
    //////////////////////////////////
    //////      APPROACH 00      //////
    //////////////////////////////////
    // Brute Force
    // Check all possible pairs
    // Time Complexity - O(n^2)
    // TLE!!
    vector<int> twoSum0(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int>out(2);
        for (int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++){
                if(numbers[i] + numbers[j] == target){
                    out[0] = i+1;
                    out[1] = j+1;
                }
            }
        }
        return out;
    }

    //////////////////////////////////
    //////      APPROACH 01      //////
    //////////////////////////////////
    // Brute Force
    // Check all possible pairs
    // Time Complexity - O(n^2) but less number of comparisons
    // TLE!!
    vector<int> twoSum01(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int>out(2);
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while(j < n){
                int sum = numbers[i] + numbers[j];
                if(sum == target){
                    out[0] = i+1;
                    out[1] = j+1;
                    return out;
                }
                j++;
            }
        }
        return out;
    }

    //////////////////////////////////
    //////      APPROACH 1      //////
    //////////////////////////////////
    // Elegant Two pointer
    // Time Complexity - O(n)
    // Space Complexity - O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j = n -1;
        while (i < j) {
            if(numbers[i] + numbers[j] > target){
                int temp = numbers[j];
                while (numbers[j] == temp) {
                    j--;
                }
            }else if(numbers[i] + numbers[j] < target){
                int temp = numbers[i];
                while (numbers[i] == temp) {
                    i++;
                }
            }else{
                return {i+1, j+1};
            }
        }
        return {};
    }
};
// @lc code=end
