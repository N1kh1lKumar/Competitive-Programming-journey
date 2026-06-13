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
    int n;
    cin >> n;

    vector<int> towers(n);
    for(int i=0; i<n; i++){
        cin >> towers[i];
    }

    int mn = *min_element(towers.begin(), towers.end());
    int mx = *max_element(towers.begin(), towers.end());
  
    cout << mx-mn+1 << "\n";
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