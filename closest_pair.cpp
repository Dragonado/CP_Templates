#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

//#include <ext/pb_ds/assoc_container.hpp> //required
//#include <ext/pb_ds/tree_policy.hpp> //required

//using namespace __gnu_pbds; //required 
using namespace std;
//template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

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
#define rightmost_bit(x) __builtin_ctzll(x) // count trailing zeros
#define set_bits(x)      __builtin_popcountll(x) 
#define pow2(i)          (1LL << (i))
#define is_on(x, i)      ((x) & pow2(i)) // state of the ith bit in x
#define set_on(x, i)     ((x) | pow2(i)) // returns integer x with ith bit on
#define set_off(x, i)    ((x) & ~pow2(i)) // returns integer x with ith bit off
  
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long int ll;

// highly risky #defines
#define int ll // disable when you want to make code a bit faster
#define endl '\n' // disable when dealing with interactive problems
#define ld long double

struct pt {
    int x, y, id;
};

bool cmp_x(const pt & a, const pt & b){
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmp_y(const pt & a, const pt & b) {
    return a.y < b.y;
}


const int INF = 1e18;
int N;
vector<pt> temp;

int eval(pair<int,int> p){
    if(p.first == -1 || p.second == -1) return INF;
    assert(p.first < N && p.second < N);

    pt point1 = temp[p.first];
    pt point2 = temp[p.second];
    int ans = (point1.x-point2.x)*(point1.x-point2.x);
    
    ans += (point1.y-point2.y)*(point1.y-point2.y);
    return ans;
}   

pair<int,int> merge(vector<pt> &v1, vector<pt> &v2, int deltaSq, int mid){
    vector<pt> v;
    for(pt i: v1) if(abs(mid-i.x)*(mid-i.x) <= deltaSq) v.pb(i);
    for(pt i: v2) if(abs(mid-i.x)*(mid-i.x) <= deltaSq) v.pb(i);
    
    sort(all(v), cmp_y);

    int n =v.size();

    pair<int,int> ans = mp(-1,-1);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < i+16; j++){
            if(j == n) break;

            pair<int,int> t = mp(v[i].id, v[j].id);
            if(eval(ans) > eval(t)) ans = t;
        }
    }

    return ans;
}

pair<int,int> solve(vector<pt> &v){
    int n = v.size();

    assert(n != 0);
    if(n == 1) return mp(v[0].id,-1);

    vector<pt> v1, v2;
    for(int i = 0; i < n/2; i++) v1.pb(v[i]);
    for(int i = n/2; i < n; i++) v2.pb(v[i]);

    pair<int,int> p1 = solve(v1);
    pair<int,int> p2 = solve(v2);

    int e1 = eval(p1), e2 = eval(p2);

    int deltaSq = min(e1, e2);
    pair<int,int> p3 = merge(v1, v2, deltaSq, v[n/2].x);

    int e3 = eval(p3);

    if(e1 < e2 && e1 < e3) return p1;
    else if(e2 < e1 && e2 < e3) return p2;
    else return p3;
}

signed main(){    
    cin >> N;
    
    vector<pt> vec(N);
    temp.resize(N);

    for(int i = 0; i < N; i++){
        cin >> vec[i].x >> vec[i].y;
        vec[i].id = i;
        temp[i] = vec[i];
    }

    sort(all(vec), cmp_x);

    pair<int,int> ans = solve(vec);
    if(ans.first > ans.second) swap(ans.first, ans.second);
    cout << setprecision(6) << fixed << ans.first << " " << ans.second << " " << sqrt(eval(ans)) << endl;
    return 0;
}
