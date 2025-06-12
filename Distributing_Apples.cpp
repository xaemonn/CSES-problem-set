#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9 + 7;
const ll MAX = 2e6 + 5;

ll inv(ll base, ll exp){
    ll res = 1;
    while(exp){
        if(exp & 1){
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main(){
    ll n, m;
    cin >> n >> m;

    vector<ll> fact(MAX);
    fact[0] = 1;
    for (ll i = 1; i < MAX; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }

    ll top = fact[n + m - 1];
    ll den1 = inv(fact[n - 1], mod - 2);
    ll den2 = inv(fact[m], mod - 2);

    ll ans = top * den1 % mod * den2 % mod;
    cout << ans << endl;
}
