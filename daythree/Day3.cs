using System;
using System.Text;
using System.IO;

class Day3 {
    static void Main(string[] args) {
        partone();
    }
    static void partone() {
        string[] lines = File.ReadAllLines("Day3.in");
        int[,] cnt = new int[lines[0].Length, 2];
        for (int i = 0; i < lines[0].Length; ++i) {
            foreach (string line in lines) {
                cnt[i, line[i] - '0']++;
            }
        }
        var sb = new StringBuilder();
        var sb1 = new StringBuilder();
        for (int i = 0; i < lines[0].Length; ++i) {
            if (cnt[i, 0] < cnt[i, 1]) {
                sb.Append(1);
                sb1.Append(0);
            } else {
                sb.Append(0);
                sb1.Append(1);
            }
        }
        Console.WriteLine(Convert.ToInt32(sb.ToString(), 2) * Convert.ToInt32(sb1.ToString(), 2));

    }
}
