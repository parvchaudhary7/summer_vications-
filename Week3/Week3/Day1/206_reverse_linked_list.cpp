#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode* reverseList(ListNode* head) {

    ListNode* prev = nullptr;
    ListNode* curr = head;

    while(curr != nullptr) {

        ListNode* nextNode = curr->next;

        curr->next = prev;

        prev = curr;

        curr = nextNode;
    }

    return prev;
}

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* ans = reverseList(head);

    while(ans != nullptr) {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}