#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr+3);
 
    int mid = arr[1];
    int ans = abs(arr[0]-mid) + abs(arr[2]-mid);
    cout << ans << endl;
 
    return 0;
}