#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("Day7.in", "r", stdin);
    int n = 1000;
    vector<int> v;
    int mi = 1e9, mx=  -1e9;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.emplace_back(x);
        mi = min(mi, x);
        mx = max(mx, x);
    }
    int ans = 1e9;
    for (int i = mi; i <= mx; ++i) {
        int cur = 0;
        for (int &e: v) {
            // uncomment below line for p1
            // int tmp = abs(e-i);
            // comment out below line for p1 (is p2 sol)
            int tmp = (abs(e-i))*(abs(e-i)+1)/2;
            cur += tmp;
        }
        ans=min(ans, cur);
    }
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

