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

vector<int> x = {1, -1, 0, 0};
vector<int> y = {0, 0, 1, -1};



void dfs(vector<vector<char>>&v, vector<vector<int>>& vis, int i, int j){
    vis[i][j] = true;
    int n = v.size();
    int m = v[0].size();
    for (int d = 0; d < 4; d++){
        int r=i+x[d];
        int c = j + y[d];
        if(r>=0 && r<n && c>=0 && c<m&&  !vis[r][c]){
            dfs(v, vis, r, c);
        }
    }
}

void solve(){
    ll n,m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i<n ;i++){
        for(int j=0; j<m;j++){
            char ch;
            cin >> ch;
            v[i][j] = ch;
            if(ch=='#'){
                vis[i][j] = 1;
            }
        }
    }

    int cnt = 0;

    for(int i=0; i<n ;i++){
        for(int j=0; j<m ;j++){
            if(!vis[i][j]){
                dfs(v, vis, i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}

int main(){
    solve();
}