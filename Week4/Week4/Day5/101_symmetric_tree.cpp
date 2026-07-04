#include <iostream>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val=x;
        left=right=nullptr;
    }
};

bool mirror(TreeNode* left,TreeNode* right){

    if(left==nullptr && right==nullptr)
        return true;

    if(left==nullptr || right==nullptr)
        return false;

    if(left->val!=right->val)
        return false;

    return mirror(left->left,right->right) &&
           mirror(left->right,right->left);
}

int main(){

    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(3);

    if(mirror(root->left,root->right))
        cout<<"True";
    else
        cout<<"False";

    return 0;
}