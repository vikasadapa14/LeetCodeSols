#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // Give every litter cell a bit number
        vector<vector<int>> id(m, vector<int>(n, -1));

        int litterCount = 0;
        int sr = -1, sc = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        // All litter already collected
        if (litterCount == 0)
            return 0;

        int fullMask = (1 << litterCount) - 1;

        /*
            visited[r][c][e][mask]

            We use a 4D vector:
            position + remaining energy + collected litter
        */

        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        // Queue: row, col, remaining energy, mask
        queue<array<int, 4>> q;

        visited[sr][sc][energy][0] = true;
        q.push({sr, sc, energy, 0});

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int sz = q.size();

            // Process one BFS level
            while (sz--) {

                auto [r, c, e, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == fullMask)
                    return moves;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    // Cannot enter obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Every movement costs 1 energy
                    if (e == 0)
                        continue;

                    int ne = e - 1;

                    // Collect litter if this cell has one
                    int newMask = mask;

                    if (classroom[nr][nc] == 'L') {
                        newMask |= (1 << id[nr][nc]);
                    }

                    // Reset energy on R
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    if (!visited[nr][nc][ne][newMask]) {

                        visited[nr][nc][ne][newMask] = true;

                        q.push({
                            nr,
                            nc,
                            ne,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};