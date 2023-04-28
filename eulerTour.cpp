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
#define allr(x)          x.rbegin(), x.rend()
#define leftmost_bit(x)  (63-__builtin_clzll(x))
#define rightmost_bit(x) __builtin_ctzll(x) // count trailing zeros
#define set_bits(x)      __builtin_popcountll(x) 
#define pow2(i)          (1LL << (i))
#define is_on(x, i)      ((x) & pow2(i)) // state of the ith bit in x
#define set_on(x, i)     ((x) | pow2(i)) // returns integer x with ith bit on
#define set_off(x, i)    ((x) & ~pow2(i)) // returns integer x with ith bit off
#define fi               first
#define se               second

typedef long long int ll;
typedef long double ld;

const int MOD = 1e9+7; // 998244353;
const ll INF = 1e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);
const ld EPS = 1e-8;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

// hash map and operator overload from https://www.youtube.com/watch?v=jkfA0Ts6YBA
// Custom hash map
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2> // Key should be integer type
using safe_map = unordered_map<T1, T2, custom_hash>;
 
// Operator overloads 
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }

template<typename T> // cin >> array<T, 2>
istream& operator>>(istream &istream, array<T, 2> &p) { return (istream >> p[0] >> p[1]); }
template<typename T> // cout << array<T, 2>
ostream& operator<<(ostream &ostream, const array<T, 2> &p) { return (ostream << p[0] << " " << p[1]); }

template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v) cin >> it; return istream;}
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

ll power(ll x, ll n, ll m = MOD){
    if (x == 0 && n == 0) return 0; // undefined case
    ll res = 1;
    while (n > 0){
        if (n % 2)
            res = (res * x) % m;
        x = (x * x) % m;
        n /= 2;
    }
    return res;
}

clock_t startTime;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
double getCurrentTime()           {return (double)(clock() - startTime) / CLOCKS_PER_SEC;}
string to_string(string s)        {return '"' + s + '"';} 
string to_string(const char* s)   {return to_string((string) s);}
string to_string(bool b)          {return (b ? "true" : "false");}
int inv(int x, int m = MOD)       {return power(x, m - 2, m);}
int getRandomNumber(int l, int r) { uniform_int_distribution<int> dist(l, r); return dist(rng);}

// https://github.com/the-tourist/algo/blob/master/misc/debug.cpp
template <typename A, typename B>
string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL_DEBUG
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
	#define debug(...) ;
#endif

// highly risky #defines
#define int ll // disable when you want to make code a bit faster
#define endl '\n' // disable when dealing with interactive problems

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef array<int,2> edge; // for graphs, make it array<int,3> for weighted edges

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

const int MX = 2e5+5;
vector<int> adj[MX];
int timer = 0, tin[MX], tout[MX];

void dfs(int node, int parent) {
	tin[node] = timer++;
	for (int i : adj[node]) {
		if (i != parent) {
			dfs(i, node);
		}
	}
	tout[node] = timer-1;
}

void solve(){
	// code starts from here
	int N, Q;
    cin >> N >> Q;
    
    vi val(N); cin >> val;

    for(int u, v, i = 0; i < N-1; i++){
        cin >> u >> v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0, 0);
    segtree<int> st(N);
    for(int i = 0;i < N; i++){
        st.update(tin[i], val[i]);
    }

    for(int t, s, x, i = 0; i < Q; i++){
        cin >> t >> s;
        s--;

        if(t == 1){
            cin >> x;
            st.update(tin[s], x);
        }
        else{
            cout << st.query(tin[s], tout[s]) << endl;
        }
    }
}

signed main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	//startTime = clock();

	int T = 1;
	// cin >> T;

	for(int _t = 1; _t <= T; _t++){
		solve();
	}
	
	//cerr << getCurrentTime() << endl;
	return 0;
}
