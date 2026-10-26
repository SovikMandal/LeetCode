class Solution {
private:
    long long dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = true;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        long long sum = grid[row][col];

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
            && grid[nrow][ncol] != 0 && !visited[nrow][ncol]) {
                sum += dfs(grid, visited, nrow, ncol);
            }
        }
        return sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0 && !visited[i][j]) {
                    long long sum = dfs(grid, visited, i, j);
                    if(sum % k == 0) count++;
                }
            }
        }

        return count;
    }
};