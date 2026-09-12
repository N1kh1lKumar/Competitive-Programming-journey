#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    
    vector<int> a(n);
    vector<long long> C(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        C[a[i]]++;
    }
    
    
    vector<long long> suf(m + 2, 0);
    for (int i = m; i >= 1; --i) {
        suf[i] = suf[i + 1] + C[i];
    }
 
    long long ans = 0;
 
    // Case 1: Target length y == x
    for (int x = 1; x <= m; ++x) {
        long long current = C[x];
        if (2 * x <= m) {
            current += C[2 * x];
        }
        if (x + 1 <= m) {
            current += suf[x + 1];
        }
        ans = max(ans, current);
    }
 
    
    vector<int> indices(m);
    for (int i = 0; i < m; ++i) {
        indices[i] = i + 1;
    }
    
    
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return C[i] > C[j];
    });
 
     int limit = min(m, 10);
    for (int i = 0; i < limit; ++i) {
        for (int j = i + 1; j < limit; ++j) {
            int y = indices[i];
            int z = indices[j];
            if (y > z) swap(y, z);
            if (z != 2 * y) {
                ans = max(ans, C[y] + C[z]);
            }
        }
    }
    
    
    for (int i = 1; i <= m; ++i) {
        ans = max(ans, C[i]);
    }
 
    cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
