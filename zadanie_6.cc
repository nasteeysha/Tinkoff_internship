#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

const int MAXN = 2e5 + 5;
int n, q;
vector<long long> a, tree, lazy;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}

void push(int v) {
    tree[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    tree[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, long long addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        tree[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}

long long get_max(int v, int tl, int tr, int l, int r, int k, int b) {
    if (l > r)
        return LLONG_MIN;
    if (l == tl && tr == r) {
        return min(tree[v], 1LL * k * tr + b);
    }
    push(v);
    int tm = (tl + tr) / 2;
    return max(
        get_max(v*2, tl, tm, l, min(r, tm), k, b),
        get_max(v*2+1, tm+1, tr, max(l, tm+1), r, k, b)
    );
}

int main() {
    cin >> n >> q;
    a.resize(n + 1);
    tree.resize(4 * n);
    lazy.assign(4 * n, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n);

    for (int i = 0; i < q; ++i) {
        char type;
        int l, r, x, k, b;
        cin >> type;
        if (type == '+') {
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        } else if (type == '?') {
            cin >> l >> r >> k >> b;
            cout << get_max(1, 1, n, l, r, k, b) << endl;
        }
    }
    return 0;
}