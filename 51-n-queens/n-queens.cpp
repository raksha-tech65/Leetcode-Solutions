
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    vector<int> col, leftDiag, rightDiag;
    void solve(int row, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++) {
            if (col[c] == 0 &&
                leftDiag[row + c] == 0 &&
                rightDiag[row - c + n - 1] == 0) {
                board[row][c] = 'Q';
                col[c] = 1;
                leftDiag[row + c] = 1;
                rightDiag[row - c + n - 1] = 1;
                solve(row + 1, n);
                board[row][c] = '.';
                col[c] = 0;
                leftDiag[row + c] = 0;
                rightDiag[row - c + n - 1] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        col = vector<int>(n, 0);
        leftDiag = vector<int>(2 * n - 1, 0);
        rightDiag = vector<int>(2 * n - 1, 0);
        solve(0, n);
        return ans;
    }
};
