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

    bool helper(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL) return p == q;

        if(p->val != q->val) return false;

        bool l = helper(p->left, q->left);
        bool r = helper(p->right, q->right);

        return l && r;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL){
            return false;
        }
        if(subRoot == NULL){
            return true;
        }
        if(root->val == subRoot->val){
            return helper(root, subRoot);
        }

        bool l = isSubtree(root->left, subRoot);
        bool r = isSubtree(root->right, subRoot);

        return l || r;
    }
};
