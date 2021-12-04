#include <vector>
#include <string>
#include <iostream>

int oxygen(std::vector<std::string> s) {
    int a[2] = {0};
    int cur = 0;
    while (s.size() > 1) {
        a[0] = a[1] = 0;
        for (auto &st: s) {
            a[st[cur] - '0']++;
        }
        std::vector<std::string> tmp;
        for (auto &st: s) {
            if (a[st[cur] - '0'] == std::max(a[0], a[1])) {
                if (a[0] == a[1] && st[cur] != '1') continue;
                tmp.emplace_back(st);
            }
        }
        s = tmp;
        ++cur;
    }

    return std::stoi(s[0], nullptr, 2);
}

int carbon(std::vector<std::string> s) {
    int a[2] = {0};
    int cur = 0;
    while (s.size() > 1) {
        a[0] = a[1] = 0;
        for (auto &st: s) {
            a[st[cur] - '0']++;
        }
        std::vector<std::string> tmp;
        for (auto &st: s) {
            if (a[st[cur] - '0'] == std::min(a[0], a[1])) {
                if (a[0] == a[1] && st[cur] != '0') continue;
                tmp.emplace_back(st);
            }
        }
        s = tmp;
        ++cur;
    }
    return std::stoi(s[0], nullptr, 2);
}

int main() {
    freopen("Day3.in", "r", stdin);
    std::vector<std::string> s;
    std::string e;
    while (std::cin >> e) s.emplace_back(e);
    int a = oxygen(s);
    int b = carbon(s);
    std::cout << a*b << '\n';
}
