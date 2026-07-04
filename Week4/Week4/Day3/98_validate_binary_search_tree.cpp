#include <iostream>
#include <climits>

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

bool solve(TreeNode* root,long long low,long long high){

    if(root==nullptr)
        return true;

    if(root->val<=low || root->val>=high)
        return false;

    return solve(root->left,low,root->val) &&
           solve(root->right,root->val,high);
}

int main(){

    TreeNode* root=new TreeNode(2);
    root->left=new TreeNode(1);
    root->right=new TreeNode(3);

    if(solve(root,LLONG_MIN,LLONG_MAX))
        cout<<"True";
    else
        cout<<"False";

    return 0;
}