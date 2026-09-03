#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N;
    cin >> N;
    
    if(N%2 == 0){
        cout << N*15 << "\n";
        return ;
    }
    
    cout << (N-1)*15 + 20 << "\n";
    
    
}

int main() {
	// your code goes here
    int t; 
    cin >> t; 
    
    while(t--){
        solve();
    }
}
