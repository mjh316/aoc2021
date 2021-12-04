using System;
using System.IO;

class Day2 {
    static void Main(string[] args) {
        partone();
        parttwo();
    }
    static void partone() {
        int x = 0;
        int depth = 0;
        foreach (string line in File.ReadAllLines("Day2.in")) {
            string[] tmp = line.Split(" ");
            if (tmp[0] == "forward") {
                x += Convert.ToInt32(tmp[1]);
            } else if (tmp[0] == "down") {
                depth += Convert.ToInt32(tmp[1]);
            } else {
                depth -= Convert.ToInt32(tmp[1]);
            }
        }
        Console.WriteLine(x*depth);
    }
    static void parttwo() {
        int aim = 0;
        int a = 0;
        int dep = 0;
        foreach (string line in File.ReadAllLines("Day2.in")) {
            string s = line.Split(" ")[0];
            Int32.TryParse(line.Split(" ")[1], out int x);
            if (s == "forward") {
                a += x;
                dep += aim * x;
            } else if (s == "down") {
                aim += x;
            } else {
                aim -= x;
            }
        }
        Console.WriteLine(a*dep);
    }
}
