#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<long long> manuls(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> manuls[i];
    }

    unordered_map<int, vector<int>> friends;
    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        friends[v].push_back(u);
        friends[u].push_back(v);
    }

    for (int i = 0; i < q; ++i) {
        char type;
        cin >> type;
        if (type == '?') {
            int v;
            cin >> v;
            cout << manuls[v] << endl;
        } else if (type == '+') {
            int v, x;
            cin >> v >> x;
            for (int friend_id : friends[v]) {
                manuls[friend_id] += x;
            }
        }
    }

    return 0;
}