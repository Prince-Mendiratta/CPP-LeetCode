/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (45.86%)
 * Likes:    5909
 * Dislikes: 214
 * Total Accepted:    485.5K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3,4]'
 *
 * You are given the head of a singly linked-list. The list can be represented
 * as:
 * 
 * 
 * L0 → L1 → … → Ln - 1 → Ln
 * 
 * 
 * Reorder the list to be on the following form:
 * 
 * 
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * 
 * 
 * You may not modify the values in the list's nodes. Only nodes themselves may
 * be changed.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4]
 * Output: [1,4,2,3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2,3,4,5]
 * Output: [1,5,2,4,3]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [1, 5 * 10^4].
 * 1 <= Node.val <= 1000
 * 
 * 
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;


// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    //////////////////////////////////
    //////      APPROACH 0      //////
    //////////////////////////////////
    // If the values were allowed to be changed.
    // Time Complexity - O(n)
    // Space Complexity - O(n)
    void reorderList0(ListNode* head) {
        vector<int> res;
        ListNode* p = head;
        while(p){
            res.push_back(p->val);
            p = p->next;
        }
        p = head;
        int i = 0;
        int itr = 0;
        while (p) {
            if(itr % 2 == 0){
                p->val = res[i];
            }else{
                p->val = res[res.size()-1-i];
                i++;
            }
            p = p->next;
            itr++;
        }
    }

    //////////////////////////////////
    //////      APPROACH 0      //////
    //////////////////////////////////
    // If the values were allowed to be changed.
    // Time Complexity - O(n)
    // Space Complexity - O(n)
    void reorderList(ListNode* head) {
        vector<ListNode*> res;
        ListNode* p = head;
        while(p){
            res.push_back(p);
            p = p->next;
        }
        p = head;
        int i = 0;
        int itr = 1;
        while (itr != res.size()-1) {
            cout<<p->val<<" ";
            if(itr % 2 == 0){
                p->next = res[i];
                p = p->next;
            }else{
                p->next = res[res.size()-1-i];
                p = p->next;
                i++;
            }
            itr++;
        }
    }
};
// @lc code=end
