#include <bits/stdc++.h>
#include <cmath>
#include <regex>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define all(x) (x).begin(),(x).end()
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
const ll mod=1e9+7;
void solve()
{
   ll n;
   cin>>n;
   vll a(n);
   vll pref;
   for(ll i=0;i<n;i++){
       cin>>a[i];
   }
   pref.pb(a[0]%mod);
   for(ll i=1;i<n;i++){
       ll temp=(pref.back()+a[i])%mod;
       pref.pb(temp%mod);
   }
   ll ans=0;
   for(ll i=0;i<n-1;i++){
       ans=(ans+((pref.back()-pref[i])%mod*a[i])%mod)%mod;
       if(ans<0)ans+=mod,ans%=mod;
       
   }
   cout<<ans%mod<<endl;
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