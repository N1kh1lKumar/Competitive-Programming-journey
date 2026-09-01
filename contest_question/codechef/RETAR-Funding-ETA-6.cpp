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
Star Games is preparing to begin development of ETA 6.

To fund the project, the company has sold two editions of ETA 5:

X copies of the Standard Edition, earning A units from each copy.
Y copies of the Deluxe Edition, earning B units from each copy.

Star Games needs at least D units in total revenue to begin development of ETA 6.

Print YES if the revenue earned from both editions is at least D. Otherwise, print NO.

Input Format
The first line contains five space-separated integers X, A, Y, B, and D.

Output Format
Print YES if Star Games has earned at least D units.

Otherwise, print NO.
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
    int X, A, Y, B, D;
    cin >> X >> A >> Y >> B >> D;
    
    if(X*A + Y*B  >= D){
        cout << "YES\n"; 
    }
    else{
        cout << "NO\n";
    }
}
