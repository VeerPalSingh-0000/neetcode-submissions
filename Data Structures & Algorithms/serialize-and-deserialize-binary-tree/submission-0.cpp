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

class Codec {
public:

    void helper1(TreeNode* root, string& store){
        if(root == NULL){
            store += "-1,";
            return;
        }
        store += to_string(root->val)+",";
        helper1(root->left, store);
        helper1(root->right, store);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string store = "";
        helper1(root, store);

        return store;
    }

    TreeNode* preorder(vector<int>& v, int& idx){
        if(v[idx] == -1){
            idx++;
            return NULL;
        }

        TreeNode* root = new TreeNode(v[idx]);
        idx++;

        root->left = preorder(v, idx);
        root->right = preorder(v, idx);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int>v;
        string num = "";
        for(char c:data){
            if(c == ','){
                v.push_back(stoi(num));
                num = "";
            }else{
                num += c;
            }
        }
        int idx = 0;
        return preorder(v, idx);
    }
};
