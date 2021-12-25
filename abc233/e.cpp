#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define pf push_front
#define ppf pop_front()
#define eb emplace_back
#define mp make_pair
#define ll long long
#define lld long double
#define all(x) (x).begin(),(x).end()
#define vll vector<long long int>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag,tree_order_statistics_node_update>

//-----------------------------------------------------------


void solve()
{
    string s;
    cin>>s;
    ll n=(ll)s.size();
    vll cnt(n);
    for (ll i = 0; i < n; i++) {
        cnt[i]=s[i]-'0';
        if(i)cnt[i]+=cnt[i-1];
    }
    for(ll i=n-1;i>0;i--){
        cnt[i-1]+=cnt[i]/10;
        cnt[i]%=10;
    }
    for(auto c:cnt)cout<<c;
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    for(int i=1;i<=t;i++){
//        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}








