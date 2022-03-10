/*
 * @lc app=leetcode id=1678 lang=cpp
 *
 * [1678] Goal Parser Interpretation
 *
 * https://leetcode.com/problems/goal-parser-interpretation/description/
 *
 * algorithms
 * Easy (85.27%)
 * Likes:    633
 * Dislikes: 59
 * Total Accepted:    96K
 * Total Submissions: 112.2K
 * Testcase Example:  '"G()(al)"'
 *
 * You own a Goal Parser that can interpret a string command. The command
 * consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal
 * Parser will interpret "G" as the string "G", "()" as the string "o", and
 * "(al)" as the string "al". The interpreted strings are then concatenated in
 * the original order.
 * 
 * Given the string command, return the Goal Parser's interpretation of
 * command.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: command = "G()(al)"
 * Output: "Goal"
 * Explanation: The Goal Parser interprets the command as follows:
 * G -> G
 * () -> o
 * (al) -> al
 * The final concatenated result is "Goal".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: command = "G()()()()(al)"
 * Output: "Gooooal"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: command = "(al)G(al)()()G"
 * Output: "alGalooG"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= command.length <= 100
 * command consists of "G", "()", and/or "(al)" in some order.
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
    string asciiToChar(int val) {
        switch(val){
            case 71:
                return "G";
            case 81:
                return "o";
            case 286:
                return "al";
            default:
                return "0";
        }
        return "0";
    }
    
    string interpret(string command) {
        int count = 0;
        string res = "";
        for(int i = 0; i < command.size(); i++){
            count += int(command[i]);
            string x = asciiToChar(count);
            if(x == "0"){
                //
            }else{
                res += x;
                count = 0;
            }
        }
        return res;
    }
};
// @lc code=end
