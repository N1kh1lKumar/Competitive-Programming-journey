
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    map<long long, int> counts;
    long long S = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        S += a[i];
        counts[a[i]]++;
    }
    
    long long max_x = 0;
    int max_k = 0;
    for (auto const& [x, k] : counts) {
        if (k > max_k) {
            max_k = k;
            max_x = x;
        }
    }
    
    if (2 * max_k - n - 2 > 0) {
        long long wasted_cards = 2 * max_k - n - 2;
        cout << S - wasted_cards * max_x << "\n";
    } else {
        cout << S << "\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
 