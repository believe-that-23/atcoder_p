#include <bits/stdc++.h>
#include <cmath>
#include <regex>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define all(x) (x).begin(),(x).end()
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define vll vector<long long int>
#define FAST ios_base :: sync_with_stdio (false); cin.tie (NULL)
using namespace std;
#define endl "\n"
ll C(ll n, ll k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
       res = res * (n - k + i) / i;
    return (ll)(res + 0.01);
}
vector<vll> readGraph(ll n,ll m){
   vector<vll> g(n);
   for(ll i=0;i<m;i++){
       ll a,b;
       cin>>a>>b;
       //sc.read(a,b);
       //a--;b--;
       g[a].pb(b);
       g[b].pb(a);
   }
   return g;
}
vector<vll> readTree(int n){
   return readGraph(n,n-1);
}
//----------------------------------------------------------------------------
const ll mod=998244353;
void solve()
{
   ll n,k;
   cin>>n>>k;
   vll a;
   for(ll i=0;i<k;i++){
       ll l,kk;       
       cin>>l>>kk;
       for(ll j=l;j<=kk;j++){
           a.pb(j);
       }
   }
   vll dp(n+1);
   dp[1]=1;
   sort(all(a));
//    getunique(a);
   for(ll i=2;i<=n;i++){
       for(auto c:a){
           if(i-c>=0){
              dp[i]+=dp[i-c];
              if(dp[i]>mod)dp[i]-=mod;
           }
           else break;
       }
   }
   cout<<dp[n]<<endl;
}
int main() {
FAST;
ll t;
t=1;
while(t--){
   solve();
}
return 0;
}