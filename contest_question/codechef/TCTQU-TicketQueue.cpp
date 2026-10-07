#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    long long total_time = 0;
    long long target_time = t[k];

    for (int i = 0; i < n; ++i) {
        if (i <= k) {
            // People before or at index K
            total_time += min(t[i], target_time);
        } else {
            // People after index K
            total_time += min(t[i], target_time - 1);
        }
    }

    cout << total_time << "\n";

    return 0;
}
