/*
Name = Nikihl
github =https://github.com/N1kh1lKumar
linked in = https://www.linkedin.com/in/n1kh1lkumar/
leetcode = https://leetcode.com/u/N1kh1lKumar/
codolio =  https://codolio.com/profile/N1kh1lKumar
codeforces = https://codeforces.com/profile/nikhilkumaraf309
Contact Email = nikhilkumaraf309@gmail.com 
*/

#include<bits/stdc++.h>
using namespace std;

// some useful alias 
using ll = long long;
using dl =  long double;

// Common Data Structure Shortcuts
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

#define pb push_back

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    // Since 1 <= A_i <= N, we can use a fixed-size frequency array
    vector<int> freq(N + 1, 0); 
    
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    
    int max_freq = 0;
    for (int i = 1; i <= N; i++) {
        max_freq = max(max_freq, freq[i]);
    }
    
    int max_freq_count = 0;
    for (int i = 1; i <= N; i++) {
        if (freq[i] == max_freq) {
            max_freq_count++;
        }
    }
    
    
    if (max_freq_count == 1) {
        cout << "YES\n";
    } else {
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
