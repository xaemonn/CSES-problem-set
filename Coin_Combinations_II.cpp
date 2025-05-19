#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;

void solve(){
    ll n, req;
    cin >> n >> req;
    vector<ll> coin(n);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    vector<ll> dp(req + 1, 0);
    dp[0] = 1; // base case: one way to make sum 0

    for (int i = 0; i < n; i++) {
        for (int sum = coin[i]; sum <= req; sum++) {
            dp[sum] = (dp[sum] + dp[sum - coin[i]]) % mod;
        }
    }

    cout << dp[req] << endl;
}

int main(){
    solve();
}
