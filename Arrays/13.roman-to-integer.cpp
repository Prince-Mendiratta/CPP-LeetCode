/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (57.69%)
 * Likes:    2656
 * Dislikes: 184
 * Total Accepted:    1.3M
 * Total Submissions: 2.2M
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, 2 is written as II in Roman numeral, just two one's added
 * together. 12 is written as XII, which is simply X + II. The number 27 is
 * written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given a roman numeral, convert it to an integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "III"
 * Output: 3
 * Explanation: III = 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 15
 * s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
 * It is guaranteed that s is a valid roman numeral in the range [1, 3999].
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
    // Bruteforce
    int romanToInt(string s) {
        int out = 0, temp;
        for (int i = 0; i < s.length(); i++) {
            temp = getInteger(s[i]);
            if(temp < getInteger(s[i+1])) {
                out -= temp;
            }else{
                out += getInteger(s[i]);
            }
        }
        return out;
    }

    int getInteger(char roman) {
        switch (roman) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }

    // Best approach - https://leetcode.com/problems/roman-to-integer/discuss/1074149/JS-Python-Java-C%2B%2B-or-Switch-Dictionary-Solution-w-Explanation-or-beats-100
    // int romanToInt(string S) {
    //     int ans = 0, num = 0;
    //     for (int i = S.size()-1; ~i; i--) {
    //         switch(S[i]) {
    //             case 'I': num = 1; break;
    //             case 'V': num = 5; break;
    //             case 'X': num = 10; break;
    //             case 'L': num = 50; break;
    //             case 'C': num = 100; break;
    //             case 'D': num = 500; break;
    //             case 'M': num = 1000; break;
    //         }
    //         if (4 * num < ans) ans -= num;
    //         else ans += num;
    //     }
    //     return ans;        
    // }
};
// @lc code=end

/**
Things to note -
1. Switch case.
*/