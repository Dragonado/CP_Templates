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
const ll INF = 4e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);
const ld EPS = 1e-8;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

// highly risky #defines
#define int ll // disable when you want to make code a bit faster
#define endl '\n' // disable when dealing with interactive problems

typedef vector<int> vi;
typedef pair<int, int> pii;

// Nlog^2N
class min_perimeter{
    vector<pii> points;

public:
    min_perimeter(vector<pii> points = {}){
        this->points = points;
        sort(all(this->points));// sorting by X
    }

    static bool cmpY(const pii & a, const pii & b) {
        return a.second < b.second;
    }

    ld dist(int i, int j, vector<pii> &points){
        int x = points[i].first - points[j].first;
        int y = points[i].second - points[j].second;

        ld d = x*x + y*y;
        return sqrt(d);
    }


    ld getPerimeter(int i, int j,int k,vector<pii> &v){
        ld d1 = dist(i, j, v);
        ld d2 = dist(j, k, v);
        ld d3 = dist(k, i, v);
        return d1 + d2 + d3;
    }

    void merge(vector<pii> &v1, vector<pii> &v2, ld &p){ 
        vector<pii> v;

        ld mid = (v1.back().first + v2[0].first)/2.0;
        for(pii i: v1) if(abs(mid-i.first) <= p/2.0) v.pb(i);
        for(pii i: v2) if(abs(mid-i.first) <= p/2.0) v.pb(i);

        int n = v.size();
        sort(all(v), cmpY);

        for(int i = 0; i < n; i++){

            // below block is actually O(1)
            // p x (p/2) block
            for(int j = i+1; j < n; j++){
                if(dist(i, j, v) > p) break;   
                // I thought making dist(i, j, v) > p/2.0 would work but that gives WA for some reason

                for(int k = j+1; k < n; k++){
                    if(dist(i, k, v) > p) break;
                    p = min(p, getPerimeter(i, j, k , v));
                }
            }
        }
    }
    ld getMinPerimeter(vector<pii> &pts){
        int n = pts.size();

        if(n <= 2) return INF;

        vector<pii> v1, v2;
        for(int i = 0; i < n/2; i++) v1.pb(pts[i]);
        for(int i = n/2; i < n; i++) v2.pb(pts[i]);

        ld p = min(getMinPerimeter(v1), getMinPerimeter(v2));

        merge(v1, v2, p);
        return p;
    }
    ld getMinPerimeter(){ return getMinPerimeter(points);}
};

// https://codingcompetitions.withgoogle.com/codejam/round/0000000000432ad5/0000000000433195
// CodeJam 2009 Finals, 2nd problem

void solve(){
	// code starts from here
	int N;
    cin >> N;

    vector<pii> points(N);
    for(int i = 0; i < N; i++) cin >> points[i].first >> points[i].second;
    
    min_perimeter peri(points);

    cout << setprecision(20) << fixed << peri.getMinPerimeter() << endl;
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

	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
        solve();
	}
	
	//cerr << getCurrentTime() << endl;
	return 0;
}
