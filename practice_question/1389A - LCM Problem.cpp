#include<bits/stdc++.h>
using namespace std;

void solve(){
      int l, r;
      cin >> l>> r;

      int x = l;
      int y = 2*l;

      if(y > r){
        cout << "-1 -1\n" ;
      }
      else{
        cout << x << " " << y;
        cout << endl;
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