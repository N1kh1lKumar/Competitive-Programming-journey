/*
Name = Nikihl
github =https://github.com/N1kh1lKumar
linked in = https://www.linkedin.com/in/n1kh1lkumar/
leetcode = https://leetcode.com/u/N1kh1lKumar/
codolio =  https://codolio.com/profile/N1kh1lKumar
codeforces = https://codeforces.com/profile/nikhilkumaraf309
Contact Email = nikhilkumaraf309@gmail.com 
*/

/*===============PROBLEM STATEMENT =================================
There are N different types of colours numbered from 1 to N. Chef has Ai balls having colour i.

Chef will arrange some boxes and put each ball in exactly one of those boxes.
Find the minimum number of boxes Chef needs so that no box contains two balls of same colour.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases. The description of the test cases follows.
The first line of each test case contains a single integer N, denoting the number of colors.
The second line of each test case contains N space-separated integers A1 ,A2 , … , AN  — denoting the number of balls having colour i.

Output Format
For each test case, output the minimum number of boxes required so that no box contains two balls of same colour.
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
void solve(){
    int N;
    cin >> N;
    
    int ans = -1;
    vector<int> arr(N);
    for(int i =0; i<N; i++){
        cin >> arr[i];
        ans = max(ans , arr[i]);
    }
    
    cout << ans << "\n";
}


int main() {
	// your code goes here
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; 
    cin >> t;
    
    while(t--){
        solve();
    }
}
