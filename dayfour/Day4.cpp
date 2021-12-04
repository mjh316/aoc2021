#include "bits/stdc++.h"
using namespace std;

struct grid {
    int a[5][5] = {0};
    bool v[5][5] = {0};
    int id;
};

vector<int> order;
vector<grid> grids;

bool has_won(const grid &g) {
    for (int i = 0; i < 5; ++i) {
        if (g.v[i][0] && g.v[i][1] && g.v[i][2] && g.v[i][3] && g.v[i][4]) return true;
    }
    for (int j = 0; j < 5; ++j) {
        if (g.v[0][j] && g.v[1][j] && g.v[2][j] && g.v[3][j] && g.v[4][j]) return true;
    }
    return false;
}

void mark_board(grid &g, int x) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (g.a[i][j] == x) g.v[i][j] = 1;
        }
    }
}

bool done[100];

int main() {
    freopen("Day4.in", "r", stdin);
    for (int i = 0; i < 100; ++i) {
        int x;
        cin >> x;
        order.push_back(x);
    }

    int x;
    int cnt = 0;
    while (cin >> x) {
        grid g;
        g.a[0][0] = x;
        for (int i = 1; i < 5; ++i) cin >> g.a[0][i];
        for (int i = 1; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                cin >> g.a[i][j];
            }
        }
        g.id = cnt++;
        grids.emplace_back(g);
    }

    for (int i = 0; i < 100; ++i) {
        for (grid &g: grids) {
            mark_board(g, order[i]);
            if (has_won(g) && !done[g.id]) {
                done[g.id] = 1;
                int s = 0;
                for (int i = 0; i < 5; ++i) {
                    for (int j = 0; j < 5; ++j) {
                        if (!g.v[i][j]) s += g.a[i][j];
                    }
                }
                cout << order[i]*s << '\n';
            }
        }
    }

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * CHECK IF DEBUGGING OUTPUT BLOCKS ANSWER
*/

