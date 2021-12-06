#include "bits/stdc++.h"
using namespace std;

struct node {
    int id;
    node *nxt;
    node (int x) {
        id = x;
        nxt = nullptr;
    }
    node () {
        nxt = nullptr;
    }
};

struct llist {
    node* head, *tail;
    llist() {
        head = tail = nullptr;
    }
    void push(int x) {
        if (head == nullptr) {
            head = new node();
            head->id = x;
            tail = head;
        } else {
            node *tmp = new node(x);
            tail->nxt = tmp;
            tail = tmp;
        }
    }
};

int main() {
    freopen("Day6.in", "r", stdin);
    int64_t n = 300;
    llist l = llist();
    int64_t cnt[9] = {0};
    for (int64_t i = 0; i < n; ++i) {
        int64_t x;
        cin >> x;
        cnt[x]++;
    }
    int d = 0;
    while (d != 256) {
        int64_t tmp[9] = {0};
        for (int i = 8; i >= 1; --i) {
            tmp[i-1] += cnt[i];
        }
        tmp[8] += cnt[0];
        tmp[6] += cnt[0];
        for (int i = 8; i >= 0; --i) {
            cnt[i] = tmp[i];
            cout << "i: " << i << " cnt[i]: " << cnt[i] << '\n';
        }
        cout << '\n';
        ++d;
    }
    int64_t sum = 0;
    for (int i = 0; i < 9; ++i) {
        sum += cnt[i];
        cout << i << ' ' << cnt[i] << '\n';
    }
    cout << sum << '\n';


    return 0;
}

/* stuff you should look for
    * int64_t overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * CHECK IF DEBUGGING OUTPUT BLOCKS ANSWER
*/

