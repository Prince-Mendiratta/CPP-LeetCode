#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode();
        ListNode(int x);
        ListNode(int x, ListNode *next);
};

ListNode::ListNode(){
    val = 0;
    next = NULL;
};

ListNode::ListNode(int x){
    val = x;
    next = NULL;
};

ListNode::ListNode(int x, ListNode *next){
    this->val = x;
    this->next = next;
};

void printVal(ListNode *x){
    cout<<x->val;
};

int main() {
    ListNode l = ListNode();
    cout<<l.val;
    printVal(&l);
    return 0;
}