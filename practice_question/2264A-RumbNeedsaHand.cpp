#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    bool already_sorted = true;
    
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (p[i] != i + 1) {
            already_sorted = false;
        }
    }
    
    // Case 1: If already sorted, a dummy operation on 1 element preserves it
    if (already_sorted) {
        cout << "YES\n";
        return;
    }
    
    // Gather indices of all misplaced elements
    vector<int> misplaced_indices;
    for (int i = 0; i < n; ++i) {
        if (p[i] != i + 1) {
            misplaced_indices.push_back(i);
        }
    }
    
    // Simulate reversing the elements at the misplaced positions
    int m = misplaced_indices.size();
    for (int j = 0; j < m / 2; ++j) {
        swap(p[misplaced_indices[j]], p[misplaced_indices[m - 1 - j]]);
    }
    
    // Verify if the array is now completely sorted
    bool successfully_sorted = true;
    for (int i = 0; i < n; ++i) {
        if (p[i] != i + 1) {
            successfully_sorted = false;
            break;
        }
    }
    
    if (successfully_sorted) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
