/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (73.07%)
 * Likes:    3589
 * Dislikes: 871
 * Total Accepted:    1.3M
 * Total Submissions: 1.8M
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * Write a function that reverses a string. The input string is given as an
 * array of characters s.
 * 
 * You must do this by modifying the input array in-place with O(1) extra
 * memory.
 * 
 * 
 * Example 1:
 * Input: s = ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * Example 2:
 * Input: s = ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] is a printable ascii character.
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
    void reverseString(vector<char>& s) {
        //////////////////////////////////
        //////      APPROACH 1      //////
        //////////////////////////////////
        // double pointer
        vector<char>::iterator ptr1 = s.begin();
        vector<char>::iterator ptr2 = s.end() - 1;
        for (int i = 0; i < (s.size() / 2); i++) {
            char temp = *ptr2;
            *ptr2 = *ptr1;
            *ptr1 = temp;
            ptr1 = ptr1 + 1;
            ptr2 = ptr2 - 1;
        }
        //////////////////////////////////
        //////      APPROACH 2      //////
        //////////////////////////////////
        // Swap function
        int start = 0, end = s.size() - 1;
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};
// @lc code=end

/*
Things to note -
1. Swapping
2. Iterating front and back using pointers
*/