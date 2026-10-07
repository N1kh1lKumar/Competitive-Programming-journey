#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int x = 0, y = 0;

    for (char ch : s) {
        if (ch == 'U') {
            y++;
        }
        else if (ch == 'D') {
            y--;
        }
        else if (ch == 'L') {
            x--;
        }
        else if (ch == 'R') {
            x++;
        }
    }

    if ((x == 0 && abs(y) == 2) || (y == 0 && abs(x) == 2)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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