#include "bits/stdc++.h"
using namespace std;

int rowv[] = {-1, 0, 1, 0};
int colv[] = {0, 1, 0, -1};
constexpr int n = 100;
constexpr int m = 100;
constexpr int INF = 1e9;
int best[n][m];
int grid[n][m];
bool vis[n][m];

pair<int, int> closest_node() {
    pair<int, int> ret = {-1, -1};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j] && (ret.first == -1 || best[i][j] < best[ret.first][ret.second]))
                ret = {i, j};
        }
    }
    return ret;
}

bool bad_coords(int row, int col) {
    return row < 0 || col < 0 || row >= n || col >= m || vis[row][col];
}

void dijkstra(int srow, int scol) {
    best[srow][scol] = 0;
    for (int i = 0; i < n*m; ++i) {
        auto [row, col] = closest_node();
        if (vis[row][col]) continue;
        vis[row][col] = true;
        for (int j = 0; j < 4; ++j) {
            int rr = row + rowv[j];
            int cc = col + colv[j];
            if (bad_coords(rr, cc)) continue;
            if (best[rr][cc] <= best[row][col] + grid[rr][cc]) continue;
            best[rr][cc] = best[row][col] + grid[rr][cc];
        }
    }
}

int main() {
    freopen("Day15.in", "r", stdin);
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j =0 ; j < m; ++j) {
            best[i][j] = INF;
            grid[i][j] = s[j] - '0';
        }
    }
    dijkstra(0, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(12) << best[i][j];
        }
        cout << '\n';
    }
    cout << best[n-1][m-1] << '\n';
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * CHECK IF DEBUGGING OUTPUT BLOCKS ANSWER
*/

