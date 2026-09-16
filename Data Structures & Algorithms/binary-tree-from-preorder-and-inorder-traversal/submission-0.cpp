/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int find(vector<int>& inorder, int val, int l, int r){
        for(int i=l;i<=r;i++){
            if(inorder[i] == val){
                return i;
            }
        }

        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int l, int r){
        if(l>r) return NULL;

        TreeNode* root = new TreeNode(preorder[preIdx]);
        int inIdx = find(inorder, preorder[preIdx], l, r);
        preIdx++;

        root->left = helper(preorder, inorder, preIdx, l, inIdx-1);
        root->right = helper(preorder, inorder, preIdx, inIdx+1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;

        return helper(preorder, inorder, preIdx, 0, preorder.size()-1);
    }
};
