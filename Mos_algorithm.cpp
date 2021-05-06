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
// auto dist = uniform_int_distribution<int>(l, r);
// use int a = dist(rng) to get a random number between [l,r] inclusive

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

int v[MX];

ll ans;
int freq[1000010];

//https://codeforces.com/contest/86/problem/D
// https://codeforces.com/contest/86/submission/79050894
inline void insert(int p){
	ans += (2*freq[v[p]]+1)*(ll)v[p];
	freq[v[p]]++;
}

inline void erase(int p){
	ans -= (2*freq[v[p]]-1)*(ll)v[p];
	freq[v[p]]--;
}

ll hilbert(int x, int y) {
	static int N = (1 << 21);
	int rx, ry, s;
	ll d = 0;
	for (s = N/2; s>0; s /= 2) {
		rx = (x & s) > 0;
		ry = (y & s) > 0;
		d += s * ll(s) * ((3 * rx) ^ ry);
		if (ry == 0) {
			if (rx == 1) {
				x = N-1 - x;
				y = N-1 - y;
			}
			swap(x, y);
		}
	}
	return d;
}

vector<ll> MO(vector<pii> &q){
	ans = 0;
	int m = q.size();
	vector<int> ord(m);
	vector<ll> h(m);
	for (int i = 0; i < m; i++)
		h[i] = hilbert(q[i].first, q[i].second);// 1 based indexing for queries
	vector<ll> ret(m);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int l, int r){ return h[l] < h[r]; });
	int l = 0, r = -1;

	for (int i : ord){
		int ql, qr;
		tie(ql, qr) = q[i];
		while (r < qr) insert(++r);
		while (l > ql) insert(--l);
		while (l < ql) erase(l++);
		while (r > qr) erase(r--);
		ret[i] = ans;
	}
	return ret;
}

signed main() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> v[i];
	vector<pii> qu(q);
	for (pii& i : qu) cin >> i.first >> i.second;
	auto anss = MO(qu);
	for (ll i : anss) cout << i << endl;
	exit(0);
}