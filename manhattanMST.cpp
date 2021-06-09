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
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#define leftmost_bit(x)  (63-__builtin_clzll(x))
#define rightmost_bit(x) __builtin_ctzll(x) // count trailing zeros
#define set_bits(x)      __builtin_popcountll(x) 
#define pow2(i)          (1ll << (i))
#define is_on(x, i)      ((x) & pow2(i)) // state of the ith bit in x
#define set_on(x, i)     ((x) | pow2(i)) // returns integer x with ith bit on
#define set_off(x, i)    ((x) & ~pow2(i)) // returns integer x with ith bit off
  
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
const ll INF = 1e18; // not too close to llONG_MAX
const ld PI = acos((ld)-1);
const ld EPS = 1e-8;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

// highly risky #defines
#define int ll // disable when you want to make code a bit faster
#define endl '\n' // disable when dealing with interactive problems

typedef vector<int> vi;
typedef pair<int, int> pii;

class Segtree{
  private:
    vector<pair<ll,ll> >tr;
  public:
    Segtree(int n) {
        tr.resize(4 * n + 10);
        for(auto & i : tr) i.first = i.second = INF;
    }
    void updata(int x, int p, int L, int R, pair<ll,ll>num) {
        if(L == R) {
            tr[x] = min(tr[x], num); return;
        }
        int M = (L + R) / 2;
        if(p <= M) updata(x << 1, p, L, M, num);
        else updata(x << 1 | 1, p, M + 1, R, num);
        tr[x] = min(tr[x << 1], tr[x << 1 | 1]);
    }
    pair<ll,ll> query(int x, int l, int r, int L, int R) {
        if(l <= L && R <= r) {
            return tr[x];
        }
        int M = (L + R) / 2;
        pair<ll,ll> ans = {INF,INF};
        if(l <= M) ans = min(ans, query(x << 1, l, r, L, M));
        if(r > M) ans = min(ans, query(x << 1 | 1, l, r, M + 1, R));
        return ans;
    }
};
struct Point {
    int x, y, id;
    bool operator <(const Point& m) const {
        if(x == m.x) return y < m.y;
        return x < m.x;
    }
};
struct edge {
    ll u, v, w;
    bool operator<(const edge& a) const {return w < a.w;}
};
vector<vector<pii>> Kruskal(vector<edge>& e, int n) {
    vector<int> bcj;
    bcj.resize(n);
    iota(bcj.begin(), bcj.end(), 0);
    sort(e.begin(), e.end());
    function<int(int)>gr=[&](int k) {
        return k == bcj[k]?k:bcj[k] = gr(bcj[k]);
    };

    vector<vector<pii>> adj(n);

    ll ans = 0;
	int num = 0;
    for (auto& i : e) {
		int x = gr(i.u), y = gr(i.v);
        if (x != y) {
            bcj[x] = gr(y);
            ans += i.w;
            
            adj[i.u].pb({i.v, i.w});
            adj[i.v].pb({i.u, i.w});

            num++;
        }
        if (num == n - 1) break;
    }
    assert(num == n-1);

    return adj;
}
vector<vector<pii>> getMMST(vector<Point> a){
    int n = a.size();

    function<ll(Point, Point)>dis=[&](Point aa, Point bb) {
        return abs(aa.x - bb.x) + abs(aa.y - bb.y);
    };
    vector<edge>e;
    for(int i = 0; i < 4; i++) {
        if(i == 1 || i == 3) {
            for(auto & j : a) swap(j.x, j.y);
        }
        else if(i == 2) {
            for(auto & j : a) j.x = -j.x;
        }
        sort(a.begin(), a.end());
        vector<ll>b;
        for(auto& j : a) {
            b.push_back(j.y - j.x);
        }
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(), b.end()),b.end());
        function<int(ll)>getid =[&](ll u) {
            return lower_bound(b.begin(), b.end(), u) - b.begin() + 1;
        };
        int sz = b.size();
        Segtree st(sz);
        for(int j = a.size() - 1; j >= 0; j--) {
            int p = getid(a[j].y - a[j].x);
            pair<ll,ll>ans = st.query(1, p, sz, 1, sz);
            if(ans.first != INF) {
                e.push_back({a[j].id, a[ans.second].id, dis(a[j], a[ans.second])});
            }
            st.updata(1, p, 1, sz, make_pair(a[j].x + a[j].y, j));
        }
    }
    return Kruskal(e, n);
}

//https://www.programmersought.com/article/6396113136/
// NOT TESTED. USE AT YOUR OWN RISK

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    
    vector<Point>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    
    vector<vector<pii>> tree = getMMST(a);
    return 0;
}
