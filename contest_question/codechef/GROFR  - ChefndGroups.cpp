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
There are N  seats arranged in a row. Each seat is either empty or occupied.
You are given a binary string S of length N. A character 0 represents an empty seat, while a character 1 represents an occupied seat.
People sitting in consecutive occupied seats belong to the same group.

For example, in the string 011010, the occupied seats form two groups: 11 and 1.

Find the total number of groups.

Input Format
The first line contains a single integer N — the number of seats.
The second line contains a binary string S of length N.

Output Format
Print a single integer — the number of groups of occupied seats.
Constraints
1 ≤ N ≤ 10
5
1≤N≤10^5
 
Si ∈{0,1}
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
    string  S;
    cin >> S;
    
    bool occupied = false;
    
    int count = 0; 
    
    for(int i =0; i<S.size(); i++){
        
        if(occupied == false &&  S[i] == '1'){
            occupied = true;
            count++;
        }
        else if(occupied == true && S[i] == '1')
        {
            continue;
        }
        else if(occupied == true && S[i] == '0'){
            occupied = false;
        }
    }
    
    cout << count << "\n";
}