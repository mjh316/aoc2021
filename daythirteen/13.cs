using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

using pii = System.Collections.Generic.KeyValuePair<int, int>;


public class Day13 {

  static int max_x = (int)1e9;
  static int max_y = (int)1e9;

  static HashSet<pii> flip_x(int x) {
    HashSet<pii> ret = new HashSet<pii>();
    foreach (pii pair in st) {
      if (pair.Key > max_x) {
        throw new IndexOutOfRangeException("x");
      }
      if (pair.Key <= x) {
        ret.Add(pair);
        continue;
      }
      int new_x = x - (pair.Key - x - 1) - 1;
      if (new_x < 0) continue;
      ret.Add(new pii(new_x, pair.Value));
    }
    max_x = Math.Min(max_x, x);
    return ret;
  }

  static HashSet<pii> flip_y(int y) {
    HashSet<pii> ret = new HashSet<pii>();
    foreach (pii pair in st) {
      if (pair.Value > max_y) {
        throw new IndexOutOfRangeException("y");
      }
      if (pair.Value <= y) {
        ret.Add(pair);
        continue;
      }
      int new_y = y - (pair.Value - y - 1) - 1;
      if (new_y < 0) continue;
      ret.Add(new pii(pair.Key, new_y));
    }
    max_y = Math.Min(max_y, y);
    return ret;
  }

  

  static HashSet<pii> st = new HashSet<pii>();
  public static void Main(string[] args) {
    string[] lines = File.ReadAllLines("13.in");
    int i;
    for (i = 0; i < lines.Length; ++i) {
      if (String.IsNullOrEmpty(lines[i])) {
        ++i;
        break;
      }
      int[] tmp = lines[i].Split(',').Select(int.Parse).ToArray();
      st.Add(new pii(tmp[0], tmp[1]));
    }
    for (; i < lines.Length; ++i) {
      string[] line = lines[i].Split("fold along ")[1].Split("=");
      if (line[0] == "x") {
        st = flip_x(int.Parse(line[1]));
        // Console.WriteLine("x split");
      } else {
        st = flip_y(int.Parse(line[1]));
        // Console.WriteLine("y split");
      }
      Console.WriteLine(st.Count);
    }
  }
}
