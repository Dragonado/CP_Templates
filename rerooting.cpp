#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
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
#define leftmost_bit(x)  (63-__builtin_clzll(x))
#define rightmost_bit(x) __builtin_ctzll(x) // count trailing zeros
#define set_bits(x)      __builtin_popcountll(x) 
#define pow2(i)          (1LL << (i))
#define is_on(x, i)      ((x) & pow2(i)) // state of the ith bit in x
#define set_on(x, i)     ((x) | pow2(i)) // returns integer x with ith bit on
#define set_off(x, i)    ((x) & ~pow2(i)) // returns integer x with ith bit off
 
#ifdef LOCAL_DEBUG
	#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
	#define debug(...) ;
#endif
  
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
const int MX = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);
const ld EPS = 1e-8;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
 
// highly risky #defines
#define int ll // disable when you want to make code a bit faster
#define endl '\n' // disable when dealing with interactive problems
 
typedef vector<int> vi;
typedef pair<int, int> pii;
 
vector<vi> adj;
int N;
vi ans, dp, sz;
 
void dfs(int src, int par){
    for(int ne: adj[src]){
        if(ne == par) continue;
        dfs(ne, src);
 
        sz[src] += 1 + sz[ne];
        dp[src] += 1 + sz[ne] + dp[ne];
    }
}

// reroot a -> b
void reroot(int a, int b){
    dp[a] -= (1 + sz[b] + dp[b]);
    sz[a] -= (sz[b]+1);

    dp[b] += 1 + sz[a] + dp[a];
    sz[b] += sz[a] + 1;
}
 
void dfs2(int src, int par){
    ans[src] = dp[src];

    for(int ne: adj[src]){
        if(ne == par) continue;
 
        // re-root from src to ne
        reroot(src, ne);

        dfs2(ne, src);
        // re-root from ne to src
        reroot(ne, src);
    }
}
void solve(){
	// code starts from here
    // https://cses.fi/problemset/task/1132 https://cses.fi/paste/567afc423031903132b279/
    // https://cses.fi/problemset/task/1133 https://cses.fi/paste/6123f02aabe32fbd32ccc2/
    cin >> N;
    adj.resize(N);
 
    for(int u, v, i = 0; i < N-1; i++){
        cin >> u >> v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
    ans.assign(N, 0);
    dp.assign(N, 0);
    sz.assign(N, 0);

    // change dfs() and reroot(), dont change dfs2()
    dfs(0, 0);
    dfs2(0, 0);

    for(int i: ans) cout << i << " ";
    cout << endl;
}
 
 
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
 
signed main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	//startTime = clock();
	// mt19937_64 rnd(time(NULL));
 
	int T = 1;
	// cin >> T;
 
	while(T--){
		solve();
	}
	
	//cerr << getCurrentTime() << endl;
	return 0;
}