#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);

    for (int &x : A) {
        cin >> x;
    }

    int windowSize = N - K;

    int windowSum = 0;

    // First window
    for (int i = 0; i < windowSize; i++) {
        windowSum += A[i];
    }

    int ans = windowSum;

    // Slide the window
    for (int i = windowSize; i < N; i++) {
        windowSum += A[i];
        windowSum -= A[i - windowSize];

        ans = max(ans, windowSum);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }
}

