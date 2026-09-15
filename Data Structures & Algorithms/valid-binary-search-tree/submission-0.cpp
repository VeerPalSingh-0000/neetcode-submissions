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

    bool helper(TreeNode* root, TreeNode* mini, TreeNode* maxi){
        if(root == NULL){
            return true;
        }

        if(mini != NULL){
            return root->val > mini->val;
        }
        if(maxi != NULL){
            return root->val < maxi->val;
        }

        bool l = helper(root->left, mini, root);
        bool r = helper(root->right, root, maxi);

        return l && r;

    }

    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        return helper(root, NULL, NULL);
    }
};
