#include <iostream>

using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = nullptr;
    }
};

ListNode* removeNthFromEnd(ListNode* head,int n){

    ListNode dummy(0);
    dummy.next = head;

    ListNode* fast = &dummy;
    ListNode* slow = &dummy;

    for(int i=0;i<=n;i++)
        fast = fast->next;

    while(fast){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return dummy.next;
}

int main(){

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* ans = removeNthFromEnd(head,2);

    while(ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }

    return 0;
}