#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[400000];
ll inf = 1e16;
struct val
{
  ll mnn;
  ll freq;
}tree[400000];

void build (ll node, ll b, ll e){
   if(b==e){
    tree[node].mnn = a[b];
    tree[node].freq = 1;
    return;
   }
   ll mid = (b+e)/2;
   ll left_node = 2*node;
   ll right_node = left_node + 1;
   build(left_node, b, mid);
   build(right_node, mid+1, e);

   tree[node].mnn = min(tree[left_node].mnn , tree[right_node].mnn);
   ll y=0;
   if(tree[node].mnn == tree[left_node].mnn){
    y += tree[left_node].freq;
   }
   if(tree[node].mnn == tree[right_node].mnn){
    y += tree[right_node].freq;
   }
  
   tree[node].freq = y;

}

void update(ll node, ll b, ll e, ll ind, ll new_val){
    if(ind > e or ind <b)
      return;
    if(b==e and b==ind){
      tree[node].mnn = new_val;
      return;
    }

   ll mid = (b+e)/2;
   ll left_node = 2*node;
   ll right_node = left_node + 1;
   update(left_node, b, mid, ind, new_val);
   update(right_node, mid+1, e, ind, new_val);
   tree [node].mnn = min( tree[left_node].mnn , tree[right_node].mnn);
    ll x = 0, y = 0;
   if(tree[node].mnn == tree[left_node].mnn){
    y += tree[left_node].freq;
   }
   if(tree[node].mnn == tree[right_node].mnn){
    y += tree[right_node].freq;
   }
   tree[node].freq = y;
}
ll ans = 0;

pair<ll,ll> query (ll node, ll b, ll e, ll i, ll j){
  pair<ll,ll>pr;
   if(e<i or b>j){
    pr.first = inf;
    pr.second = inf;
     return pr;
   }
   if(b>=i and e<=j){
    pr.first = tree[node].mnn;
    pr.second = tree[node].freq;
     return pr;
   }

  ll mid = (b+e)/2;
  ll left_node = 2*node;
  ll right_node = left_node + 1;
 
  pair<ll,ll>left_min = query(left_node, b, mid, i, j);
  pair<ll,ll>right_min = query(right_node, mid+1, e, i, j);
  ll mn = min(left_min.first , right_min.first);
  ll x = 0;
  if(mn == left_min.first){
    x += left_min.second;
  }
  if(mn == right_min.first){
    x += right_min.second;
  }
  pr.first = mn;
  pr.second = x;
  return pr;
}


void solve() {
ll n,m; cin >> n >> m;
  for (ll i=1; i<=n; i++)
    cin >> a[i];
  build(1, 1, n);

  while(m--){
    ll id; cin >> id;
    if(id==1){
      ll ind, new_val;
      cin >> ind >> new_val;
      ind++;
      update(1, 1, n, ind, new_val);
    }
    else{
      ll l,r;
      cin >> l >> r;
      l+=1;
      
     pair<ll,ll> as = query(1, 1, n, l, r);
      cout << as.first <<' '<<as.second <<'\n';
      ll ans = 0;
    }
  }
  
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll t =1; // cin >> t;
  while (t--) {
    solve();
  }
}