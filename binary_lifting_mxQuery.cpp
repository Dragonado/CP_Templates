#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> //required
//#include <ext/pb_ds/tree_policy.hpp> //required

//using namespace __gnu_pbds; //required 
using namespace std;
//template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

// ordered_set <int> s;
// s.find_by_order(k); returns the (k+1)th smallest element
// s.order_of_key(k); returns the number of elements in s strictly less than k

#define pb               push_back
#define mp(x,y)          make_pair(x,y)
#define all(x)           x.begin(), x.end()
#define print(vec,l,r)   for(int i = l; i <= r; i++) cout << vec[i] <<" "; cout << endl;
#define input(vec,N)     for(int i = 0; i < (N); i++) cin >> vec[i];
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#define leftmost_bit(x)  (63-__builtin_clzll(x))
#define rightmost_bit(x) __builtin_ctzll(x) // count trailing zeros
#define set_bits(x)      __builtin_popcountll(x) 
#define pow2(i)          (1LL << (i))
#define is_on(x, i)      ((x) & pow2(i)) // state of the ith bit in x
#define set_on(x, i)     ((x) | pow2(i)) // returns integer x with ith bit on
#define set_off(x, i)    ((x) & ~pow2(i)) // returns integer x with ith bit off
  
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// auto dist = uniform_int_distribution<int>(l, r);
// use int a = dist(rng) to get a random number between [l,r] inclusive
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cerr << vars << " = ";
    string delim = "";
    (..., (cerr << delim << values, delim = ", "));
	cerr << endl;
}

typedef long long int ll;
typedef long double ld;

const int MOD = 1e9+7; // 998244353;

const ll INF = 1e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);
const ld EPS = 1e-8;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

// highly risky #defines
#define int ll // disable when you want to make code a bit faster
#define endl '\n' // disable when dealing with interactive problems

typedef vector<int> vi;
typedef pair<int, int> pii;

const int MAXN = 1e6+5;
int n, l; // = 1 + log2(MAXN); use only if no multitests
int timer;
vector<int> tin, tout;
vector<vector<pii>> up, adj;

#define fi first
#define se second

void dfs(int v, int p, int w){
    tin[v] = ++timer;
    up[v][0].fi = p;
    up[v][0].se = w;

    pii mid;
    for (int i = 1; i <= l; ++i){
        mid = up[v][i-1];
        up[v][i].fi = up[mid.fi][i-1].fi;
        up[v][i].se = max(mid.se, up[mid.fi][i-1].se);
    }

    for (pii ne : adj[v]) {
        if (ne.first != p)
            dfs(ne.first, v, ne.second);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i].fi, v))
            u = up[u][i].fi;
    }
    return up[u][0].fi;
}

int getMaxToAnc(int u, int v){
    assert(is_ancestor(u, v)); // u is ancestor of v

    int ans = 0, temp;
    for(int i = l; i >= 0; i--){
        if(!is_ancestor(u, up[v][i].fi)) continue;

        ans = max(ans, up[v][i].se);
        v = up[v][i].fi;
    }
    return ans;
}

int getMax(int u, int v){
    int lc = lca(u, v);
    return max(getMaxToAnc(lc, u), getMaxToAnc(lc, v)); 
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<pii>(l + 1, {0,-INF}));
    dfs(root, root, 0);
}
//-------------------------------------------------------

void solve(){
	// code starts from here
	cin >> n;

	adj.clear();
	adj.resize(n);

    int u, v, w;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v >> w;
		u--;v--; // assuming 1 based indexing
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}

	preprocess(0); // usually 0 is root

    int Q;
    cin >> Q;
    while(Q--){
        cin >> u >> v;
        u--;v--;

        cout << getMax(u, v) << endl; // returns the maximum edge in the path between u, v
    }
}

signed main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int T = 1;
	cin >> T;
	while(T--){
		solve();
	}

	return 0;
}
