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
		vector<pair<int,int>> val;
	};
	
	T sentinel_val;// the out of range value
	vector<item> arr;//[4*MAXN]; // MAXN = 2e5
	
	T N;
	
	segtree(const T  sz){
		N = 1;
		sentinel_val = 0;
		// for sum:sentinal_val = 0, min = 1e17, max = -1e7, XOR = 0, gcd = 1

		
		while(N < sz) N <<= 1;
		arr.resize(2*N);

		for(int i = 0; i < 2*N; i++) arr[i].val.pb(mp(0,sentinel_val));	
	}
	
	T combine(T a, T b){
		return a+b; // for sum
	}
	// 0 based indexing for upd_index 
	void update(int index, int l, int r, int upd_index,T upd_val, int _time){
		if(l > upd_index || upd_index > r) return;
		
		if(l == r){
			arr[index].val.pb(mp(_time,upd_val));
			return;
		}
		
		int m = (l+r)/2;
		
		update(2*index,l,m,upd_index,upd_val, _time);
		update(2*index+1,m+1,r,upd_index,upd_val, _time);
		
		int s = arr[2*index].val.back().second + arr[2*index + 1].val.back().second;
		
		arr[index].val.pb(mp(_time,s));
	}
	
	// 0 based indexing for upd_index
	void update(int upd_index, T upd_val, int _time){
		update(1,0,N-1,upd_index,upd_val, _time);
	}
	
	int get_ans(int _time, vector<pair<int,int>> &v){
		int low = 0, high = (int)v.size()-1;
		int ans = -1, mid;
		
		while(low <= high){
			mid = (low+high)/2;
			if(v[mid].first <= _time){
				ans = v[mid].second;
				low = mid+1;
			}
			else high = mid-1;
		}
		
		assert(ans != -1);
		return ans;
	}
	
	T query(int index, int l, int r, int lx, int rx, int _time){
		if(l > rx || lx > r) return sentinel_val;
		
		if(lx <= l && r <= rx){
			return get_ans(_time,arr[index].val);
		}
		int m = (l+r)/2;
		
		return combine(query(2*index,l,m,lx,rx,_time),
						query(2*index+1,m+1,r,lx,rx,_time));
	}
	
	// assuming lx and rx are 0 based
	// query returns the answer in the range [lx,rx]
	// including lx and rx
	T query(int lx, int rx, int _time){
		return query(1,0,N-1,lx,rx, _time);
	}
};



void solve(){
	// code starts from here
	int N;
	cin >> N;
	vector<pair<int,int>> v(N);
	
	#define endl '\n'
	
	vector<int> freq(N+1, 0), vec(N,-1);
	for(int i = 0; i < N; i++){
		cin >> v[i].first;
		v[i].second = i;
	}
	
	sort(all(v));
	int cur = 0;
	vec[v[0].second] = cur;
	
	map<int,int> mp;
	
	for(int i = 1; i < N; i++){
		if(v[i].first != v[i-1].first) cur++;
		mp[v[i].first] = cur;
		
		vec[v[i].second] = cur;
	}
	
	segtree<int> s(N);
	
	for(int i = 0; i < N; i++){
		freq[vec[i]]++;
		s.update(vec[i],freq[vec[i]],i+1);
	}
	
	int Q;
	cin >> Q;
	while(Q--){
		int l,r,K;
		cin >> l >> r >> K;
		
		if(K >= v.back().first){
			cout << 0 << endl;
			continue;
		}
		if(K < v[0].first){
			cout << r-l+1 << endl;
			continue;
		}
		
		int low = 0, high = N-1;
		int ans = -1,mid;
		
		while(low <= high){
			mid = (low+high)/2;
			
			if(v[mid].first <= K){
				low = mid+1;
				ans = mp[v[mid].first];
			}
			else high = mid-1;
		}
		
		assert(ans != -1);
		
		int k = ans;
				
		//ll f = [&](int R){
			//if(R < 0) return 0;
			
			//ilt sum = s.query(k+1,N,R);
			//return sum;
		//};
		
		//cout << f(r)-f(l-1) << endl;
	}
}

signed main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int T;
	//cin >> T;
	T = 1;
	while(T--){
		solve();
	}

	return 0;
}
