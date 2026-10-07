class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {

            // Left subtree nahi hai
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            }

            // Left subtree exists
            else {
                TreeNode* prev = curr->left;

                // Inorder predecessor find karo
                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }

                // First time current par aaye
                if (prev->right == NULL) {
                    prev->right = curr;   // Temporary thread
                    curr = curr->left;
                }

                // Second time current par aaye
                else {
                    prev->right = NULL;   // Thread remove
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};