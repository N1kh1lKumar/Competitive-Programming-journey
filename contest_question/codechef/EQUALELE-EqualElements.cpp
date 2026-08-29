/*
Name = Nikihl
github =https://github.com/N1kh1lKumar
linked in = https://www.linkedin.com/in/n1kh1lkumar/
leetcode = https://leetcode.com/u/N1kh1lKumar/
codolio =  https://codolio.com/profile/N1kh1lKumar
codeforces = https://codeforces.com/profile/nikhilkumaraf309
Contact Email = nikhilkumaraf309@gmail.com 
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


/*============== PROBLEM STATEMENT ==============
You are given an array A of size N. In one operation, you can do the following:

Select indices i and j (i ≠ j) and set Ai = Aj .
Find the minimum number of operations required to make all elements of the array equal.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains an integer N — the size of the array.
The next line contains N space-separated integers, denoting the array A.

Output Format
For each test case, output on a new line, the minimum number of operations required to make all elements of the array equal.
===================================================*/

void solve(){
    int N;
    cin >> N;
    
    unordered_map<int, int> freq;
    int maxFreq = 0;
    
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        freq[x]++;
        maxFreq = max(maxFreq, freq[x]);
    }
    
    cout << N - maxFreq << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}