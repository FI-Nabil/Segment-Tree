#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
typedef tree<ll, null_type, greater_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll a[400000];
ll t[400000];


void build (ll node, ll b, ll e){
     
     if(b==e){
      t[node] = a[b];
      return;
     }
     ll left_node = 2*node;
     ll right_node = 2*node + 1;
     ll mid = (b+e)/2;
     build(left_node, b, mid);
     build (right_node, mid+1, e);
     t[node] = t[left_node] + t[right_node];


}
ll query(ll node, ll b, ll e, ll i , ll j){
  if(e<i or b>j) return 0;
  if(b>=i and e<=j){
    return t[node];
  }
  ll mid = (b+e)/2;
  ll left_node = 2*node;
  ll right_node = left_node + 1;
  return query(left_node , b , mid , i, j ) + query (right_node , mid+1,e, i, j);
}

void update (ll node, ll b, ll e, ll i, ll x){
      if(i>e or i<b)
        return;
      if(b==e and b==i){
        t[node]=x;
       return;
      }

      ll mid = (b+e)/2;
      ll left_node = 2*node;
      ll right_node = left_node + 1;
      update (left_node, b , mid, i, x);
      update (right_node, mid+1, e, i, x);
      t[node] = t[left_node] + t[right_node];
}


void solve() {
 ll n, q; cin >> n >> q;
 for (ll i=1; i<=n; i++)
   cin >> a[i];
   build(1, 1, n);
   while(q--){

   // cout << query(n, 1, n, b, c) <<'\n';
    ll id; cin >> id;
    if(id==1){
      ll ind, val;
      cin >> ind >> val;
      ind++;
      ///cout << ind <<' '<<val<<'\n';
      update(1, 1, n, ind , val);
    }
    else{
      ll l,r; cin >> l >> r; 
      l++;
   //   cout << l << ' '<< r <<'\n';
      cout << query(1, 1, n, l, r) <<'\n';
    }
   }


  }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll t =1; //cin >> t;
  while (t--) {
    solve();
  }
}
