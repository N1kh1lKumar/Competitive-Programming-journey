#include<bits/stdc++.h>
using namespace std;
 
void solve(){
    int number;
    cin >> number;
 
    int ans=0;
    vector<int> answers;
    int div = 10;
 
    while(number > 0){
        int rem = number % div;
        if(rem != 0){
            answers.push_back(rem);
            ans += 1;
            number -= rem;
        }
        div = div*10;
    }
 
    cout << ans << endl;
    for(int val : answers){
        cout << val << " ";
    }
    cout << endl;
 
}
 
 
int main(){
    int t ;
    cin >> t;
 
    while(t--){
        solve();
    }
 
    return 0;
}