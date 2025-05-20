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
    ll n; cin >> n;
    ll x;
    cin >> x;
    vector<pair<ll,ll>> v(n);
    for (int i = 0; i < n; i++) {
        ll num;
        cin >> num;
        v[i] = {num, i+1};
    }

    sort(v.begin(),v.end());

    ll curr = 0;

    for (int i = 0; i < n - 2; i++){
        ll val1 = v[i].first;
        // fix one value vary other two

        int ptr1 = i + 1;
        int ptr2 = n - 1;

        while(ptr1<ptr2){
            curr = val1 + v[ptr1].first + v[ptr2].first;


            if(curr==x)
            {   
               cout<<v[i].second<<" "<<v[ptr1].second<<" "<<v[ptr2].second<<endl;
              
               return;
            }else if(curr<x){
                ptr1++;
            }else{
                ptr2--;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main(){
    solve();
}