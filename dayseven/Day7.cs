using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class Day7 {
    static void Main(string[] args) {
        int[] v = File.ReadAllLines("Day7.in").Select(int.Parse).ToArray();
        int mi = v.Min();
        int mx = v.Max();
        int ans = (int)2e9;
        for (int i = mi; i <= mx; ++i) {
            int cur = 0;
            foreach (int crab in v) {
                cur += (Math.Abs(crab-i))*(Math.Abs(crab-i)+1)/2;
            }
            ans=Math.Min(ans, cur);
        }
        Console.WriteLine(ans);
    }
}
