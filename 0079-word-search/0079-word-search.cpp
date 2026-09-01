class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word,
             int row, int col, int index) {

        // Word completely found
        if (index == word.length()) {
            return true;
        }

        // Check boundaries and character match
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size() ||
            board[row][col] != word[index]) {
            return false;
        }

        // Mark current cell as visited
        char temp = board[row][col];
        board[row][col] = '#';

        // Check all 4 directions
        bool found = dfs(board, word, row + 1, col, index + 1) ||
                     dfs(board, word, row - 1, col, index + 1) ||
                     dfs(board, word, row, col + 1, index + 1) ||
                     dfs(board, word, row, col - 1, index + 1);

        // Restore the cell
        board[row][col] = temp;

        return found;
    }
};