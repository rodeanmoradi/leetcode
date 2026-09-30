class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count{};
        // Visited matrix
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i{}; i < grid.size(); i++) {
            for (int j{}; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    // BFS
                    queue<vector<int>> q;
                    vis[i][j] = true;
                    q.push({i, j});
                    while (!q.empty()) {
                        vector<int> indices = q.front();
                        vis[indices[0]][indices[1]] = true;
                        q.pop();
                        // Adjacents
                        vector<int> left = {indices[0], indices[1] - 1};
                        vector<int> right = {indices[0], indices[1] + 1};
                        vector<int> up = {indices[0] - 1, indices[1]};
                        vector<int> down = {indices[0] + 1, indices[1]};
                        vector<vector<int>> adj = {left, right, up, down};
                        for (vector<int> a : adj) {
                            if (a[0] < 0 || a[0] > grid.size() - 1 || a[1] < 0 || a[1] > grid[0
                                ].size() - 1) continue;
                            if (grid[a[0]][a[1]] == '1' && !vis[a[0]][a[1]]) {
                                q.push(a);
                                vis[a[0]][a[1]] = true;
                            }
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};
