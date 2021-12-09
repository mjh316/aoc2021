using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

public class Day9P2 {
    static bool[,] vis = new bool[100, 100];
    static int cur = 0;
    static void dfs(int row, int col) {
        if (vis[row, col]) return;
        vis[row, col] = true;
        cur += 1;
        for (int k = 0; k < 4; ++k) {
               int rr = row + rowv[k];
               int cc = col + colv[k];
               if (rr < 0 || cc < 0 || rr >= 100 || cc >= 100) continue;
               if (lines[rr][cc] != '9' && lines[rr][cc] >= lines[row][col]) {
                   dfs(rr, cc);
               }
        }
    }
        static int[] colv = new int[]{0, 1, 0, -1};
        static int[] rowv = new int[]{-1, 0, 1, 0};
        static string[] lines;
    static void Main(string[] args) {
        lines = File.ReadAllLines("Day9.in");
        int ans = 0;
        List<int> l = new List<int>();
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                if (vis[i, j]) continue;
                bool r = true;
                for (int k = 0; k < 4; ++k) {
                    int rr = i + rowv[k];
                    int cc = j + colv[k];
                    if (rr < 0 || cc < 0 || rr >= 100 || cc >= 100) continue;
                    if (lines[rr][cc] <= lines[i][j]) r = false;
                }
                if (r) {
                    cur = 0;
                    dfs(i, j);
                    l.Add(cur);
                }
            }
        }
        l.Sort();
        Console.WriteLine(l[l.Count - 1] + " " + l[l.Count-2] + " " + l[l.Count-3]);
    }
}

