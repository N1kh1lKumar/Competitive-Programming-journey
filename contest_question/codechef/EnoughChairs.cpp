/*
Name = Nikihl
github =https://github.com/N1kh1lKumar
linked in = https://www.linkedin.com/in/n1kh1lkumar/
leetcode = https://leetcode.com/u/N1kh1lKumar/
codolio =  https://codolio.com/profile/N1kh1lKumar
codeforces = https://codeforces.com/profile/nikhilkumaraf309
Contact Email = nikhilkumaraf309@gmail.com 
*/



/*
A college hall is being prepared for an event. There are N tables in the hall, and exactly K chairs are placed around each table.
A total of P students are expected to attend, and each student needs one chair.

Determine whether the available seating is enough for everyone.
Print YES if all students can be seated; otherwise, print NO.

Input Format
The first line contains three integers N, K, and P.
Output Format
Print YES if there are enough chairs for all the people. Otherwise, print NO.
Constraints

1 ≤ N,K,P ≤ 10^4
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
	
    int N, K, P;
    cin >>N >>K>>P;
    
    if(N*K >= P){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}
