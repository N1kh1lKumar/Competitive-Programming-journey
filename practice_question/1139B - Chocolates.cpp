#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >>n;
 
    long long arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
 
    long long ans = arr[n-1];
    long long mx_ch= arr[n-1]-1;
 
    for(int i=n-2; i>=0; i--){
        ans += min(arr[i], mx_ch);
        mx_ch = min(mx_ch, arr[i])-1;
 
        if(mx_ch<=0){
            break;
        }
    }
 
    cout << ans << endl;
 
    return 0;
}