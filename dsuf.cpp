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

class DSUF{
public:
	vector<int> dist, sz;
    vector<int> par;
    int distinct_comp;
    int N;
    
    DSUF(int n){
		N = n;
		distinct_comp = n;
		dist.resize(n);
		par.resize(n);
		sz.resize(n);
		
		for(int i = 0; i < N; i++){
			dist[i] = 0;
			par[i] = i;
			sz[i] = 1;
		}
	}
    
    int get_key(int k){
        while(k != par[k]) k = par[k];
        return k;
    }
    
    void merge(int k1, int k2){
        int head_k1 = get_key(k1);
        int head_k2 = get_key(k2);
        
        if(head_k1 == head_k2) return;
        
        distinct_comp--;

		// I want to connect k1 to k2, so k2 should be bigger
		if(dist[head_k1] > dist[head_k2]) swap(head_k1, head_k2); // union by depth
		// if(sz[head_k1]   > sz[head_k2])   swap(head_k1, head_k2); // union by size
		
		// use one of the union heuristics, both are practically the same 
        
		if(dist[head_k1] == dist[head_k2]) dist[head_k2]++;
		sz[head_k2] += sz[head_k1];

		par[head_k1] = head_k2;
    }
    
    bool is_connected(int k1, int k2){
		return get_key(k1) == get_key(k2);
	}
};
// template ends here

void solve(){
	// code starts from here
	int N, Q;
	cin >> N >> Q;

	DSUF dsu(N);

	while(Q--){
		int t, x,y;
		cin >> t >> x >> y; 
		if(t == 0){
			dsu.merge(x,y);
		}else{
			cout << dsu.is_connected(x,y) << endl;
		}
	}
}


clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

signed main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	//startTime = clock();
	
	int T = 1;
	// cin >> T;

	while(T--){
		solve();
	}
	
	//cout << getCurrentTime() << endl;
	return 0;
}


