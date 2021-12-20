#include "bits/stdc++.h"
using namespace std;

string s;
constexpr int mxN = 1000, n = 100, offset = 300;
vector<vector<char>> grid(mxN, vector<char>(mxN));

char apply(char c) {
    return c == '.' ? '0' : '1';
}

char gethar(int row, int col) {
    string tmp = "";
    //cout << "tmp: " << tmp << endl;
    tmp += apply(grid[row-1][col-1]);
    tmp += apply(grid[row-1][col]);
    tmp += apply(grid[row-1][col+1]);

    tmp += apply(grid[row][col-1]);
    tmp += apply(grid[row][col]);
    tmp += apply(grid[row][col+1]);

    tmp += apply(grid[row+1][col-1]);
    tmp += apply(grid[row+1][col]);
    tmp += apply(grid[row+1][col+1]);

    //cout << "tmp: " << tmp << endl;
    int idx = stoi(tmp, nullptr, 2);
    //cout << "idx: " << idx << " " << "tmp: " << tmp << '\n';
    //cout << idx << '\n';
    //cout << "s[idx]: " << s[idx] << '\n';
    return s[idx];
}

void apply() {
    char tmp[mxN][mxN] = {0};
    for (int i = 0; i < mxN; ++i) for (int j = 0; j < mxN; ++j) tmp[i][j] = '.';
    for (int i = 10; i < mxN - 10; ++i) {
        for (int j = 10; j < mxN - 10; ++j) {
            tmp[i][j] = gethar(i, j);
            //cout << tmp[i][j] << ' ';
        }
    }
    for (int i = 0; i < mxN; ++i) for (int j = 0; j < mxN; ++j) grid[i][j] = tmp[i][j];
}

void pg() {
    for (int i = 100; i < n+offset+10; ++i) {
        for (int j = 100; j < n+offset+10; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int count() {
    int ret = 0;
    for (int i = 0; i < mxN; ++i) {
        for (int j = 0; j < mxN; ++j) {
            ret += grid[i][j] == '#';
        }
    }
    return ret;
}

int main() {
    for (int i = 0; i < mxN; ++i) for (int j = 0; j < mxN; ++j) grid[i][j] = '.';
    freopen("Day20.in", "r", stdin);
    for (int i = 0; i < 1; ++i) {
        string t;
        cin >> t;
        //cout << t << '\n';
        s += t;
    }
    //cout << s.size() << '\n';
    for (int i = offset; i < n+offset; ++i) {
        for (int j = offset; j < n+offset; ++j) {
            cin >> grid[i][j];
            assert(grid[i][j] == '.' || grid[i][j] == '#');
        }
    }
    /*for (int i = offset; i <= n+offset; ++i) {
        for (int j = offset; j <= n+offset; ++j) {
            cout << grid[i][j];
        }
        cout << '\n';
    }*/
    //cout << 1 << endl;
    //pg();
    //cout << '\n';
    apply();
    //cout << 2 << endl;
    //pg();
    //cout << gethar(24, 22) << '\n';
    //cout << gethar(offset, offset+1);
    apply();
    //cout << 3 << endl;
    freopen("test.j", "w", stdout);
    pg();
    //cout << count() << '\n';
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * CHECK IF DEBUGGING OUTPUT BLOCKS ANSWER
*/

