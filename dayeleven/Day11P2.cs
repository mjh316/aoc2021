using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class Day11 {
    static char[][] lines;
    static int flashes = 0;
    static int curflashes = 0;
    static bool[,] vis = new bool[10, 10];
    static int[] rowv = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int[] colv = {0, 1, 1, 1, 0, -1, -1, -1};
    static bool bad(int row, int col) {return row < 0 || col < 0 || row >= lines.Length || col >= lines.Length;}
    static void dfs(int row, int col) {
        if (vis[row, col]) return;
        vis[row, col] = true;
        ++flashes;
        ++curflashes;
        if (lines[row][col] == '9') {
            lines[row][col] = '0';
        } else {
            int x = lines[row][col];
            lines[row][col] = (char)(x+1);
            return;
        }
        for (int i = 0; i < rowv.Length; ++i) {
            int rr = row + rowv[i];
            int cc = col + colv[i];
            if (bad(rr, cc)) continue;
            if (lines[rr][cc] == '9') {
                dfs(rr, cc);
            } else {
                lines[rr][cc] = (char)(lines[rr][cc]+1);
                if (vis[rr, cc]) {

                } else {

                }
            }
        }
    }
    static void Main(string[] args) {
        lines = File.ReadAllLines("Day11.in").Select((string x) => x.ToCharArray()).ToArray();
        int steps = 0;
        while (steps >= 0) {
            curflashes = 0;
            bool[,] need = new bool[10, 10];
            vis = new bool[10, 10];
            for (int i = 0; i < lines.Length; ++i) {
                for (int j = 0; j < lines[i].Length; ++j) {
                    if (lines[i][j] == '9') {
                        need[i,j] = true;
                    } else lines[i][j] = (char)(lines[i][j]+1);
                }
            }
            /*Console.WriteLine();
            for (int i = 0; i < lines.Length; ++i) {
                Console.WriteLine(new string(lines[i]));
            }
            Console.WriteLine();*/
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    if (need[i, j]) {
                        dfs(i, j);
                    }
                }
            }
            /*
            for (int i = 0; i < lines.Length; ++i) {
                Console.WriteLine(new string(lines[i]));
            }*/
            for (int i = 0; i < lines.Length; ++i) {
                for (int j = 0; j < lines.Length; ++j) {
                    if (vis[i, j]) lines[i][j] = '0';
                }
            }
            Console.WriteLine();
            for (int i = 0; i < lines.Length; ++i) {
                Console.WriteLine(new string(lines[i]));
            }
            steps += 1;
            if (curflashes == lines.Length * lines.Length) {
                Console.WriteLine("steps: " + steps);
                return;
            }
        }
        Console.WriteLine(flashes);
    }
}
