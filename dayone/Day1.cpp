#include "bits/stdc++.h"
using namespace std;

void partone(bool console=false), parttwo(bool console=false);

int main() {
    partone(1);
    parttwo(1);
    return 0;
}

void partone(bool console) {
    ifstream fin = ifstream("Day1.in");
    ofstream fout = ofstream("Day1.out");
    string s;
    vector<int> v;
    while (fin >> s) {
        v.emplace_back(stoi(s));
    }
    int ans = 0;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] >= v[i-1]) ++ans;
    }
    (console?cout:fout)<< ans << '\n';
    fout.close();
}


void parttwo(bool console) {
    ifstream fin = ifstream("Day1.in");
    ofstream fout = ofstream("Day1.out");
    string s;
    vector<int> v;
    while (fin >> s) {
        v.emplace_back(stoi(s));
    }
    int ans = 0;
    long long sum = 0;
    sum += v[0] + v[1] + v[2];
    for (int i = 3; i < v.size(); ++i) {
        long long newsum = sum - v[i-3] + v[i];
        if (newsum > sum) ++ans;
        sum = newsum;
    }
    (console?cout:fout) << ans << '\n';
    fout.close();
}


