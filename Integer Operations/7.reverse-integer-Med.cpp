/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Medium (26.33%)
 * Total Accepted:    1.9M
 * Total Submissions: 7.2M
 * Testcase Example:  '123'
 *
 * Given a signed 32-bit integer x, return x with its digits reversed. If
 * reversing x causes the value to go outside the signed 32-bit integer range
 * [-2^31, 2^31 - 1], then return 0.
 * 
 * Assume the environment does not allow you to store 64-bit integers (signed
 * or unsigned).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: x = 120
 * Output: 21
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= x <= 2^31 - 1
 * 
 * 
 */

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0, rem;
        while(x != 0){
            if(rev > INT32_MAX / 10 || rev < INT32_MIN / 10) return 0;
            rem = x % 10;
            rev = rev * 10 + rem;
            x /= 10;
        }
        return rev;
    }
};

/* Things to note -
1. Reversing an integer
2. Check if an operation will overflow the int datatype
*/