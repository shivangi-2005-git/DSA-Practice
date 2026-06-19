 class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int startX, startY;
        int totalKeys = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    startX = i;
                    startY = j;
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    totalKeys = max(totalKeys,
                                    grid[i][j] - 'a' + 1);
                }
            }
        }

        int finalMask = (1 << totalKeys) - 1;

        queue<vector<int>> q;

        vector<vector<vector<bool>>> visited(
            m,
            vector<vector<bool>>(n,
            vector<bool>(1 << totalKeys, false))
        );

        q.push({startX, startY, 0});
        visited[startX][startY][0] = true;

        int steps = 0;

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto curr = q.front();
                q.pop();

                int x = curr[0];
                int y = curr[1];
                int mask = curr[2];

                if (mask == finalMask)
                    return steps;

                for (int k = 0; k < 4; k++) {

                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || ny < 0 ||
                        nx >= m || ny >= n)
                        continue;

                    char ch = grid[nx][ny];

                    if (ch == '#')
                        continue;

                    int newMask = mask;

                    // Key
                    if (ch >= 'a' && ch <= 'f') {
                        newMask |= (1 << (ch - 'a'));
                    }

                    // Lock
                    if (ch >= 'A' && ch <= 'F') {
                        if (!(mask & (1 << (ch - 'A'))))
                            continue;
                    }

                    if (!visited[nx][ny][newMask]) {
                        visited[nx][ny][newMask] = true;
                        q.push({nx, ny, newMask});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};