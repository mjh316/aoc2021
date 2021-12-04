using System;
using System.Collections;
using System.IO;
using System.Linq;


class Day1 {
    static void Main(string[] args) {
        partone();
        parttwo();
    }

    static void partone() {
        int last = 0, ans = 0;
        bool first = true;
        foreach (string line in File.ReadAllLines("Day1.in")) {
            int x = Convert.ToInt32(line);
            if (first) {
                first = false;
                last = x;
                continue;
            }
            if (x > last) ++ans;
            last = x;
        }
        Console.WriteLine(ans);
    }

    static void parttwo() {
        int ans = 0;
        int[] tmp = File.ReadAllLines("Day1.in").Select(int.Parse).ToArray();
        int sum = tmp[0] + tmp[1] + tmp[2];
        for (int i = 3; i < tmp.Length; ++i) {
            int x = sum - tmp[i-3] + tmp[i];
            if (x > sum) ++ans;
            sum = x;
        }
        Console.WriteLine(ans);
    }
}
