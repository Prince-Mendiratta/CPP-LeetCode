/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.55%)
 * Likes:    11473
 * Dislikes: 497
 * Total Accepted:    2M
 * Total Submissions: 4.9M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "(]"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 * 
 * 
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;


// @lc code=start
class MyStack{
    private:
        int arr[100000];
        int top;
    public:
        MyStack() {top = -1;}
        int pop();
        void push(int);
};

void MyStack::push(int x){
    if(top == 99999) return;
    arr[++top] = x;
}

int MyStack::pop() {
    if(top == -1) return -1;
    top--;
    return arr[top+1];
}

class Solution {
public:
    bool isValid(string x) {
        MyStack sq = MyStack();
        bool flag = false;
        int out;
        for(int i = 0; i < x.size(); i++){
            char bracket = x[i];
            switch(bracket){
                case '(':
                    sq.push(0);
                    break;
                case ')':
                    out = sq.pop();
                    if(out != 0){
                        flag = true;
                        break;
                    }
                    break;
                case '[':
                    sq.push(1);
                    break;
                case ']':
                    out = sq.pop();
                    if(out != 1){
                        flag = true;
                        break;
                    }
                    break;
                case '{':
                    sq.push(2);
                    break;
                case '}':
                    out = sq.pop();
                    if(out != 2){
                        flag = true;
                        break;
                    }
                    break;
                default:
                    cout<<"eh";
            }
            if(flag){
                return false;
            }
        }
        int f = sq.pop();
        if(f != -1){
            return false;
        }
        return true;
    }
};
// @lc code=end
