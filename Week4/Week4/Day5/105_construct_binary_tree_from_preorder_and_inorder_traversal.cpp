#include <iostream>
#include <vector>
#include <unordered_map>

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

unordered_map<int,int> mp;

TreeNode* build(vector<int>& preorder,int ps,int pe,
                vector<int>& inorder,int is,int ie){

    if(ps>pe || is>ie)
        return nullptr;

    TreeNode* root=new TreeNode(preorder[ps]);

    int index=mp[root->val];
    int left=index-is;

    root->left=build(preorder,ps+1,ps+left,
                     inorder,is,index-1);

    root->right=build(preorder,ps+left+1,pe,
                      inorder,index+1,ie);

    return root;
}

void preorderPrint(TreeNode* root){

    if(root==nullptr)
        return;

    cout<<root->val<<" ";

    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main(){

    vector<int> preorder={3,9,20,15,7};
    vector<int> inorder={9,3,15,20,7};

    for(int i=0;i<inorder.size();i++)
        mp[inorder[i]]=i;

    TreeNode* root=build(preorder,0,preorder.size()-1,
                         inorder,0,inorder.size()-1);

    preorderPrint(root);

    return 0;
}