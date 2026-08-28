/*
Name = Nikihl
github =https://github.com/N1kh1lKumar
linked in = https://www.linkedin.com/in/n1kh1lkumar/
leetcode = https://leetcode.com/u/N1kh1lKumar/
codolio =  https://codolio.com/profile/N1kh1lKumar
Contact Email = nikhilkumaraf309@gmail.com 
*/


/*
Minimum Flips
You are given an array A of length N, where each element is either 1 or -1.

In one operation, you may choose any index i and change Ai to −Ai.

Find the minimum number of operations required to make the sum of the array equal to 0.

If it is impossible, print -1.

Input Format
First line will contain T, number of test cases. Then the test cases follow.
First line of each test case consists of a single integer N denoting the length of the array.
Second line of each test case contains N space-separated integers 
A1,A2,…  denoting the array A.

Output Format
For each test case, output the minimum number of operations to make the sum of the array equal to 0.
 Output -1 if it is not possible to make the sum equal to 0.
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
    if (!(cin >> N)) return;
    
    int sum = 0;
    for(int i = 0; i < N; i++){
        int x; 
        cin >> x;
        sum += x;
    }
    
    if(N % 2 != 0){
        cout << "-1\n";
        return;
    }
  
      cout << abs(sum) / 2 << "\n";
}

int main() {
 
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while(t--){
            solve();
        }
    }
    return 0;
}
