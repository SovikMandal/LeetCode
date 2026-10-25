class Solution {
public:
    bool closed(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (grid[i][j]) return true;
        grid[i][j] = 1;
        return closed(grid, i + 1, j) & closed(grid, i - 1, j) & closed(grid, i, j + 1) & closed(grid, i, j - 1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!grid[i][j]) count += closed(grid, i, j);
            }
        }

        return count;
    }
};