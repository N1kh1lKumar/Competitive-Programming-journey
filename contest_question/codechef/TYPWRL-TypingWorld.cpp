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

void solve(){
    int n , m;
    cin >> n>> m;
    
    string s , l;
    cin >> s >> l;

    int arr[26] = {0};
    
    for( auto ch : l){
        arr[ch - 'a']++;
    }
    int maxLength = 1, currlength=1 ;
    
    for(int i = 1; i<n; i++){
        if( arr[s[i]-'a'] == arr[s[i-1]-'a']){
            currlength++;
            
        }
        else{
            currlength = 1;
        }
        
        maxLength =  max(maxLength ,currlength );
    }
    
    cout << maxLength <<"\n";

    
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}