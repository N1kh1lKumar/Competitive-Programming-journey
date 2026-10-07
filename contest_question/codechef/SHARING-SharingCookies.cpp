/*
Name = Nikhil
github =https://github.com/N1kh1lKumar
linked in = https://www.linkedin.com/in/n1kh1lkumar/
leetcode = https://leetcode.com/u/N1kh1lKumar/
codolio =  https://codolio.com/profile/N1kh1lKumar
codeforces = https://codeforces.com/profile/nikhilkumaraf309
Contact Email = nikhilkumaraf309@gmail.com 
*/

#include<bits/stdc++.h>
using namespace std;


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     int A, B;
    cin >> A >> B;
    
    if((A-B) % 2 == 0){
        cout << (A-B)/2 << "\n";
      
    }
    else{
         cout << "-1\n";
    }
   
   
    return 0;
}