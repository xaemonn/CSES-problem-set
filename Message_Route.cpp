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
    vector<vector<ll>> adj(n);
    for (int i = 0; i < k;i++){
        int u, v;
        cin>>u>>v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    
    queue<int> q;

    q.push(0);
    vector<int> vis(n, 0);
    vector<int> par(n,-1);
    par[0] = 0;
    vis[0] = 1;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        if(it==n-1){

            break;
        }

        for(auto i:adj[it]){
            if(!vis[i]){
                vis[i]=1;
                par[i] = it;
                q.push(i);
            }
        }
    }

    if(par[n-1]==-1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<int> route;
    route.push_back(n - 1);
    int st = n-1;
    while(st!=0){
        st = par[st];
        route.push_back(st);
    }

    reverse(route.begin(), route.end());
    cout<<route.size()<<endl;
    for(auto i:route){
        cout << i+1 << " ";
    }
}

int main(){
    solve();
}