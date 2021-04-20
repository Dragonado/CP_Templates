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

const int N = 3e5 + 10;
const int MX = 1e9 + 10;
const int LOGN = 32;
int L[N * LOGN], R[N * LOGN], ST[N * LOGN], blen, root[N];

class path_copying_segtree {
public:
    // sparse persistent-segtree. range sum, initially 0
    path_copying_segtree(){
        blen = 0;
    }

    int update(int pos, int add, int l, int r, int id) {
        if (l > pos || r <= pos) return id;
        int ID = ++blen, m = l + (r - l) / 2;
        if (l == r - 1) return (ST[ID] = ST[id] + add, ID);
        L[ID] = update(pos, add, l, m, L[id]);
        R[ID] = update(pos, add, m, r, R[id]);
        return (ST[ID] = ST[L[ID]] + ST[R[ID]], ID);
    }

    void update(int A[], int n) {
        root[0] = ++blen;
        for (int i = 1; i <= n; i++) root[i] = update(A[i], 1, 1, MX, root[i - 1]);
    }

    int query(int qL, int qR, int l, int r, int x) {
        if (!x || r <= qL || qR <= l) return 0;
        if (l >= qL && r <= qR) return ST[x];
        int m = l + (r - l) / 2;
        return query(qL, qR, l, m, L[x]) + query(qL, qR, m, r, R[x]);
    }

    int query(int l, int r, int k) {
        return query(k + 1, MX, 1, MX, root[r]) -
            query(k + 1, MX, 1, MX, root[l - 1]);
    }
} ; // namespace path_copying_segree


void solve(){
	// usage: https://pastebin.com/WM816gtu
	// problem: https://www.spoj.com/problems/KQUERY/
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
