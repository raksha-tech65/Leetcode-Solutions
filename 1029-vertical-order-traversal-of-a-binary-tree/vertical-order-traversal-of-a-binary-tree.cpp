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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>>mp;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        while(!q.empty()){
            int size=q.size();
            vector<pair<int, int>>level;
            for(int i=0; i<size; i++){
                TreeNode* node=q.front().first;
                int col=q.front().second;
                q.pop();
                level.push_back({col, node->val});
                if(node->left)
                    q.push({node->left, col-1});
                    if(node->right)
                    q.push({node->right, col+1});
            }
            sort(level.begin(), level.end());
            for(auto x : level){
                mp[x.first].push_back(x.second);
            }
        }
        vector<vector<int>>ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};