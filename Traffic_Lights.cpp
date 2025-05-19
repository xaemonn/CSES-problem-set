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
    ll n, q; cin >> n>>q;
     //take input first if try to run while taking input also it gives TLE
    vector<int> v(q);
    for (int i = 0; i < q;i++){
        cin >> v[i];
    }
        set<pair<int, int>> range;
    range.insert({0,n});

    multiset<int> len;
    len.insert(n);

    for (int i = 0; i < q; i++){
        int pos = v[i];
        auto it = range.upper_bound({pos, 0});
        // first pair such that a>pos && a==pos then b>0
        it--;

        range.erase(it);
        int st=it->first;
        int end = it->second;
        int l=end-st;
        len.erase(len.find(l));

        range.insert({st, pos});
        range.insert({pos,end});
        len.insert(pos - st);
        len.insert(end- pos);

        cout << *len.rbegin() << " ";
    }

    cout << endl;
}

int main(){
    solve();
}