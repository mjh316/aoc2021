#include "bits/stdc++.h"
using namespace std;
void partone(), parttwo();

int main() {
    partone();
    parttwo();
    return 0;
}

void partone() {
    ifstream fin = ifstream("Day2.in");
    ofstream fout = ofstream("Day2.out");
    int curdepth = 0;
    int curx = 0;
    string s;
    int x;
    while (fin >> s) {
        fin >> x;
        if (s == "forward") {
            curx += x;
        } else if (s == "down") {
            curdepth += x;
        } else {
            curdepth -= x;
        }
    }

    cout << curdepth * curx << '\n';

    fin.close();
    fout.close();
}

void parttwo() {
    ifstream fin = ifstream("Day2.in");
    ofstream fout = ofstream("Day2.out");
    int curdepth = 0;
    int curx = 0;
    int aim = 0;
    string s;
    int x;
    while (fin >> s) {
        fin >> x;
        if (s == "forward") {
            curx += x;
            curdepth += aim * x;
        } else if (s == "down") {
            aim += x;
        } else {
            aim -= x;
        }
    }


    cout << curdepth*curx << '\n';
    fin.close();
    fout.close();
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * CHECK IF DEBUGGING OUTPUT BLOCKS ANSWER
*/

