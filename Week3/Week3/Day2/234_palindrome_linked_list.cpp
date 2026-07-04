#include <iostream>
#include <vector>

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

bool isPalindrome(ListNode* head){

    vector<int> nums;

    while(head){
        nums.push_back(head->val);
        head = head->next;
    }

    int left = 0;
    int right = nums.size()-1;

    while(left < right){

        if(nums[left] != nums[right])
            return false;

        left++;
        right--;
    }

    return true;
}

int main(){

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    if(isPalindrome(head))
        cout<<"True";
    else
        cout<<"False";

    return 0;
}