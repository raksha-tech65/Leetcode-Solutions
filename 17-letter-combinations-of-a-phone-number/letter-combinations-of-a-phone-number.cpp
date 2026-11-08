
class Solution {
public:
    vector<string> ans;
    string mp[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
    void solve(int index, string digits, string curr) {
        if (index == digits.size()) {
            ans.push_back(curr);
            return;
        }
        int digit = digits[index] - '0';
        for (char ch : mp[digit]) {
            curr.push_back(ch);
            solve(index + 1, digits, curr);
            curr.pop_back();  
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        solve(0, digits, "");
        return ans;
    }
};
