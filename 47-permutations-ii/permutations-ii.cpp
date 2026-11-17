
class Solution {
public:
    void solve(vector<int>& nums,
               vector<int>& ds,
               vector<vector<int>>& ans,
               vector<bool>& visited) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            if (i > 0 && nums[i] == nums[i-1]
                && !visited[i-1]) {
                continue;
            }
            visited[i] = true;
            ds.push_back(nums[i]);
            solve(nums, ds, ans, visited);
            ds.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        solve(nums, ds, ans, visited);
        return ans;
    }
};
