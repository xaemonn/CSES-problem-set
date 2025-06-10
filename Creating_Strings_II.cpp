#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;

ll modInverse(ll a) {
    ll res = 1;
    ll n = mod - 2;
    while (n) {
        if (n & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    string s;
    cin >> s;

    vector<ll> fact(1000001);
    fact[0] = 1;
    for (ll i = 1; i < fact.size(); i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    map<char, int> mp;
    for (auto i : s) {
        mp[i]++;
    }

    ll res = fact[s.length()];
    for (auto x : mp) {
        res = (res * modInverse(fact[x.second])) % mod;
    }

    cout << res << endl;
}
