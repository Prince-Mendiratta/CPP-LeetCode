/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (42.27%)
 * Likes:    3374
 * Dislikes: 3834
 * Total Accepted:    1M
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,2,3]'
 *
 * You are given a large integer represented as an integer array digits, where
 * each digits[i] is the i^th digit of the integer. The digits are ordered from
 * most significant to least significant in left-to-right order. The large
 * integer does not contain any leading 0's.
 * 
 * Increment the large integer by one and return the resulting array of
 * digits.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: digits = [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * Incrementing by one gives 123 + 1 = 124.
 * Thus, the result should be [1,2,4].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: digits = [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * Incrementing by one gives 4321 + 1 = 4322.
 * Thus, the result should be [4,3,2,2].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: digits = [9]
 * Output: [1,0]
 * Explanation: The array represents the integer 9.
 * Incrementing by one gives 9 + 1 = 10.
 * Thus, the result should be [1,0].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= digits.length <= 100
 * 0 <= digits[i] <= 9
 * digits does not contain any leading 0's.
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
    vector<int> plusOne(vector<int>& digits) {
        // Legacy Way
        int i;
        for (i = digits.size() - 1; i >= 0; i--) {
            if(digits[i] == 9){
                digits[i] = 0;
            }else {
                digits[i] = digits[i] + 1;
                return digits;
            }
        }
        digits[0] = digits[0] + 1;
        digits.push_back(0);
        return digits;

        // STL
        vector<int>::iterator ptr = digits.end() - 1;
        while (*ptr == 9) {
            *ptr = 0;
            if(ptr == digits.begin()){
                *ptr = *ptr + 1;
                digits.push_back(0);
                return digits;
            }
            ptr = ptr - 1;
        }
        *ptr = *ptr + 1;
        return digits;
    }
};
// @lc code=end

/** Things to note
1. Iterating backwards using pointers
2. Check for a specific number in array from backwards
*/