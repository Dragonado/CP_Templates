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

// https://atcoder.jp/contests/abc205/submissions/23534523
// Learnt from: https://www.youtube.com/watch?v=K1i-wP82Zdo
// Time Complexity is O(F * V^2), use when flow edges are of capacity is 1 but it also works when capacity is more
// https://pastebin.com/SLf6Kjbf
class FordFulkerson{
public:
	int n;
	vector<bool> vis;
	vector<vi> adj, cap;
	int src, sink;

	FordFulkerson(int n = 0){
		vis.assign(n, false);
		adj.resize(n);
		cap.assign(n, vi(n, 0));
		this->n = n;

		src = sink = -1;
	}
	void set_src(int src){
		this->src = src;
	}
	void set_sink(int sink){
		this->sink = sink;
	}

	void add_edge(int from, int to, int edge_cap){
		adj[from].pb(to);
		adj[to].pb(from);
		cap[from][to] += edge_cap;
	}

	int dfs(int cur, int min_cost){
		vis[cur] = true;

		if(cur == sink){
			return min_cost;
		}
		
		for(int ne: adj[cur]){
			if(vis[ne] || cap[cur][ne] == 0) continue;
			
			int cur_min = min(min_cost, cap[cur][ne]);
			int t = dfs(ne, cur_min);

			if(t > 0){
				cap[cur][ne] -= t;
				cap[ne][cur] += t;
				return t;
			}	
			
		}

		return 0; // no path found
	}

	int getMaxFlow(){
		assert(src != sink);

		int ans = 0;
		int sent = -1;

		while(sent != 0){
			vis.assign(n, false);
			sent = dfs(src, INF);
			ans += sent;
		}
		return ans;
	}
};

void solve(){
	// code starts from here
	
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
	cin >> T;

	while(T--){
		solve();
	}
	
	//cerr << getCurrentTime() << endl;
	return 0;
}
