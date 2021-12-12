#include "bits/stdc++.h"
using namespace std;

int ans = 0, startnode, endnode;
unordered_map<string, int> mp;
vector<int> graph[12];
bool small[12];

inline void dfs(int node, array<int, 12> vis, bool twice) {
    if (small[node] && vis[node] == 2) return;
    if ((node == startnode || node == endnode) && vis[node] >= 1) return;
    if (twice && small[node] && vis[node] >= 1) return;

    vis[node]++;

    if (vis[node] == 2 && small[node]) twice = true;

    if (node == endnode) {
        ++ans;
        return;
    }

    for (const auto &neighbor: graph[node]) {
        if (small[neighbor] && vis[neighbor] == 1) {
            if (twice) continue;
            dfs(neighbor, vis, true);
        }
        dfs(neighbor, vis, twice);
    }
}

int main() {
    freopen("Day12.in", "r", stdin);
    string s;
    int cur = 0;
    for (int i = 0; i < 24; ++i) {
        cin >> s;
        auto s1 = s.substr(0, s.find('-'));
        auto s2 = s.substr(s.find('-')+1);
        if (!mp.count(s1)) mp[s1] = cur++;
        if (!mp.count(s2)) mp[s2] = cur++;
        if (s1[0] >= 97) {
            small[mp[s1]] = true;
        }
        if (s2[0] >= 97) {
            small[mp[s2]] = true;
        }
        graph[mp[s1]].emplace_back(mp[s2]);
        graph[mp[s2]].emplace_back(mp[s1]);
    }
    startnode = mp["start"];
    endnode = mp["end"];
    dfs(startnode, array<int, 12>(), false);
    cout << ans << '\n';

    return 0;
}
