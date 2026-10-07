#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    char c ; cin >> c;
    string s ;cin >> s;

    int cost = 0;
    int i =0 , j = n-1;
    while(i<j){

        if(s[i] != s[j]){
            if(s[i] != s[j] && s[j] != c && s[i] != c){
                s[i] = c;
                s[j] = c;
                cost++;
            }
            else if(s[i] == c ){
                s[j] = c;
            }
            else{
                s[i] = c;
            }

            cost++;
        }
        i++; j--;

    }

    cout << cost << "\n";
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
