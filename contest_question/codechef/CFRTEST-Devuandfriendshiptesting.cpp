#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int ans = 1;
    
    vector<int> a(n);
    for(int i =0; i<n ; i++){
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    for(int i =0; i<n-1; i++){
        if(a[i] != a[i+1]){
            ans++;
        }
    }
    
    cout << ans <<"\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        solve();
    }
    
}
