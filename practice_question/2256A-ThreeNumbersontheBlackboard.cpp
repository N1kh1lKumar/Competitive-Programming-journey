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
 
void solve(){
    int a, b, c;
    cin >> a >> b >> c;
 
    if(a+b < c){
        c = a+b;
    }
    else if(a+c < b){
        b = a+c;
    }
    else if(b+c < a){
        a = b+c;
    }
 
    cout << max({a, b, c}) - min({a, b, c}) << "\n";
 
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