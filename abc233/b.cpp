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
    ll l,r;
    cin>>l>>r;
    l--,r--;
    string s;
    cin>>s;
    ll n=(ll)s.size();
    string a="";
    string b="";
    string c="";
    for (ll i = 0; i < n; i++) {
        if(i==l)break;
        a+=s[i];
    }
    for(ll i=l;i<=r;i++){
        b+=s[i];
    }
    for(ll i=r+1;i<n;i++){
        c+=s[i];
    }
    reverse(all(b));
    string ans="";
    ans+=a;
    ans+=b;
    ans+=c;
    cout<<ans<<endl;
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








