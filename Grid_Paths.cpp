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

ll mod = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
     //no of ways to reach from 0,0 to i,j
    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    if(grid[0][0]=='.'){dp[0][0] = 1; }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '*') continue;
            
            if (i - 1 >= 0)
                {
                    dp[i][j] = (dp[i][j]+dp[i - 1][j])%mod;
                }
            if (j - 1 >= 0)
                {
                    dp[i][j] = (dp[i][j]+dp[i][j - 1])%mod;
                }
            
        }
    }
    cout << dp[n - 1][n - 1] << endl;
}

int main()
{
    solve();
}