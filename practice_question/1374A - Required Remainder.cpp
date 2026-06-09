#include<bits/stdc++.h>
using namespace std;



void solve(){
      int x, y, n;
      cin >>x>>y>> n;

      int k = (n/x)*x +y;

      if(k<=n){
        cout << k << endl;
      }
      else{
        cout << k-x << endl;
      }
  }


int main(){
      int t;
      cin >> t;
      
      while(t--){
            solve();
      }
      
      return 0;
}