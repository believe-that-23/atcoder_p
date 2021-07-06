#include <bits/stdc++.h>
#include <cmath>
#include <regex>
#define fi first
#define endl "\n"
#define se second
#define pb push_back
#define mp make_pair
#define ba back
#define ppb pop_back
#define pqb   priority_queue<long long int>
#define eb emplace_back
#define eps 1e-6
#define vll vector<long long int>
#define pqs   priority_queue<int,vll,greater<long long int> >
#define sz(x) (int((x.size())))
#define all(x) (x).begin(),(x).end()
#define FAST ios_base :: sync_with_stdio (false); cin.tie (NULL)
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,a,b) for(ll i=b-1;i>=a;i--)
//-------------------------------------Mod_operations------------------------------------------
const ll M = 1e9 + 7;
const ll N = 1e5 + 5;
const ll inf = 2e18;
ll mod(ll x){   return (x%M);}
ll mod_minus(ll a, ll b){ ll ans= (mod(a)-mod(b)); if(ans<0) ans=mod(ans+M); return ans;}
ll mod_mul(ll a,ll b){  return mod(mod(a)*mod(b));}
ll mod_add(ll a,ll b){ return mod(mod(a)+mod(b));}
ll power(ll a,ll n){  if(n==0) return 1;  else if(n==1) return a;  ll R=power(a,n/2)%M;  if(n%2==0) {  return mod(mod_mul(R,R)); }   else { return mod(mod_mul(mod_mul(R,a),mod(R)));  }}
ll mod_div(ll a,ll b){// only if M is prime
ll ans=mod(a);
ll b1=power(b,M-2);
 ans= mod(mod_mul(ans,b1));
 return ans;
}
ll mod_inv(ll n){  return power(n,M-2);}
ll fact_mod(ll n){
    vll fact(n+1);
    fact[0]=1;
     for(ll i=1;i<n+1;i++){
     fact[i]=mod_mul(fact[i-1],i);
     }
     return fact[n];
}
ll ncr(ll n,  ll r)
{
    if (r == 0 || n==0)
        return 1;
    ll fac[n + 1];
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % M;
    return (fac[n] * mod_inv(fac[r]) % M * mod_inv(fac[n - r]) % M) % M;
}
pair<ll,ll> Egcd(ll a,ll b)
{
 if(b==0)
 return make_pair(1,0);
 pair<ll,ll> t=Egcd(b,a%b);
 return make_pair(t.se,t.fi-(a/b)*t.se);
}
//-------------------------------------------------------------------------------------------------


/*ll tree[1000], a[1000], n;
ll sum(ll k) {
    ll s = 0;
    while (k >= 1) {
    s += tree[k];
    k -= k&-k;
    }
    return s;
}
void update(ll k, ll x) {
    while (k <= n) {
        tree[k] += x;
        k += k&-k;
    }
}*/


void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> g(n);
    for (ll i = 0; i < m; i++) {
        ll a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        g[a].pb({b,c});
    }
    vector<vll> d(n,vll(n,INT_MAX));
    for (ll i = 0; i < n; i++) {
        d[i][i]=0;
    }
    for (ll i = 0; i < n; i++) {
        for(auto c : g[i]){
            ll j=c.fi;
            ll w=c.se;
            d[i][j]=min(d[i][j],w);
            
        }
    }
    ll ans=0;

    for (ll k = 0; k < n; k++) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                if(d[i][k]!=INT_MAX&&d[k][j]!=INT_MAX)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
        for (ll i = 0; i < n; i++) {
           for (ll j = 0; j < n; j++) {
              if(d[i][j]!=INT_MAX)
                 ans+=d[i][j];
            }
        }
    }
    cout<<ans<<endl;
}
int main() {
FAST;
ll t;
t=1;
while(t--)
{
    solve();
}
return 0;
}
