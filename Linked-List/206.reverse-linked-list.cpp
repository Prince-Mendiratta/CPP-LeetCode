/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (68.86%)
 * Likes:    10882
 * Dislikes: 184
 * Total Accepted:    2M
 * Total Submissions: 2.8M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, reverse the list, and return the
 * reversed list.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2]
 * Output: [2,1]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = []
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is the range [0, 5000].
 * -5000 <= Node.val <= 5000
 * 
 * 
 * 
 * Follow up: A linked list can be reversed either iteratively or recursively.
 * Could you implement both?
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //////////////////////////////////
        //////      APPROACH 1      //////
        //////////////////////////////////
        // Brute force
        // Time - O(n)
        // Space - O(n)

        ListNode *p = head;
        vector<int> vc;
        while(p){
            vc.push_back(p->val);
            p = p->next;
        }
        p = head;
        for(int i = (vc.size() - 1); i >= 0; i--){
            p->val = vc[i];
            p = p->next;
        }
        return head;

        //////////////////////////////////
        //////      APPROACH 2      //////
        //////////////////////////////////
        // Sliding Pointers
        ListNode *p = NULL, *q = NULL;
        while(head){
            q = p;
            p = head;
            head = head->next;
            p->next = q;
        }
        return p;
    }
};
// @lc code=end
