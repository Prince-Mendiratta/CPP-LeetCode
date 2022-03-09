/*
 * @lc app=leetcode id=2114 lang=cpp
 *
 * [2114] Maximum Number of Words Found in Sentences
 *
 * https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/description/
 *
 * algorithms
 * Easy (89.15%)
 * Likes:    393
 * Dislikes: 15
 * Total Accepted:    47.5K
 * Total Submissions: 53.2K
 * Testcase Example:  '["alice and bob love leetcode","i think so too","this is great thanks very much"]'
 *
 * A sentence is a list of words that are separated by a single space with no
 * leading or trailing spaces.
 * 
 * You are given an array of strings sentences, where each sentences[i]
 * represents a single sentence.
 * 
 * Return the maximum number of words that appear in a single sentence.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: sentences = ["alice and bob love leetcode", "i think so too", "this
 * is great thanks very much"]
 * Output: 6
 * Explanation: 
 * - The first sentence, "alice and bob love leetcode", has 5 words in total.
 * - The second sentence, "i think so too", has 4 words in total.
 * - The third sentence, "this is great thanks very much", has 6 words in
 * total.
 * Thus, the maximum number of words in a single sentence comes from the third
 * sentence, which has 6 words.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: sentences = ["please wait", "continue to fight", "continue to win"]
 * Output: 3
 * Explanation: It is possible that multiple sentences contain the same number
 * of words. 
 * In this example, the second and third sentences (underlined) have the same
 * number of words.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= sentences.length <= 100
 * 1 <= sentences[i].length <= 100
 * sentences[i] consists only of lowercase English letters and ' ' only.
 * sentences[i] does not have leading or trailing spaces.
 * All the words in sentences[i] are separated by a single space.
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

    int mostWordsFound(vector<string>& sentences) {
        int max = 1;
        for(int i = 0; i<sentences.size(); i++){
            int curr = 1;
            for(int j = 0; j<sentences[i].size(); j++){
                if(sentences[i][j] == ' '){
                    curr++;
                }
            }
            if(curr>max){
                max = curr;
            }
        }
        return max;
    }
};
// @lc code=end
