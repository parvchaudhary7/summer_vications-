#include <iostream>
#include <algorithm>
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

int ans=INT_MIN;

int dfs(TreeNode* root){

    if(root==nullptr)
        return 0;

    int left=max(0,dfs(root->left));
    int right=max(0,dfs(root->right));

    ans=max(ans,left+right+root->val);

    return root->val+max(left,right);
}

int main(){

    TreeNode* root=new TreeNode(-10);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);

    dfs(root);

    cout<<ans;

    return 0;
}