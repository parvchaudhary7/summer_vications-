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

TreeNode* lowestCommonAncestor(TreeNode* root,
                               TreeNode* p,
                               TreeNode* q){

    while(root){

        if(p->val<root->val &&
           q->val<root->val)
            root=root->left;

        else if(p->val>root->val &&
                q->val>root->val)
            root=root->right;

        else
            return root;
    }

    return nullptr;
}

int main(){

    TreeNode* root=new TreeNode(6);

    root->left=new TreeNode(2);
    root->right=new TreeNode(8);

    root->left->left=new TreeNode(0);
    root->left->right=new TreeNode(4);

    TreeNode* p=root->left;
    TreeNode* q=root->right;

    TreeNode* ans=lowestCommonAncestor(root,p,q);

    cout<<ans->val;

    return 0;
}