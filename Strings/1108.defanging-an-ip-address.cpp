/*
 * @lc app=leetcode id=1108 lang=cpp
 *
 * [1108] Defanging an IP Address
 *
 * https://leetcode.com/problems/defanging-an-ip-address/description/
 *
 * algorithms
 * Easy (88.70%)
 * Likes:    1025
 * Dislikes: 1438
 * Total Accepted:    392.7K
 * Total Submissions: 441.7K
 * Testcase Example:  '"1.1.1.1"'
 *
 * Given a valid (IPv4) IP address, return a defanged version of that IP
 * address.
 * 
 * A defanged IP address replaces every period "." with "[.]".
 * 
 * 
 * Example 1:
 * Input: address = "1.1.1.1"
 * Output: "1[.]1[.]1[.]1"
 * Example 2:
 * Input: address = "255.100.50.0"
 * Output: "255[.]100[.]50[.]0"
 * 
 * 
 * Constraints:
 * 
 * 
 * The given address is a valid IPv4 address.
 * 
 */


#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    //////////////////////////////////
    //////      APPROACH 1      //////
    //////////////////////////////////
    // Bruteforce
    // Time - O(n)
    // Space - O(n)

    string defangIPaddr(string address) {
        string res;
        for(int i = 0; i < address.size(); i++){
            if(address[i] == '.'){
                res+="[.]";
            }else{
                res+=address[i];
            }
        }
        return res;
    }
};
// @lc code=end
