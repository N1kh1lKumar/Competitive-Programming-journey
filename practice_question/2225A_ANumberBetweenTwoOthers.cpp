/*
Name = Nikihl
github =https://github.com/N1kh1lKumar
linked in = https://www.linkedin.com/in/n1kh1lkumar/
leetcode = https://leetcode.com/u/N1kh1lKumar/
codolio =  https://codolio.com/profile/N1kh1lKumar
codeforces = https://codeforces.com/profile/nikhilkumaraf309
Unstop = https://unstop.com/u/nikhilps68134

Contact Email = nikhilkumaraf309@gmail.com 
*/

// some useful alias 
using ll = long long;
using dl =  long double;



#include<bits/stdc++.h>
using namespace std;

void solve(){
    ll x, y;
    cin >> x>> y;

    ll n = y/x;
    ll z = x*(n-1);

    if(z > x   && y%z !=0){
        cout << "YES\n";
    }
    else{
        cout <<"NO\n";
    }

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