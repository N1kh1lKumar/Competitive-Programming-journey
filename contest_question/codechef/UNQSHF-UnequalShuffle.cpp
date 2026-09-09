/*
Name = Nikhil
github =https://github.com/N1kh1lKumar
linked in = https://www.linkedin.com/in/n1kh1lkumar/
leetcode = https://leetcode.com/u/N1kh1lKumar/
codolio =  https://codolio.com/profile/N1kh1lKumar
codeforces = https://codeforces.com/profile/nikhilkumaraf309
Contact Email = nikhilkumaraf309@gmail.com 
*/


#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    
   
    int count_a_in_A = count(a.begin(), a.end(), 'a');
    int count_a_in_B = count(b.begin(), b.end(), 'a');
    
    
    if (count_a_in_A + count_a_in_B == n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
