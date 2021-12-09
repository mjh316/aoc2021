using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

public class Day9 {
    static void Main(string[] args) {
        string[] lines = File.ReadAllLines("Day9.in");
        int[] rowv = new int[]{-1, 0, 1, 0};
        int[] colv = new int[]{0, 1, 0, -1};
        int ans = 0;
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                bool r = true;
                for (int k = 0; k < 4; ++k) {
                    int rr = i + rowv[k];
                    int cc = j + colv[k];
                    if (rr < 0 || cc < 0 || rr >= 100 || cc >= 100) continue;
                    if (lines[rr][cc] <= lines[i][j]) r = false;
                }
                if (r) {
                    ans += (lines[i][j] - '0') + 1;
                }
            }
        }
        Console.WriteLine(ans);
    }
}
