/*
 * @lc app=leetcode id=2011 lang=cpp
 *
 * [2011] Final Value of Variable After Performing Operations
 *
 * https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/
 *
 * algorithms
 * Easy (89.39%)
 * Likes:    404
 * Dislikes: 82
 * Total Accepted:    80.3K
 * Total Submissions: 90K
 * Testcase Example:  '["--X","X++","X++"]'
 *
 * There is a programming language with only four operations and one variable
 * X:
 * 
 * 
 * ++X and X++ increments the value of the variable X by 1.
 * --X and X-- decrements the value of the variable X by 1.
 * 
 * 
 * Initially, the value of X is 0.
 * 
 * Given an array of strings operations containing a list of operations, return
 * the final value of X after performing all the operations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: operations = ["--X","X++","X++"]
 * Output: 1
 * Explanation: The operations are performed as follows:
 * Initially, X = 0.
 * --X: X is decremented by 1, X =  0 - 1 = -1.
 * X++: X is incremented by 1, X = -1 + 1 =  0.
 * X++: X is incremented by 1, X =  0 + 1 =  1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: operations = ["++X","++X","X++"]
 * Output: 3
 * Explanation: The operations are performed as follows:
 * Initially, X = 0.
 * ++X: X is incremented by 1, X = 0 + 1 = 1.
 * ++X: X is incremented by 1, X = 1 + 1 = 2.
 * X++: X is incremented by 1, X = 2 + 1 = 3.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: operations = ["X++","++X","--X","X--"]
 * Output: 0
 * Explanation: The operations are performed as follows:
 * Initially, X = 0.
 * X++: X is incremented by 1, X = 0 + 1 = 1.
 * ++X: X is incremented by 1, X = 1 + 1 = 2.
 * --X: X is decremented by 1, X = 2 - 1 = 1.
 * X--: X is decremented by 1, X = 1 - 1 = 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= operations.length <= 100
 * operations[i] will be either "++X", "X++", "--X", or "X--".
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
    // Bad look

    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();
        int x = 0;
        for(int i = 0; i < n; i++){
            if(operations[i] == "--X"){
                x--;
            }else if(operations[i] == "X--"){
                x--;
            }else if(operations[i] == "++X"){
                x++;
            }else if(operations[i] == "X++"){
                x++;
            }
        }
        return x;
    }
    
    //////////////////////////////////
    //////      APPROACH 2      //////
    //////////////////////////////////
    // Just one comparison
    int finalValueAfterOperations1(vector<string>& operations) {
        int n = operations.size();
        int x = 0;
        for(int i = 0; i < n; i++){
            if(operations[i][1] == '+'){
                x++;
            }else{
                x--;
            }
        }
        return x;
    }
};
// @lc code=end
