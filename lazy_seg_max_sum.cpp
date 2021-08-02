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

template <typename T>
class max_segtree{
    // taken from: https://www.hackerearth.com/submission/14209722/
public:
    //int N;
    int n, h;  // array size
    vector<int> t,d;
    
    void init(){
        t.resize(2*n);
        d.resize(2*n);
        h = 5 + log2(2*n);
    }
    void build() {  // build the tree
      for (int i = n - 1; i > 0; --i)
        t[i] = max(t[i<<1], t[i<<1|1]);
    }
     
    // Range update and query
    void apply(int p, int value) {          // applying value to segment node
      t[p] += value;
      if (p < n) d[p] += value;
    }
     
    void buildup(int p) {                     // build up from a node
      while (p > 1) p >>= 1, t[p] = max(t[p<<1], t[p<<1|1]) + d[p];     // build moving up with lazy value of each node
    }
     
    void push(int p) {
      for (int s = h; s > 0; --s) {            // update h of segment tree;
        int i = p >> s;
        if (d[i] != 0) {
          apply(i<<1, d[i]);
          apply(i<<1|1, d[i]);
          d[i] = 0;
        }
      }
    }
     
    void inc(int l, int r, ll value) {
      l += n, r += n;
      int l0 = l, r0 = r;
      for (; l <= r; l >>= 1, r >>= 1) {
        if (l&1) apply(l++, value);
        if (!(r&1)) apply(r--, value);
      }
      buildup(l0);
      buildup(r0);
    }
     
    int query(int l, int r) { // both l,r inclusive
      l += n, r += n;
      push(l);
      push(r);
      int res = -2e9;
      for (; l <= r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, t[l++]);
        if (!(r&1)) res = max(t[r--], res);
      }
      return res;
    }
};

void solve(){
	// code starts from here
    int N;
    cin >> N;

    vi vec(N);
    input(vec, N);

	  max_segtree<int> st;
    st.n = 2*N;
    st.init();
    for(int i = 0; i < st.n; i++) st.t[i+st.n] = vec[i];
    st.build();

    // Usage: https://codedrills.io/submissions/158083
    //https://www.hackerrank.com/contests/praelium-2020/challenges/mutating-grid/submissions/code/1327451249
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
