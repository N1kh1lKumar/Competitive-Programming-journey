#include<bits/stdc++.h>
using namespace std;
 
 
void solve(){
      int n;
      cin >> n;
      int a[n];
      int b[n];
 
      int a_max= INT_MIN;
      long long  sum_b = 0;
 
      for(int i=0; i<n; i++){
            int x ;
            cin >> x;
            a[i] = x;
      }
 
       for(int i=0; i<n; i++){
         int x;
         cin >> x;
         b[i] = x;
      }
      
     for(int i=0; i<n; i++){
      int temp1 = min(a[i], b[i]);
      int temp2 = max(a[i], b[i]);
      a_max = max(temp1, a_max);
      sum_b += (long long)temp2;
     }
 
     cout << (a_max + sum_b) << endl;
 
}
 
 
int main(){
      int t;
      cin >> t;
      
      while(t--){
            solve();
      }
      
      return 0;
}