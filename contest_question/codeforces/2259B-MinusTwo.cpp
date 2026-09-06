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
 
// some useful alias 
using ll = long long;
using dl =  long double;
 
// Common Data Structure Shortcuts
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
 
 
 
void solve(){
    int n;
    cin >> n;
 
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int odds = 0;
    int even_rem0 = 0;
    int even_rem2 = 0;
 
    for (int x : a) {
        if (x % 2 != 0) {
            odds++;
        } else if (x % 4 == 0) {
            even_rem0++;
        } else {
            even_rem2++;
        }
    }
cout << max({odds, even_rem0, even_rem2}) << "\n";
}
 
 
 
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t; 
    cin >> t;
 
    while(t--)
    {
        solve();
    }
 
    return 0;
}