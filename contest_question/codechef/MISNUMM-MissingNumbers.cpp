#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> a(n);
    map<int, int> freq; 

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]--; // Decrement for array A
    }

    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        freq[b[i]]++; // Increment for array B
    }

    set<int> missing_numbers;
    for (auto const& [num, count] : freq) {
        // If count > 0, it means it appeared more times in B than A
        if (count > 0) {
            missing_numbers.insert(num);
        }
    }

    if (missing_numbers.empty()) {
        cout << -1 << "\n";
    } else {
        bool first = true;
        for (int num : missing_numbers) {
            if (!first) cout << " ";
            cout << num;
            first = false;
        }
        cout << "\n";
    }

    return 0;
}
