#include<bits/stdc++.h>
using namespace std;

int nCr(int n, int r){
    if(r > n )  return 0;
    if(r == n || r == 0) return 1;

    return nCr(n-1, r-1) + nCr(n-1, r);
}

void solve(){
      int n;
      cin >> n;

      for(int i =0; i<n; i++){
        int x;
        cin >> x;
      }

      cout << nCr(10-n, 2) *  6 << endl; 
  }


int main(){
      int t;
      cin >> t;
      
      while(t--){
            solve();
      }
      
      return 0;
}