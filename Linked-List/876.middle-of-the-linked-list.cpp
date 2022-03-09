/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
 *
 * https://leetcode.com/problems/middle-of-the-linked-list/description/
 *
 * algorithms
 * Easy (71.69%)
 * Likes:    4814
 * Dislikes: 120
 * Total Accepted:    580.8K
 * Total Submissions: 803.4K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, return the middle node of the linked
 * list.
 * 
 * If there are two middle nodes, return the second middle node.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5]
 * Output: [3,4,5]
 * Explanation: The middle node of the list is node 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2,3,4,5,6]
 * Output: [4,5,6]
 * Explanation: Since the list has two middle nodes with values 3 and 4, we
 * return the second one.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [1, 100].
 * 1 <= Node.val <= 100
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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //////////////////////////////////
        //////      APPROACH 1      //////
        //////////////////////////////////
        // Brute force

        ListNode * p = head;
        double size =0;
        while(p){
            size++;
            p = p->next;
        }
        int mid = (int(size)%2 == 0) ? (size/2 + 1) : ceil(size/2);
        p = head;
        int i = 1;
        while(i != mid){
            p = p->next;
            i++;
        }
        return p;

        //////////////////////////////////
        //////      APPROACH 1      //////
        //////////////////////////////////
        // Hare and Tortoise approach

        ListNode * slow = head;
        ListNode * fast = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
// @lc code=end
