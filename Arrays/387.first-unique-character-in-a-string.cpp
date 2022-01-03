/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (56.06%)
 * Likes:    4198
 * Dislikes: 176
 * Total Accepted:    922.2K
 * Total Submissions: 1.6M
 * Testcase Example:  '"leetcode"'
 *
 * Given a string s, find the first non-repeating character in it and return
 * its index. If it does not exist, return -1.
 * 
 * 
 * Example 1:
 * Input: s = "leetcode"
 * Output: 0
 * Example 2:
 * Input: s = "loveleetcode"
 * Output: 2
 * Example 3:
 * Input: s = "aabb"
 * Output: -1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of only lowercase English letters.
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
    int firstUniqChar(string s) {
        // Bruteforce
        // O(n^2)
        int flag = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == s[i] && i!=j) {
                    break;
                }
                if (j == (s.length() - 1)) {
                    flag = 1;
                }
            }
            if (flag) {
                return i;
            }
        }
        return -1;

        // Index all characer occurences first
        // O(len(s) + 26)
        vector<int> frequency(26,0);
        for (int i = 0; i < s.length(); i++) {
            frequency[(s[i] - 'a')] += 1;
        }
        for (int i = 0; i < s.length(); i++) {
            if(frequency[(s[i] - 'a')] == 1) return i;
        }
        return -1;

        // Even faster
        // https://leetcode.com/problems/first-unique-character-in-a-string/discuss/979061/C%2B%2B-Array-based-Solutions-Compared-and-Explained-~100-Time-~90-Space
        int len = s.size(), alpha[127] = {}, seenTwice = 0;
		// populating alpha as long as it is needed
        for (char c: s) {
            if (alpha[c] == 1) seenTwice++;
            if (seenTwice == 26) return -1;
            alpha[c]++;
        }
		// hunting for unique elements
        for (int i = 0; i < len; i++) {
            if (alpha[s[i]] == 1) return i;
        }
        return -1;
    }
};
// @lc code=end

/*
Things to note -
1. Iterating through array and marking duplicates.
2. Marking duplicates when characters are involved.
*/