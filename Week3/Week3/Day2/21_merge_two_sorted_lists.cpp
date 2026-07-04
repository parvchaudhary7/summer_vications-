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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){

    ListNode dummy(0);
    ListNode* tail = &dummy;

    while(list1 && list2){

        if(list1->val < list2->val){
            tail->next = list1;
            list1 = list1->next;
        }
        else{
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    tail->next = (list1)? list1 : list2;

    return dummy.next;
}

int main(){

    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(4);

    ListNode* b = new ListNode(1);
    b->next = new ListNode(3);
    b->next->next = new ListNode(4);

    ListNode* ans = mergeTwoLists(a,b);

    while(ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }

    return 0;
}