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



int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n ;
    cin >> n;
    vector<int> v(n);

    
    for(int i = 0; i < n; ++i){
        cin >> v[i];

    }
    int mn = v[0];
    int mx = v[0];

    int ans =0;
    for(int i = 0; i < n; ++i){
        if(v[i] < mn || v[i] > mx){
            ans++;
            if(v[i] < mn) mn = v[i];
            if(v[i] > mx) mx = v[i];
        }
    }

    cout << ans << "\n";

    return 0;
}