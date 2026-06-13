#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n, q;
    cin >> n>>q;

    vector<int> candy(n);
    for(int i=0; i<n; i++){
        cin >> candy[i];
    }

    sort(candy.begin(), candy.end());
    reverse(candy.begin(), candy.end());

    for(int i=1; i<n; i++){
        candy[i] += candy[i-1];
    }

    while(q--){
        int x;
        cin >> x;

        int lb = lower_bound(candy.begin(), candy.end(),x) - candy.begin();

        if(lb < n){ 
        cout << lb+1 << endl;
        }
        else{
            cout << -1<< endl;
        }
}
}

int main(){

    int t;
    cin >>t;

    while(t--){
        solve();
    }

    return 0;
}