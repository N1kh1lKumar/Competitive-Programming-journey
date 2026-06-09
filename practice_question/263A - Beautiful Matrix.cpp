#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int arr[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>arr[i][j];
        }
    }
    
    int ans=0;
    int index1 = 2;
    int index2 = 2;
    
    int loc1 =0;
    int loc2 =0;


    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(arr[i][j] == 1){
                loc1 = i;
                loc2 = j;
                break;
            }
        }
    }
 
 
    int diff1 = abs(loc1-index1);
    int diff2 = abs(loc2-index2);
 
    ans = diff1 + diff2;
 
 
    
 
    cout << ans << endl;
 
    return 0;
}