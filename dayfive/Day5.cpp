#include "bits/stdc++.h"
using namespace std;

void partone();
void parttwo();

int main() {
    partone();
    parttwo();

    return 0;
}

void partone() {
    freopen("Day5.in", "r", stdin);

}

void parttwo() {
    freopen("Day5.in", "r", stdin);
    int grid[1000][1000] = {0};
    int n = 500;
    int l1=-1, l2=-1, l3=-1, l4=-1;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        swap(x1, y1);
        swap(x2, y2);
        cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        if (x1 <= x2) {
            if (y1 <= y2) {
                int y = y1;
                bool s = 0;
                for (int x = x1; x <= x2; ++x) {
                    grid[x][y]++;
                    if (y == y2) s = 1;
                    y = min(y2, y + 1);
                }
                if (!s) {
                    while (y <= y2) grid[x2][y++]++;
                }
            } else {
                int x = x1;
                bool s = 0;
                for (int y = y1; y >= y2; --y) {
                    grid[x][y]++;
                    if (x == x2) s = 1;
                    x = min(x2, x + 1);
                }
                if (!s) {
                    while (x >= x2) grid[x--][y2]++;
                }
            }
        } else {
            // x1 > x2
            if (y1 <= y2) {
                int x = x1;
                bool s = 0;
                for (int y = y1; y <= y2; ++y) {
                    grid[x][y]++;
                    if (x == x2) s = 1;
                    x = max(x2, x - 1);
                }
                if (!s) {
                    while (x >= x2) grid[x--][y2]++;
                }
            } else {
                // x1 > x2
                // y1 > y2
                int x = x1;
                bool s = 0;
                for (int y = y1; y >= y2; --y) {
                    grid[x][y]++;
                    if (x == x2) s = 1;
                    x = max(x2, x - 1);
                }
                if (!s) {
                    while (x >= x2) grid[x--][y2]++;
                }
            }
        }
    }
    int ans = 0;
    int m = 1000;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] >= 2) ++ans;
            //if (grid[i][j] >= 2) cout << grid[i][j] << ' ';
        }
    }
    cout << ans << '\n';
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * CHECK IF DEBUGGING OUTPUT BLOCKS ANSWER
*/

