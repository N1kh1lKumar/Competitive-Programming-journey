/*
Name = Nikihl
github =https://github.com/N1kh1lKumar
linked in = https://www.linkedin.com/in/n1kh1lkumar/
leetcode = https://leetcode.com/u/N1kh1lKumar/
codolio =  https://codolio.com/profile/N1kh1lKumar
codeforces = https://codeforces.com/profile/nikhilkumaraf309
Contact Email = nikhilkumaraf309@gmail.com 
*/

/*============================PROBLEM STATEMENT============================
You are given an array A of N integers and an integer X.
Find the 0-based index of the second occurrence of X in the array.

If X does not appear in the array, print -1.
If X appears exactly once, print -2.

Input Format
The first line contains an integer N — the size of the array.
The second line contains N space-separated integers A0 ,A1 , … ,AN−1.
The third line contains an integer X.

Output Format
Print:

the 0-based index of the second occurrence of X, if it exists;
-1 if X does not appear;
-2 if X appears exactly once.
*/


#include<bits/stdc++.h>
using namespace std;

// some useful alias 
using ll = long long;
using dl =  long double;

// Common Data Structure Shortcuts
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

#define pb push_back


int main() {
	// your code goes here
    int N;
    cin >> N;
    
    vector<int> a(N);
    for(int i =0; i<N; i++){
        cin >> a[i];
    }
    
    int X;
    cin >> X;
    
    int count = 2;
    for(int i =0; i<N; i++){
        
        if(a[i] == X){
            count--;
        }
        if(count == 0){
            cout << i << "\n";
            break;
        }
    }
    
    if(count == 2 ){
        cout << -1 << "\n";
    }
    else if(count == 1){
        cout << -2 << "\n";
    }    
}
