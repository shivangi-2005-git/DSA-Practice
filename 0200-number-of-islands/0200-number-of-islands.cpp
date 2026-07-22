#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (grid[i][j] == '1') {
                    islands++;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0'; // Mark as visited

                    while (!q.empty()) {
                        pair<int, int> current = q.front();
                        q.pop();

                        int r = current.first;
                        int c = current.second;

                        for (auto dir : directions) {
                            int nr = r + dir.first;
                            int nc = c + dir.second;

                            if (nr >= 0 && nr < rows &&
                                nc >= 0 && nc < cols &&
                                grid[nr][nc] == '1') {

                                grid[nr][nc] = '0';
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};