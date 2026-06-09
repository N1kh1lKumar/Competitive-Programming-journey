//sieve algorithms is used to find all prime number in a given range in O(sqrt(n)) time complexity

#include<bits/stdc++.h>
using namespace std;

vector<bool> sieve(int n){
    vector<bool> primes(n+1, true);

    primes[0] = primes[1] = false;

    for(int i=2; i*i <= n ; i++){
        if(primes[i]){
            for(int j =i*i; j<=n; j +=i ){
                primes[j] = false;
            }
        }
    }

    return primes;
}

int main(){
    int n;
    cin >> n;

    vector<bool> primes = sieve(n);
    for(int i =0; i< primes.size(); i++){
        if(primes[i] == true)
            cout << i << " ";
    }

    cout << endl;

    return 0;
}