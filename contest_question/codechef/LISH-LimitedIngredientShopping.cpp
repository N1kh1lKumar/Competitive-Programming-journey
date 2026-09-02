/*
Name = Nikhil
github =https://github.com/N1kh1lKumar
linked in = https://www.linkedin.com/in/n1kh1lkumar/
leetcode = https://leetcode.com/u/N1kh1lKumar/
codolio =  https://codolio.com/profile/N1kh1lKumar
codeforces = https://codeforces.com/profile/nikhilkumaraf309
Contact Email = nikhilkumaraf309@gmail.com 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long W;
    int N;

    cin >> W >> N;

    vector<long long> A(N);

    for (auto &x : A) {
        cin >> x;
    }

    sort(A.rbegin(), A.rend());

    long long sum = 0;
    int ans = 0;

    for (long long x : A) {
        sum += x;
        ans++;

        if (sum >= W) {
            cout << ans << '\n';
            return 0;
        }

        sum += x;
        ans++;

        if (sum >= W) {
            cout << ans << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';

    return 0;
}