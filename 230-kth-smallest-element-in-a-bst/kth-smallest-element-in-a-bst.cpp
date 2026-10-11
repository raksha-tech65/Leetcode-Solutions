
class Solution {
public:
    int cnt = 0;
    int ans = -1;
    void inorder(TreeNode* root, int k) {
        if (root == nullptr || cnt >= k) return; 
        inorder(root->left, k);
        if (cnt >= k) return; 
        cnt++;
        if (cnt == k) {
            ans = root->val;
            return;
        }
        inorder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        cnt = 0;  
        ans = -1; 
        inorder(root, k);
        return ans;
    }
};
