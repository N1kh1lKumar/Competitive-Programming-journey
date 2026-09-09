/*
Name = Nikhil
github =https://github.com/N1kh1lKumar
linked in = https://www.linkedin.com/in/n1kh1lkumar/
leetcode = https://leetcode.com/u/N1kh1lKumar/
codolio =  https://codolio.com/profile/N1kh1lKumar
codeforces = https://codeforces.com/profile/nikhilkumaraf309
Contact Email = nikhilkumaraf309@gmail.com 
*/

#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    map<int, int> frequencies;
    
    int max_freq = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        frequencies[a]++;
        if (frequencies[a] > max_freq) {
            max_freq = frequencies[a];
        }
    }
    
   
    int ans = (max_freq + 1) / 2;
    cout << ans << "\n";
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
