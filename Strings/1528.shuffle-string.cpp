/*
 * @lc app=leetcode id=1528 lang=cpp
 *
 * [1528] Shuffle String
 *
 * https://leetcode.com/problems/shuffle-string/description/
 *
 * algorithms
 * Easy (85.82%)
 * Likes:    1260
 * Dislikes: 243
 * Total Accepted:    188.2K
 * Total Submissions: 219.4K
 * Testcase Example:  '"codeleet"\n[4,5,6,7,0,2,1,3]'
 *
 * You are given a string s and an integer array indices of the same length.
 * The string s will be shuffled such that the character at the i^th position
 * moves to indices[i] in the shuffled string.
 * 
 * Return the shuffled string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
 * Output: "leetcode"
 * Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "abc", indices = [0,1,2]
 * Output: "abc"
 * Explanation: After shuffling, each character remains in its position.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * s.length == indices.length == n
 * 1 <= n <= 100
 * s consists of only lowercase English letters.
 * 0 <= indices[i] < n
 * All values of indices are unique.
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
    string restoreString(string s, vector<int>& indices) {
        string res(indices.size(), 'A');
        for(int i = 0; i < indices.size(); i++){
            res[indices[i]] = s[i];
        }
        return res;
    }
};
// @lc code=end
