#include <bits/stdc++.h>
#include <cmath>
#include <regex>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define all(x) (x).begin(), (x).end()
#define getunique(v)                                  \
    {                                                 \
        sort(v.begin(), v.end());                     \
        v.erase(unique(v.begin(), v.end()), v.end()); \
    }
#define vll vector<long long int>
#define FAST                           \
    ios_base ::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;
#define endl "\n"
ll C(ll n, ll k)
{
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (ll)(res + 0.01);
}
vector<vll> readGraph(ll n, ll m)
{
    vector<vll> g(n);
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        //sc.read(a,b);
        //a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    return g;
}
vector<vll> readTree(int n)
{
    return readGraph(n, n - 1);
}
//----------------------------------------------------------------------------

void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    map<ll, ll> m;
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
        m[a[i]] = a[i];
    }
    vector<bool> used(n);
    ll ans = 0;
    if (a[0] != a[n - 1])
        m[a[n - 1]] = a[0], ans++, used[m[a[0]]] = true;

    for (ll i = 1; i < n / 2; i++)
    {
        if (m[a[i]] != m[a[n - i - 1]])
        {
            if (!used[m[a[i]]])
            {
                used[m[a[i]]] = true;
                m[a[n - i - 1]] = m[a[i]];
                ans++;
                continue;
            }
            if (!used[m[a[n - i - 1]]])
            {
                used[m[a[n - i - 1]]] = true;
                m[a[i]] = m[a[n - i - 1]];
                ans++;
            }
        }
    }
    for(ll i=0;i<n;i++){
        cout<<m[a[i]]<<" ";
    }
    cout << ans << endl;
}
int main()
{
    FAST;
    ll t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
