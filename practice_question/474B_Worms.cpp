 #include<bits/stdc++.h>
using namespace std;
 
 
int main(){
 
    int n ;
    cin >>n;
 
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >>arr[i];
    }
 
    for(int i=1; i<n; i++){
        arr[i] += arr[i-1];
    }
 
    int m;
    cin >>m;
 
    while(m--){ 
    int x;
    cin >>x;
 
     int lb = lower_bound(arr.begin(), arr.end(), x)-arr.begin();
    cout << lb+1 << endl;
    
    }
 
    return 0;
}