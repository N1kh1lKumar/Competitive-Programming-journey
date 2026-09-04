#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int k;
        cin >> k;
 
        int cnt = 0;
        bool possible = false;
 
        for (int i = 0; i < k; i++) {
            long long c;
            cin >> c;
 
            if (c >= 3)
                possible = true;
 
            if (c >= 2)
                cnt++;
        }
 
        if (possible || cnt >= 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
 
    return 0;
}