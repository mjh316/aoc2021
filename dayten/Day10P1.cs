using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class Day10P1 {

    static void Main(string[] args) {
        string[] lines = File.ReadAllLines("Day10.in");
        // int[][] grid = lines.Select((string row) => row.Split(" ").Select(int.Parse).ToArray()).ToArray();
        int ans = 0;
        Dictionary<char, char> mp = new Dictionary<char, char>();
        mp.Add('}', '{');
        mp.Add(']', '[');
        mp.Add('>', '<');
        mp.Add(')', '(');
        Dictionary<char, int> price = new Dictionary<char, int>();
        price.Add(')', 3);
        price.Add(']', 57);
        price.Add('}', 1197);
        price.Add('>', 25137);
        foreach (string line in lines) {
            Stack<char> stk = new Stack<char>();
            for (int i = 0; i < line.Length; ++i) {
                if (line[i] == '(' || line[i] == '[' || line[i] == '<' || line[i] == '{') {
                    stk.Push(line[i]);
                } else {
                    if (stk.Count > 0 && stk.Peek() == mp[line[i]]) {
                        stk.Pop();
                    } else {
                        ans += price[line[i]];
                        break;
                    }
                }
            }
        }
        Console.WriteLine(ans);
    }
}
