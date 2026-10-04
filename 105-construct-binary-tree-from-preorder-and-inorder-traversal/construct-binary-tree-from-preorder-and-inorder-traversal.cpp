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
TreeNode* build(vector<int>& preorder, int &preindex, int instrt, int inend, unordered_map<int, int>&mp){
    if(instrt>inend)return nullptr;
    int rootvalue=preorder[preindex++];
    TreeNode* node=new TreeNode(rootvalue);
    int pos=mp[rootvalue];
    node->left=build(preorder, preindex, instrt, pos-1, mp);
    node->right=build(preorder, preindex, pos+1, inend, mp);
    return node;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        int preindex=0;
        return build(preorder, preindex, 0, inorder.size()-1, mp);
    }
};