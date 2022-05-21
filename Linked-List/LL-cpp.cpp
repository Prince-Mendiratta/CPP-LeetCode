#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main() {
	int num,x;
	cin >> num;    //Reading input from STDIN
    cin>>x;
	ListNode *first = new ListNode(x);
    ListNode *last = first;
	for(int i = 0; i < num-1; i++){
		cin>>x;
        ListNode *temp = new ListNode(x);
        last->next = temp;
        last = temp;
	}
    ListNode *p = first;
    while(p){
        cout<<p->val<<" ";
        p = p->next;
    }
}