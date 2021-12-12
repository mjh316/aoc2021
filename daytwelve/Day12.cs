using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

public class Day12 {
    static long ans = 0;
    static Dictionary<string, List<string>> adj = new Dictionary<string, List<string>>();
    static int n = 12;
    static Dictionary<string, int> mp = new Dictionary<string, int>();


    static void dfs(string node, Dictionary<string, int> vis, bool twice) {
        if (node[0] >= 97 && vis.ContainsKey(node) && vis[node] == 2) return;
        if ((node == "start" || node == "end") && vis.ContainsKey(node)) return;
        if (twice && node[0] >= 97 && vis.ContainsKey(node)) return;

        if (vis.ContainsKey(node)) vis[node]++;
        else vis[node] = 1;

        if (vis[node] == 2 && node[0] >= 97) twice = true;
        if (vis[node] > 2 && node[0] >= 97) {
            Console.WriteLine(node);
            throw new Exception();
        }
        if (node == "end") {
            //foreach (string s in path) Console.Write(s + ',');
            //Console.WriteLine();
            ++ans;
            return;
        }
        foreach (string neighbor in adj[node]) {
            if (neighbor[0] >= 97 && vis.ContainsKey(neighbor) && vis[neighbor] == 1) {
                if (twice) continue;
                else {
                    dfs(neighbor, new Dictionary<string, int>(vis), true);
                }
            }
            dfs(neighbor, new Dictionary<string, int>(vis), twice);
        }
    }

    static void Main(string[] args) {
        string[][] lines = File.ReadAllLines("Day12.in").Select((string x) => x.Split('-')).ToArray();
        int cur = 0;
        foreach (string[] line in lines) {
            if (!mp.ContainsKey(line[0])) {
                mp[line[0]] = cur++;
            }
            if (!mp.ContainsKey(line[1])) {
                mp[line[1]] = cur++;
            }
            if (adj.ContainsKey(line[0])) {
                adj[line[0]].Add(line[1]);
            } else {
                adj[line[0]] = new List<string>();
                adj[line[0]].Add(line[1]);
            }
            if (adj.ContainsKey(line[1])) {
                adj[line[1]].Add(line[0]);
            } else {
                adj[line[1]] = new List<string>();
                adj[line[1]].Add(line[0]);
            }
        }
        dfs("start", new Dictionary<string, int>(), false);
        Console.WriteLine(ans);
    }
}
