class Solution {
private:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    bool isValid(int newRow, int newCol, int n, int m){
        return (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m);
    }
    void dfs(int currRow, int currCol, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        if(!isValid(currRow, currCol, grid.size(), grid[0].size()) || vis[currRow][currCol] || grid[currRow][currCol]!='1') return;
        vis[currRow][currCol] = true;

        for(int i=0; i<4; i++){
            int newRow=currRow+dx[i];
            int newCol=currCol+dy[i];
            dfs(newRow, newCol, grid, vis);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == '1' && !vis[i][j]){
                    count++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return count;
    }
};
