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

TreeNode* searchBST(TreeNode* root,int val){

    while(root){

        if(root->val==val)
            return root;

        if(val<root->val)
            root=root->left;
        else
            root=root->right;
    }

    return nullptr;
}

int main(){

    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);

    TreeNode* ans=searchBST(root,2);

    if(ans)
        cout<<ans->val;
    else
        cout<<"Not Found";

    return 0;
}