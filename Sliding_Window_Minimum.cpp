#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

void solve(){
    ll n,k; cin >> n>>k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    deque<pair<ll, ll>> dq;
    ll xorr = 0;

    for (ll i = 0; i < n;i++){
        // remove from back if element >=x 
        while(!dq.empty() && dq.back().first>=x){
            dq.pop_back();
        }

        dq.emplace_back(x, i);

        // remove elements outside the window

        while(!dq.empty() && dq.front().second<=i-k){
            dq.pop_front();
        }

        if(i>=k-1){
            xorr = xorr ^ dq.front().first;
        }

        x = (x * a + b) % c;
    }

        cout << xorr << endl;
}

int main(){
    solve();
}