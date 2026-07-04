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

bool hasPathSum(TreeNode* root,int target){

    if(root==nullptr)
        return false;

    if(root->left==nullptr && root->right==nullptr)
        return target==root->val;

    return hasPathSum(root->left,target-root->val) ||
           hasPathSum(root->right,target-root->val);
}

int main(){

    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(4);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(11);
    root->left->left->left=new TreeNode(7);
    root->left->left->right=new TreeNode(2);

    if(hasPathSum(root,22))
        cout<<"True";
    else
        cout<<"False";

    return 0;
}