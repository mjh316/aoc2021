using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class Day10 {

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
        Dictionary<char, char> rev = new Dictionary<char, char>();
        rev.Add('{', '}');
        rev.Add('[', ']');
        rev.Add('<', '>');
        rev.Add('(', ')');
        List<long> scores = new List<long>();
        foreach (string line in lines) {
            Stack<char> stk = new Stack<char>();
            bool incomp = true;
            for (int i = 0; i < line.Length; ++i) {
                if (line[i] == '(' || line[i] == '[' || line[i] == '<' || line[i] == '{') {
                    stk.Push(line[i]);
                } else {
                    if (stk.Count > 0 && stk.Peek() == mp[line[i]]) {
                        stk.Pop();
                    } else {
                        incomp = false;
                        break;
                    }
                }
            }
            if (stk.Count == 0 || !incomp) continue;
                long cur = 0;
            while (stk.Count > 0) {
                char c = stk.Pop();
                if (c == '(') cur = cur*5 + 1;
                if (c == '[') cur = cur*5 + 2;
                if (c == '{') cur = cur*5 + 3;
                if (c == '<') cur = cur*5 + 4;
            }
            scores.Add(cur);
        }
        scores.Sort();
        Console.WriteLine(scores[scores.Count/2]);
    }
}
