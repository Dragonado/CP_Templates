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

template <typename T>
class segtree{
public:

	struct item{
		T val;
	};
	item sentinel;// the out of range value
	vector<item> arr;//[4*MAXN]; // MAXN = 2e5
	
	T N;
	
	segtree(const T  sz){
		N = 1;
		sentinel.val = 0;
		// for sum:sentinal_val = 0, min = 1e17, max = -1e7, XOR = 0, gcd = 1

		
		while(N < sz) N <<= 1;
		arr.resize(2*N);

		for(int i = 0; i < 2*N; i++) arr[i] = sentinel;	
	}
	
	item combine(item a, item b){
		item res;
		res.val = a.val + b.val;
		
		return res;
	}
	
	void build(vector<T> &vec,int index, int l, int r){
		if(l == r){
			if(l >= (int)vec.size()) return;
			
			arr[index].val = vec[l];
			return;
		}
		int m = (l+r)/2;
		
		build(vec,2*index,l,m);
		build(vec,2*index+1,m+1,r);
		
		arr[index] = combine(arr[2*index],arr[2*index+1]);
	}
	void build(vector<T> &vec){
		build(vec,1,0,N-1);
	}
	
	// 0 based indexing for upd_index 
	void update(int index, int l, int r, int upd_index,T upd_val){
		if(l > upd_index || upd_index > r) return;
		
		if(l == r){
			arr[index].val = upd_val;
			return;
		}
		
		int m = (l+r)/2;
		
		update(2*index,l,m,upd_index,upd_val);
		update(2*index+1,m+1,r,upd_index,upd_val);
		
		arr[index] = combine(arr[2*index],arr[2*index+1]);
	}
	
	// 0 based indexing for upd_index
	void update(int upd_index, T upd_val){
		update(1,0,N-1,upd_index,upd_val);
	}
	
	item query(int index, int l, int r, int lx, int rx){
		if(l > rx || lx > r) return sentinel;
		
		if(lx <= l && r <= rx){
			return arr[index];
		}
		int m = (l+r)/2;
		
		return combine(query(2*index,l,m,lx,rx),
		               query(2*index+1,m+1,r,lx,rx));
	}
	
	// assuming lx and rx are 0 based
	// query returns the answer in the range [lx,rx]
	// including lx and rx
	T query(int lx, int rx){
		return query(1,0,N-1,lx,rx).val;
	}
};

void solve(){
	// code starts from here

}

signed main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int T;
	cin >> T;
	//T = 1;
	while(T--){
		solve();
	}

	return 0;
}
