#include<bits/stdc++.h>
using namespace std;
 
 
int main() {
   
    int n;
    cin >> n;
    int ones = 0;
    int twos = 0;
 
    for(int i =0; i<n; i++){
      int x ;
      cin >> x;
      if(x==1) ones++;
      else twos++;
    }
 
    if(ones == 0){
      while(twos--){
        cout << 2 << " ";
      }
    }
    else if(twos == 0){
      while(ones--){
        cout << 1 << " ";
      }
    }
    else{
      cout << 2 << " " << 1 << " ";
      ones --;
      twos--;
       while(twos--){
        cout << 2 << " ";
      }
 
      while(ones--){
        cout << 1 << " ";
      }
      
    }
    return 0;
}