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

bool possible(ll mid, vector<ll>& v, ll k){
    ll n = v.size();
    ll curr = 0;
    int cnt = 1;   //subarrays
    for (ll i = 0; i < n;i++){
        if(v[i]>mid)
            return false;
        if(curr+v[i]<=mid){
            curr += v[i];
        }else{
            cnt++;
            curr = v[i];
        }
    }

    return cnt <= k;
}

void solve(){
    ll n; cin >> n;
    ll k;
    cin >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll l = *max_element(v.begin(), v.end());

    ll h = LLONG_MAX;
    ll ans = 0;
    while(l<=h){
        ll mid = l+(h-l) / 2;
        if(possible(mid,v,k)){
            ans = mid;
            h = mid - 1;
        }else{
            l = mid + 1;
        }
    }

    cout << ans << endl;
}

int main(){
    solve();
}