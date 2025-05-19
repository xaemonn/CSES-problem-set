#include <bits/stdc++.h>
using namespace std;

#define ll long long


const int mod = 1e9 + 7;

void solve(){
    ll n; cin >> n;
    ll req;
    cin >> req;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<ll> dp(req + 1,0);
    dp[0] = 1;
    for (int i = 1; i <= req; i++){
        for (int c:v)
        {
           if(i-c>=0)
                {dp[i]= (dp[i]+dp[i - c])%mod;}
        }
    }

    cout << dp[req] << endl;
}

int main(){
    solve();
}