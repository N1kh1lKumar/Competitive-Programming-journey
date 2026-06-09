#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long  powbin(long long  a, long long  b){

    if(b == 0) return 1;
    if(b == 1) return a;


    long long  x = powbin(a, b/2);

    long long ans = 0;

    if(b%2==1){ 
         ans = (x*x*a);
    }
    else{ 
         ans = x*x;
    }

    return ans;  
}




int main(){ 
    long long n,m;
    cin >> n >>m;

    if(n>30){
        cout <<  m ;
    }
    else{
        long long  x = powbin(2, n);
        long long ans = m%x;
        cout<< ans ;
    }
    return 0;
}