
class Solution {
public:
    void dfs(int node, vector<int>& vis,
             vector<vector<int>>& adjls) {
        vis[node] = 1;
        for (auto it : adjls[node]) {
            if (!vis[it]) {
                dfs(it, vis, adjls);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> adjls(v);
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjls[i].push_back(j);
                }
            }
        }
        vector<int> vis(v, 0);
        int cnt = 0;
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, vis, adjls);
            }
        }
        return cnt;
    }
};
