#include <iostream>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = right = nullptr;
    }
};

bool isSameTree(TreeNode* p, TreeNode* q){

    if(p == nullptr && q == nullptr)
        return true;

    if(p == nullptr || q == nullptr)
        return false;

    if(p->val != q->val)
        return false;

    return isSameTree(p->left,q->left) &&
           isSameTree(p->right,q->right);
}

int main(){

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    if(isSameTree(p,q))
        cout << "True";
    else
        cout << "False";

    return 0;
}