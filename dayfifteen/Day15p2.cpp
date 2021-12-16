#include "bits/stdc++.h"
using namespace std;

struct node {
    int w, r, c;
    const bool operator<(const node &n) const {
        return w < n.w;
    }
};

struct grid {
    vector<vector<int>> v;
    int size() const {return v.size();}
    auto operator[](int idx) const {return v[idx];}
    grid (const grid &o) {
        v = vector<vector<int>>(o.size(), vector<int>(o[0].size()));
        for (int i = 0; i < o.size(); ++i) {
            for (int j = 0; j < o[i].size(); ++j) {
                if (o[i][j] == 9) v[i][j] = 1;
                else v[i][j] = o[i][j]+1;
            }
        }
    }
    grid () {}
};

constexpr int gn = 5;
constexpr int n = 100;
constexpr int m = 100;
constexpr int INF = 1e9;
grid grids[gn][gn];
int cost[n*5][m*5];
int best[n*5][m*5];
constexpr int rowv[] = {-1, 0, 1, 0};
constexpr int colv[] = {0, 1, 0, -1};

bool out_of_bounds(int row, int col) {
    return row < 0 || col < 0 || row >= (n*5) || col >= (m*5);
}

void dijkstra(int srow, int scol) {
    priority_queue<node> pq;
    pq.push({0, srow, scol});
    while (pq.size()) {
        auto [weight, row, col] = pq.top();
        pq.pop();
        weight = -weight;
        assert (weight >= 0);
        if (weight >= best[row][col]) continue;
        // cout << row << ' ' << col << ' ' << best[row][col] << ' ' << weight << '\n';
        best[row][col] = weight;
        for (int i = 0; i < 4; ++i) {
            int rr = row + rowv[i];
            int cc = col + colv[i];
            if (out_of_bounds(rr, cc)) continue;
            if (weight + cost[rr][cc] < best[rr][cc]) {
                pq.push({-(weight + cost[rr][cc]), rr, cc});
            }
        }
    }
}

int main() {
    freopen("Day15.in", "r", stdin);
    // freopen("Day15.out", "w", stdout);
    grids[0][0].v = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n*5; ++i) for (int j = 0; j < m*5; ++j) best[i][j] = INF;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        // cout << s << '\n';
        for (int j = 0; j < m; ++j) {
            grids[0][0].v[i][j] = (int)(s[j] - '0');
            // cout << grids[0][0][i][j] << ' ';
        }
        // cout << '\n';
    }
    for (int i = 1; i < gn; ++i) {
        grids[0][i] = grid(grids[0][i-1]);
        grids[i][0] = grid(grids[i-1][0]);
    }
    for (int i = 1; i < gn; ++i) {
        for (int j = 1; j < gn; ++j) {
            grids[i][j] = grid(grids[i-1][j]);
        }
    }
    for (int i = 0; i < gn; ++i) {
        for (int j = 0; j < gn; ++j) {
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < m; ++l) {
                    cost[k + n*i][l + m*j] = grids[i][j][k][l];
                }
            }
        }
    }
    for (int i = 0; i < n*5; ++i) {
        for (int j = 0; j < m*5; ++j) {
            //cout << cost[i][j];
        }
        //cout << '\n';
    }
    dijkstra(0, 0);
    cout << best[n*5-1][m*5-1] << '\n';
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * CHECK IF DEBUGGING OUTPUT BLOCKS ANSWER
*/

