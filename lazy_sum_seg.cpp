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
		T add, val;
        int l,r;
        item(){
            val = add = l = 0;
			r = -1;
        }
	};
	item sentinel;// the out of range value
	vector<item> arr;//[4*MAXN]; // MAXN = 2e5
	
	T N;
	
	segtree(const T  sz){
		N = 1;
		
		while(N < sz) N <<= 1;
		arr.resize(2*N);

		for(int i = 0; i < 2*N; i++) arr[i] = sentinel;	
	}
	
	item combine(item a, item b){
		if(a.r == -1) return b;
		if(b.r == -1) return a;

		item res;

		T add = (a.r-a.l+1)*a.add + (b.r-b.l+1)*b.add;

		res.val = a.val + b.val + add;
		res.l = a.l;
		res.r = b.r;

		return res;
	}
	
	void build(vector<T> &vec,int index, int l, int r){
		arr[index].l = l;
		arr[index].r = r;

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
	
	void push_to_children(int index){
        int add = arr[index].add;

 		arr[2*index + 0].add += add;
        arr[2*index + 1].add += add;

		arr[index].val += (arr[index].r - arr[index].l + 1)*add;
		arr[index].add = 0;
	}
	// 0 based indexing for upd_index 
	void update(int index, int l, int r, int upd_l, int upd_r, T upd_add){
		if(l > upd_r || upd_l > r) return;
        if(upd_l <= l &&  r <= upd_r){
            arr[index].add += upd_add;

            return;
        }

		int m = (l+r)/2;

		push_to_children(index);
    
		update(2*index   ,l   ,m ,upd_l, upd_r, upd_add);
		update(2*index+1 ,m+1 ,r ,upd_l, upd_r, upd_add);
		
		arr[index] = combine(arr[2*index], arr[2*index+1]);
	}
	
	// 0 based indexing for upd_index
	void update(int upd_l, int upd_r, T add_val){
		update(1,0,N-1,upd_l, upd_r,add_val);
	}
	
	item query(int index, int l, int r, int lx, int rx){
		if(l > rx || lx > r) return sentinel;
		
		if(lx <= l && r <= rx){
			return arr[index];
		}
		int m = (l+r)/2;
		
		push_to_children(index);
		return combine(query(2*index,l,m,lx,rx),
		               query(2*index+1,m+1,r,lx,rx));
	}
	
	// assuming lx and rx are 0 based
	// query returns the answer in the range [lx,rx]
	// including lx and rx
	T query(int lx, int rx){
		item it = query(1,0,N-1,lx,rx);
		return it.val + (it.r-it.l + 1)*it.add;
	}
};

void solve(){
	// code starts from here

	// https://cses.fi/problemset/result/2197984/
	// https://codeforces.com/contest/1567/submission/127994390
    int N, Q;
    cin >> N >> Q;
    
    vector<int> vec(N);
    input(vec, N);

    segtree<int> st(N);
    st.build(vec);

    int t, k, a, b, u;

    while(Q--){
        cin >> t;

        if(t == 1){
            cin >> a >> b >> u;
            a--;b--;

			// cerr << "update" << endl;
            st.update(a, b, u);
        }
        else{
            cin >> k;
            k--;
			// cerr << "query" << endl;
            cout << st.query(k,k) << endl;
        }
		// cerr << endl;
    }
}

signed main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int T = 1;
	// cin >> T;
	//T = 1;
	while(T--){
		solve();
	}

	return 0;
}
