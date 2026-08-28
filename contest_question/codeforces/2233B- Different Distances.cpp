#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // Block 1
    for (int i = 1; i <= n; i++)
        cout << i << ' ';

    // Block 2
    for (int i = n; i >= 1; i--)
        cout << i << ' ';

    // Block 3
    cout << n << ' ';
    for (int i = 1; i < n; i++)
        cout << i << ' ';

    // Block 4
    for (int i = n - 1; i >= 1; i--)
        cout << i << ' ';
    cout << n;

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}