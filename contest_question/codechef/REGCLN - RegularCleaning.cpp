/*
Name = Nikihl
github =https://github.com/N1kh1lKumar
linked in = https://www.linkedin.com/in/n1kh1lkumar/
leetcode = https://leetcode.com/u/N1kh1lKumar/
codolio =  https://codolio.com/profile/N1kh1lKumar
Contact Email = nikhilkumaraf309@gmail.com 
*/


/*============ PROBLEM STATEMENT =========================
 
Regular Cleaning
Chef will do a deep cleaning of his house every 10 days - meaning on days numbered 
10,20,30,
…

Today is day number N.
How many more days are there until the next day strictly after today that Chef will deep clean?

Input Format:
The only line of input will contain one integer N
N, representing the current day number.
Output Format
Output a single integer: the number of days till the next deep cleaning.

Constraints
1≤N≤100

========================================*/


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
    
    cout << 10 - (N%10) << "\n";
}
