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
   ll n;
   cin>>n;
   vll t(n);
   ll sum=0;
   for(ll i=0;i<n;i++){
       cin>>t[i];
       sum+=t[i];
   }
   vector<bool> dp(sum+1);
   dp[0]=true;
   for(auto i:t){
       for(ll j=sum-i;j>=0;j--){
           if(dp[j]==true)dp[j+i]=true;
       }
   }
   if(sum%2==0&&dp[sum/2]==true){
       cout<<sum/2<<endl;
   }
   else{
       ll ans;
       for(ll i=sum/2+1;i<=sum;i++){
           if(dp[i]){
               ans=i;
               break;
           }
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