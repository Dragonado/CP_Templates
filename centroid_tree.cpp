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

#define MOD              (1000000000+7) // change as required
#define pb(x)            push_back(x)
#define mp(x,y)          make_pair(x,y)
#define all(x)           x.begin(), x.end()
#define print(vec,l,r)   for(int i = l; i <= r; i++) cout << vec[i] <<" "; cout << endl;
#define input(vec,N)     for(int i = 0; i < (N); i++) cin >> vec[i];
#define debug(x)         cerr << #x << " = " << (x) << endl;
#define leftmost_bit(x)  (63-__builtin_clzll(x))
#define rightmost_bit(x) __builtin_ctzll(x) // count trailing zeros
#define set_bits(x)      __builtin_popcountll(x) 
#define pow2(i)          (1LL << (i))
#define is_on(x, i)      ((x) & pow2(i)) // state of the ith bit in x
#define set_on(x, i)     ((x) | pow2(i)) // returns integer x with ith bit on
#define set_off(x, i)    ((x) & ~pow2(i)) // returns integer x with ith bit off
  
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long int ll;

// highly risky #defines
#define int ll // disable when you want to make code a bit faster
#define endl '\n' // disable when dealing with interactive problems


const int MAXN = 1e5 + 10;
const int LOGN = 20; // 20 will work upto N ~ 10^6, log2(MAXN) + 2;


// taken from https://pastebin.com/YPhMK9Dg Orz Tanuj Khattar
class centroidTree{
public:
    // Original Tree
    vector<int> g[MAXN];
    int sub[MAXN], nn, U[MAXN], V[MAXN], W[MAXN], deleted[MAXN];

    // Centroid Tree
    int par[MAXN], level[MAXN], dist[LOGN][MAXN];
    // dist[LOGN][N] : dist[lvl][x] :  Distance between C and x in the original tree, when node C becomes a centroid at level "lvl". 
    // G[u] --> [v1, v2, v3] ... Not doing this.
    // G[u] --> [e1, e1, e3 ..] 
    int adj(int x, int e) { return U[e] ^ V[e] ^ x; }
    void dfs1(int u, int p) {
    sub[u] = 1;
    nn++;
    for (auto e : g[u]) {
        int w = adj(u, e);
        if (w != p && !deleted[e]) dfs1(w, u), sub[u] += sub[w];
    }
    }
    int find_centroid(int u, int p) {
        for (auto e : g[u]) {
            if (deleted[e]) continue;
            int w = adj(u, e);
            if (w != p && sub[w] > nn / 2) return find_centroid(w, u);
        }
        return u;
    }
    void add_edge_centroid_tree(int parent, int child) {
        par[child] = parent;
        level[child] = level[parent] + 1;
    }

    void dfs2(int u, int p, int lvl) {
        for (auto e : g[u]) {
            int w = adj(u, e);
            if (w == p || deleted[e]) continue;
            dist[lvl][w] = dist[lvl][u] + W[e];
            dfs2(w, u, lvl);
        }
    }
    // unordered_map<int, int> dist[N]; -- inefficient.
    // all the nn nodes which lie in the component of "centroid"
    // dist[centroid][x] = <value>
    // int dist[LOGN][N]; (centroid,x) --> one to one mapping --> (level[centroid], x);
    void decompose(int root, int p = -1) {
        nn = 0;
        // Compute subtree sizes and no. of nodes (nn) in this tree.
        dfs1(root, root);
        // Find the centroid of the tree and make it the new root.
        int centroid = find_centroid(root, root);
        // Construct the Centroid Tree
        if (p == -1) p = root;
        add_edge_centroid_tree(p, centroid);
        // Process the O(N) paths from centroid to all leaves in this component.
        dfs2(centroid, centroid, level[centroid]);
        // Delete the adjacent edges and recursively decompose the adjacent subtrees.
        for (auto e : g[centroid]) {
            if (deleted[e]) continue;
            deleted[e] = 1;
            int w = adj(centroid, e);
            decompose(w, centroid);
        }
    }
    
    int compute_distance(int x, int y) {
        // We need to compute the LCA(x, y) in the centroid tree. 
        // O(logN).
        int lca_level = 0;
        for (int i = x, j = y; (lca_level = level[i]) && i != j;
            level[i] < level[j] ? (j = par[j]) : (i = par[i]))
        ;
        return dist[lca_level][x] + dist[lca_level][y];
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
