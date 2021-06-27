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
void solve()
{
   ll n,q;
   cin>>n>>q;
   vll a(n);
   for(ll i=0;i<n;i++){
       cin>>a[i];
   }
   vll v(n);
   for(ll i=0;i<n;i++){
       v[i]=a[i]-(i+1);
   }
   while(q--){
       ll k;
       cin>>k;
       ll ans=-1;
       auto z=lower_bound(all(v),k)-v.begin();
       if(z==n){
           ans=a[n-1]+k-v[n-1];
       }
       else{
           ans=a[z]-1-(v[z]-k);
       }
        cout<<ans<<endl;
   }

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