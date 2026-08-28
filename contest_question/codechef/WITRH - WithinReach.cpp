/*
Name = Nikihl
github =https://github.com/N1kh1lKumar
linked in = https://www.linkedin.com/in/n1kh1lkumar/
leetcode = https://leetcode.com/u/N1kh1lKumar/
codolio =  https://codolio.com/profile/N1kh1lKumar
codeforces = https://codeforces.com/profile/nikhilkumaraf309
Contact Email = nikhilkumaraf309@gmail.com 
*/


/*==================== PROBLEM STATEMENT =========================
A robot is standing at position X on a one-dimensional line, and its charging station is located at position Y on the same line.

The robot can move either left or right and can travel at most K units with its remaining battery.

Determine whether the robot can reach the charging station.

Input Format
The first line contains three space-separated integers X, Y, and K.

Output Format
Print YES if the robot can reach the charging station.
Otherwise, print NO.
Constraints
0 ≤ X, Y ≤ 100
0≤K≤100
===================================================================*/

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
	int x, y, k;
	cin >> x >> y>> k;
	
	if(abs(y-x)<= k){
	    cout << "YES\n";
	}
	else{
	    cout << "NO\n";
	    }

}
