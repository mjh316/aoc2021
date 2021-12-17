#include "bits/stdc++.h"
using namespace std;

int fromx, tox;
int fromy, toy;

bool inside(int x, int y) {
    if (fromy >= 0 && toy >= 0)
        return (x >= fromx) && (x <= tox) && (y >= fromy) && (y <= toy);
    if (fromy < 0 && toy < 0) {
        return (x >= fromx) && (x <= tox) && (y <= fromy) && (y >= toy);
    }
}

int main() {
    freopen("Day17.in", "r", stdin);
    ofstream fout("Day17.out");
    cin >> fromx >> tox;
    cin >> fromy >> toy;
    if (fromy < 0 && toy < 0) swap(fromy, toy);
    int ans = 0;
    for (int i = 0; i <= 500; ++i) {
        for (int j = -500; j <= 500; ++j) {
            int cx = 0, cy = 0;
            int xv = i, yv = j;
            int mx = -1e9;
            while (!(cx > tox) && !(cy < toy) && !inside(cx, cy)) {
                if (i == 6 && j == 0) {
                    //cout << cx << ' ' << cy << '\n';
                }
                mx = max(mx, cy);
                cx += xv;
                cy += yv;
                if (xv > 0) --xv;
                else if (xv < 0) ++xv;
                yv--;
                //cout << cx << ' ' << cy << endl;
            }
            if (i == 6 && j == 0) {
                //cout << cx << ' ' << cy << '\n';
            }
            if (inside(cx, cy)) {
                //fout << i << ' ' << j << '\n';
                ++ans;
            }
        }
    }
    fout.close();
    cout << ans << '\n';
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * CHECK IF DEBUGGING OUTPUT BLOCKS ANSWER
*/
