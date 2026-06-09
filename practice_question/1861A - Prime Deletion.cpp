#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
void solve(string n){
    for(int i =0; i< n.size(); i++){
      if(n[i] == '1') { 
        cout << 13 << endl;
        return;
      }
      
      if(n[i] == '3') {
       cout << 31 << endl;
       return;
      }
    }
}
 
 
int main() {
   
    int t;
    cin >> t;
    while(t--){
        string n;
        cin >> n;
 
       solve(n);
    }
 
 
    return 0;
}