#include <iostream>
#include <vector>
#include <queue>

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

vector<vector<int>> levelOrder(TreeNode* root){

    vector<vector<int>> ans;

    if(root == nullptr)
        return ans;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){

        int size = q.size();
        vector<int> level;

        while(size--){

            TreeNode* node = q.front();
            q.pop();

            level.push_back(node->val);

            if(node->left)
                q.push(node->left);

            if(node->right)
                q.push(node->right);
        }

        ans.push_back(level);
    }

    return ans;
}

int main(){

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = levelOrder(root);

    for(auto level : ans){
        for(int x : level)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}