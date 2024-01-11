#include <iostream>
#include <vector>

using namespace std;

bool canFormNetwork(int n, const vector<int>& socialThresholds) {
    long long sum = 0;
    for (int threshold : socialThresholds) {
        sum += threshold;
    }
    return sum >= 2LL * n - 2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> socialThresholds(n);
        for (int i = 0; i < n; ++i) {
            cin >> socialThresholds[i];
        }

        cout << (canFormNetwork(n, socialThresholds) ? "Yes" : "No") << endl;
    }
    return 0;
}