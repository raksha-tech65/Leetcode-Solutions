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
TreeNode* buildTreePostIn(vector<int>&inorder, int is, int ie, vector<int>&postorder, int ps, int pe, map<int, int>&mp){
    if(ps>pe || is>ie)return nullptr;
    TreeNode* root=new TreeNode(postorder[pe]);
    int inroot=mp[postorder[pe]];
    int numleft = inroot-is;
    root->left=buildTreePostIn(inorder, is, inroot-1, postorder, ps, ps+numleft-1, mp);
    root->right=buildTreePostIn(inorder, inroot+1, ie, postorder, ps+numleft, pe-1, mp);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())return nullptr;
        map<int, int>mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        return buildTreePostIn(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mp);
    }
};