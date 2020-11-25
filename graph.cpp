#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required

// template starts
using namespace __gnu_pbds; //required 
using namespace std;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

// ordered_set <int> s;
// s.find_by_order(k); returns the (k+1)th smallest element
// s.order_of_key(k); returns the number of elements in s strictly less than k

#define MOD              (1000000000+7) // change as required
#define pb(x)            push_back(x)
#define mp(x,y)          make_pair(x,y)
#define all(x)           x.begin(), x.end()
#define print(vec,l,r)   for(int i = l; i <= r; i++) cout << vec[i] <<" "; cout << endl;
#define input(vec,N)     for(int i = 0; i < (N); i++) cin >> vec[i];
#define debug(x)         cerr << #x << " = " << (x) << endl;
#define leftmost_bit(x)  (63-__builtin_clzll(x))
#define rightmost_bit(x) __builtin_ctzll(x)
#define set_bits(x)      __builtin_popcountll(x)
  
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long int ll;

// start of highly risky #defines

#define int ll // disable when you want to make code a bit faster
#define endl '\n' // disable when dealing with interactive problems

// End of highly risky #defines

ll N, M; // no of vertices and no of edges
vector<vector<ll>> adj;
vector<bool> vis;
vector<ll> dist;
vector<ll> tin,tout;
ll T_of_tin= 0;

void resizeAll(){
	vis.clear();
	dist.clear();
	adj.clear();
	tin.clear();
	tout.clear();
	
	vis.resize(N);
	dist.resize(N);
	adj.resize(N);
	tin.resize(N);
	tout.resize(N);
	
	for(int i = 0; i < N; i++){
		vis[i] = false;
		dist[i] = -1;
	}
}

void input_graph(){
	for(int i = 0; i < M; i++){
		int t1,t2;
		cin >> t1 >> t2;
		t1--;t2--; // assuming the input is 1 based!!
		
		adj[t1].pb(t2);
		adj[t2].pb(t1);
	}
}

void bfs(ll root){
	queue<ll> q;
	q.push(root);
	q.push(-1);
	
	vis[root] = true;
	dist[root] = 0;
	ll level = 1;
	
	while(q.size() > 1){
		int node = q.front();
		q.pop();
		
		if(node == -1){
			q.push(-1);
			level++;
			continue;
		}
		
		for(ll i = 0; i < (ll)adj[node].size(); i++){
			ll child = adj[node][i];
			if(vis[child]) continue;
			
			vis[child] = true;
			dist[child] = level;
			q.push(child);
		}
	}
}

void dfs(ll root){
	vis[root] = true;
	
	tin[root] = T_of_tin++;
	for(ll i = 0; i < (ll)adj[root].size(); i++){
		ll child = adj[root][i];
		
		if(vis[child]) continue;
		dfs(child);
	}	
	tout[root] = T_of_tin++;
}


// IMPORTANT: Everything here is 0 based index!!!!
void solve(){
	// code starts from here
	cin >> N;
	
	M = N-1; // by default tree
	cin >> M; //comment if tree
	
	resizeAll();
	input_graph();
	
	// thing to remember:
	// Make sure everything is zero based indexing
	// Make sure to check each component of the graph
	// Memory overflow. Try making ll to int
}

signed main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int T;
	T = 1;
	while(T--){
		solve();
	}

	return 0;
}
