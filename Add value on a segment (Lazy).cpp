#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[400000];
ll t[400000];
ll lazy[400000];

void push(ll node, ll b, ll e){
  if(lazy[node]==0) return;
  t[node] = t[node] + (e-b+1)*lazy[node];
  if(b!=e){
    lazy[node*2] += lazy[node];
    lazy[node*2 + 1] += lazy[node]; 
  }
  lazy[node]=0;
}

void merge(ll node){
  t[node] = t[node*2]+t[node*2 + 1];
}

void upd(ll node, ll b, ll e, ll i, ll j, ll v){
  push(node, b, e);
    if(b>j or e<i) return;
    if(i<=b and e<=j){
      lazy[node] = v;
      push(node, b, e);
      return;
    }

  ll mid = (b+e)/2;
  ll left_node = node*2;
  ll right_node = left_node + 1;
  upd(left_node, b, mid, i, j, v);
  upd(right_node, mid+1, e, i, j, v);
  merge(node);
}

ll query(ll node, ll b, ll e, ll i){
  push(node, b, e);
  if(b>i or e<i) return 0;
   if(i<=b and e<=i){
    //  push(node, b, e);
      return t[node];
    }
    ll mid = (b+e)/2;
  ll left_node = node*2;
  ll right_node = left_node + 1;
    
    ll p = query(left_node, b, mid, i);
    ll q = query(right_node, mid+1, e, i);

    return p+q; // combine

}

void solve(){
ll n, q; cin >> n >> q;
for (ll i=1; i<=n; i++)
  a[i] = t[i] = lazy[i] = 0;

while(q--){
   ll x; cin >> x;
    if(x==1){
        ll l,r; cin >> l >> r; l++;
        ll v; cin >> v;
        upd(1,1,n,l,r,v);
    }
    else{
       ll i; cin >> i;
       i++;
      cout << query(1, 1, n , i) <<'\n';
    }
}
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll ts =1; // cin >> t;
  while (ts--) {
    solve();
  }
}

/*
1 l r v: assign value v to all elements on the segment from l to r−1 (0≤l<r≤n, 0≤v≤10^9).
2 i: find the value of the element with index i (0≤i<n).

Input :
5 5
1 0 3 3
2 1
1 2 4 4
2 3
2 4

Output :
3
4
0

*/
