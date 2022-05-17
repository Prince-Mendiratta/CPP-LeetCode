/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (76.61%)
 * Likes:    2780
 * Dislikes: 166
 * Total Accepted:    447.2K
 * Total Submissions: 567.2K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * Given a string s, reverse the order of characters in each word within a
 * sentence while still preserving whitespace and initial word order.
 * 
 * 
 * Example 1:
 * Input: s = "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * Example 2:
 * Input: s = "God Ding"
 * Output: "doG gniD"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 5 * 10^4
 * s contains printable ASCII characters.
 * s does not contain any leading or trailing spaces.
 * There is at least one word in s.
 * All the words in s are separated by a single space.
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
    //////      APPROACH 1      //////
    //////////////////////////////////
    // Time Complexity - O(n)
    // Space Complexity - O(1)
    string reverseWords(string s) {
        int i = 0, j = 0;
        while(j <= s.size()){
            if(s[j] == ' ' || j == s.size()){
                int x = j-1;
                while(i < x){
                    swap(s[i], s[x]);
                    i++;
                    x--;
                }
                j++;
                i = j;
            }else{
                j++;
            }
        }
        return s;
    }
};
// @lc code=end
