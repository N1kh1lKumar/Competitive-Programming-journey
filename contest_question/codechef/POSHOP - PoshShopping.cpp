/*
Name = Nikihl
github =https://github.com/N1kh1lKumar
linked in = https://www.linkedin.com/in/n1kh1lkumar/
leetcode = https://leetcode.com/u/N1kh1lKumar/
codolio =  https://codolio.com/profile/N1kh1lKumar
Contact Email = nikhilkumaraf309@gmail.com 
*/


/*==================== PROBLEM STATEMENT =========================
There's a shop with N items. The cost of the i-th item is Ci.
Chef wants to buy at most two of these N items.

Chef doesn't want to look poor, and so if he decides to buy two items, the cost of the second item must not be smaller than the cost of the first item.
That is, if Chef decides to buy items i and j, where 
i < j, then 
Ci ≤ Cj must hold.

If Chef decides to buy only one item, there is no such constraint: any item can be bought.

Your task is to find the maximum amount of money that Chef can spend at the shop, while buying at most two items.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains a single integer N — the number of items.
The second line contains N space-separated integers C1,…,CN  — the costs of the items.
Output Format
For each test case, output on a new line the maximum amount Chef can spend.

Constraints

1 ≤ T ≤ 100
2  ≤N ≤100
1 ≤ Ci ≤100
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


void solve() {
    int N;
    cin >> N;

    vector<int> C(N);

    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    int ans = 0;

    // Buying only one item
    for (int i = 0; i < N; i++) {
        ans = max(ans, C[i]);
    }

    // Buying two items
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {

            if (C[i] <= C[j]) {
                ans = max(ans, C[i] + C[j]);
            }
        }
    }

    cout << ans << '\n';
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