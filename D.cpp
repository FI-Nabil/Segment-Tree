#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define YES cout <<"Yes\n";
#define NO cout <<"No\n";
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const ll mxN = 1e7+5;
ll spf[mxN];

void pf(){
 for (ll i=1; i<mxN; i++) spf[i] = i;
 for (ll i=2; i<mxN; i++){
  if(spf[i]==i){
    for (ll j=i+i; j<mxN; j+=i){
      spf[j] = min(spf[j], i);
    }
  }
 }
}

void dracarys(){
 ll x,y; cin >> x >> y;
 if(y-x == 1) {
  cout << -1 <<'\n'; return;
 }
 ll gap = y-x;
 vector<ll>d;
 while(gap>1){
   ll xd = spf[gap];
   while(gap%xd==0) gap /= xd;
   d.pb(xd);
 }
 ll ans = 1e16;
 for (auto p:d){
    ll rc =p* ((x+p-1)/p);
    ans = min(ans, rc-x);
 }
 cout << ans <<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);
  cin.tie(0);
  pf();
    ll tc=1; cin >> tc;
    for (ll i=1; i<=tc; i++){
        dracarys();
    }
}