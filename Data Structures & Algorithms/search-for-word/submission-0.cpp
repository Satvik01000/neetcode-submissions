class Solution {
private:
    int n, m;

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    bool isValid(int r, int c) {
        return (r >= 0 && r < n && c >= 0 && c < m);
    }

    bool helper(int i, int j, int idx, vector<vector<char>>& board, string& word) {

        if(idx == word.size()) return true;

        if(!isValid(i, j) || board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '#';

        for(int k = 0; k < 4; k++) {
            int newRow = i + dx[k];
            int newCol = j + dy[k];

            if(helper(newRow, newCol, idx + 1, board, word)) return true;
        }

        board[i][j] = temp;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(helper(i, j, 0, board, word)) return true;
            }
        }
        return false;
    }
};