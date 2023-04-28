#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
<<<<<<< HEAD
#include <ext/pb_ds/tree_policy.hpp>     //required

using namespace __gnu_pbds; // required
using namespace std;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
=======
#include <ext/pb_ds/tree_policy.hpp> //required

using namespace __gnu_pbds; //required 
using namespace std;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
>>>>>>> af96ba467627664a1d8f1fac73e8602bca0eb667

// ordered_set <int> s;
// s.find_by_order(k); returns the (k+1)th smallest element
// s.order_of_key(k); returns the number of elements in s strictly less than k

<<<<<<< HEAD
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
#define print(vec, l, r)                                                       \
  for (int i = l; i <= r; i++)                                                 \
    cout << vec[i] << " ";                                                     \
  cout << endl;
#define input(vec, N)                                                          \
  for (int i = 0; i < (N); i++)                                                \
    cin >> vec[i];
#define debug(x) cerr << #x << " = " << (x) << endl;
#define leftmost_bit(x) (63 - __builtin_clzll(x))
#define rightmost_bit(x) __builtin_ctzll(x) // count trailing zeros
#define set_bits(x) __builtin_popcountll(x)
#define is_on(x, i) ((x)&pow2(i))      // state of the ith bit in x
#define set_on(x, i) ((x) | pow2(i))   // returns integer x with ith bit on
#define set_off(x, i) ((x) & ~pow2(i)) // returns integer x with ith bit off

=======
#define pb(x)            push_back(x)
#define mp(x,y)          make_pair(x,y)
#define all(x)           x.begin(), x.end()
#define print(vec,l,r)   for(int i = l; i <= r; i++) cout << vec[i] <<" "; cout << endl;
#define input(vec,N)     for(int i = 0; i < (N); i++) cin >> vec[i];
#define debug(x)         cerr << #x << " = " << (x) << endl;
#define leftmost_bit(x)  (63-__builtin_clzll(x))
#define rightmost_bit(x) __builtin_ctzll(x) // count trailing zeros
#define set_bits(x)      __builtin_popcountll(x) 
#define is_on(x, i)      ((x) & pow2(i)) // state of the ith bit in x
#define set_on(x, i)     ((x) | pow2(i)) // returns integer x with ith bit on
#define set_off(x, i)    ((x) & ~pow2(i)) // returns integer x with ith bit off
  
>>>>>>> af96ba467627664a1d8f1fac73e8602bca0eb667
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// auto dist = uniform_int_distribution<int>(l, r);
// use int a = dist(rng) to get a random number between [l,r] inclusive

typedef long long int ll;
typedef long double ld;

<<<<<<< HEAD
const int MOD = 1e9 + 7; // 998244353;
const int MX = 2e5 + 5;
const ll INF = 1e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);
const ld EPS = 1e-8;
const int dx[4] = {1, 0, -1, 0},
          dy[4] = {0, 1, 0, -1}; // for every grid problem!!

// highly risky #defines
#define int ll    // disable when you want to make code a bit faster
=======
const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);
const ld EPS = 1e-8;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

// highly risky #defines
#define int ll // disable when you want to make code a bit faster
>>>>>>> af96ba467627664a1d8f1fac73e8602bca0eb667
#define endl '\n' // disable when dealing with interactive problems

typedef vector<int> vi;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

// for usage: https://www.codechef.com/viewsolution/46063535
<<<<<<< HEAD
class tree_dc { // tree divide and conquer
private:
  vector<vi> adj; // you may use vector<set<int>> adj but much slower
  vector<bool>
      rem; // this should be commented if you are using set<int> adj[MAXN]
  vi subtree_cnt; // subtree_cnt[u] gives number nodes in subtree of u
  int N;

  void dfs(int root, int par = 0) {
    assert(rem[root] == false);
    subtree_cnt[root] = 1;

    for (int ne : adj[root]) {
      if (ne == par || rem[ne])
        continue;
      dfs(ne, root);

      subtree_cnt[root] += subtree_cnt[ne];
    }
  }

  void reRoot(int old_root, int new_root) {
    int t1 = subtree_cnt[old_root];
    int t2 = subtree_cnt[new_root];

    subtree_cnt[old_root] -= t2;
    subtree_cnt[new_root] += (t1 - t2);
  }

  int getCentroid(int root) {
    assert(rem[root] == false); // its not removed

    int centroid = root;

    for (int ne : adj[root]) {
      if (rem[ne])
        continue;
      if (subtree_cnt[ne] <= subtree_cnt[root] / 2)
        continue;

      reRoot(root, ne);
      centroid = getCentroid(ne);
      break;
    }

    return centroid;
  }

  void removeCentroid(int centroid) {
    // if you are using vector<set<int>> adj use below
    // for(int ne: adj[centroid]){
    //     adj[ne].erase(centroid);
    // }
    rem[centroid] = true;
  }

public:
  tree_dc(int N = 0) {
    this->N = N;

    adj.resize(N + 1);
    subtree_cnt.assign(N + 1, 0);
    rem.assign(N + 1, false);
  }

  void init(int N) {
    this->N = N;

    adj.resize(N + 1);
    subtree_cnt.assign(N + 1, 0);
    rem.assign(N + 1, false);
  }

  void add_edge(int u,
                int v) { // 1 based indexing, adding weight to edges can be done
    assert(u > 0 && v > 0 && u <= N && v <= N && u != v);
    adj[u].pb(v);
    adj[v].pb(u);
  }

  void build() {
    dfs(1); // initial root doesnt matter so it can be anything
  }

  // modify below code for your problem
  void dfs2(int root, int par, int depth, vi &v) {
    assert(rem[root] == false);

    depth++;
    v.pb(depth);

    for (int ne : adj[root]) {
      if (rem[ne] || ne == par)
        continue;

      dfs2(ne, root, depth, v);
    }
  }

  // modify below code for your problem
  int getAnswer(int temp_root) {
    int centroid = getCentroid(temp_root); // O(N)
    int ans = 0;

    // merging step
    // capture all answers that involve the centroid in O(N) or O(NlogN) where N
    // = subtree_cnt[centroid] add your code here
    for (int ne : adj[centroid]) {
      if (rem[ne])
        continue;

      vi v;
      dfs2(ne, centroid, 0, v); // usually a 2nd dfs is done to capture answers
    }

    // Conquering step, done need to change below step
    removeCentroid(centroid);
    for (int ne : adj[centroid]) {
      if (rem[ne])
        continue;
      ans += getAnswer(ne);
      // if(ans >= MOD) ans -= MOD; if needed
    }

    return ans;
  }
};

void solve() {
  // code starts from here
  int N;
  cin >> N;

  tree_dc tree(N);
  for (int i = 1; i <= N - 1; i++) {
    int u, v;
    cin >> u >> v; // 1 based indexing
    tree.add_edge(u, v);
  }

  tree.build();

  // cout << tree.getAnswer(1) << endl;
}

clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // startTime = clock();
  //  mt19937_64 rnd(time(NULL));
  int T = 1;
  cin >> T;

  while (T--) {
    solve();
  }

  // cerr << getCurrentTime() << endl;
  return 0;
=======
class tree_dc{ // tree divide and conquer
private:
    vector<vi> adj; // you may use vector<set<int>> adj but much slower
    vector<bool> rem; // this should be commented if you are using set<int> adj[MAXN]
    vi subtree_cnt; // subtree_cnt[u] gives number nodes in subtree of u
    int N;

    void dfs(int root, int par = 0){
        assert(rem[root] == false);
        subtree_cnt[root] = 1;
        
        for(int ne: adj[root]){
            if(ne == par || rem[ne]) continue;
            dfs(ne, root);

            subtree_cnt[root] += subtree_cnt[ne];
        }
    }

    void reRoot(int old_root, int new_root){
        int t1 = subtree_cnt[old_root];
        int t2 = subtree_cnt[new_root];
        
        subtree_cnt[old_root] -= t2;
        subtree_cnt[new_root] += (t1-t2);
    }

    int getCentroid(int root){
        assert(rem[root] == false); // its not removed
        
        int centroid = root; 

        for(int ne: adj[root]){
            if(rem[ne]) continue;
            if(subtree_cnt[ne] <= subtree_cnt[root]/2) continue;

            reRoot(root, ne);
            centroid = getCentroid(ne);
            break;
        }

        return centroid;
    }   

    void removeCentroid(int centroid){
        // if you are using vector<set<int>> adj use below
        // for(int ne: adj[centroid]){
        //     adj[ne].erase(centroid);
        // }
        rem[centroid] = true;
    }

public:

    tree_dc(int N = 0){
        this->N = N;

        adj.resize(N+1);
        subtree_cnt.assign(N+1, 0);
        rem.assign(N+1, false);
    }
   
    void init(int N){
        this->N = N;

        adj.resize(N+1);
        subtree_cnt.assign(N+1, 0);
        rem.assign(N+1, false);
    }
   
    void add_edge(int u, int v){ // 1 based indexing, adding weight to edges can be done
        assert(u > 0 && v > 0 && u <= N && v <= N && u != v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
  
    void build(){
        dfs(1); // initial root doesnt matter so it can be anything
    }

     // modify below code for your problem
    void dfs2(int root, int par,int depth, vi &v){
        assert(rem[root] == false);

        depth++;
        v.pb(depth);

        for(int ne: adj[root]){
            if(rem[ne] || ne == par) continue;

            dfs2(ne, root, depth, v);
        }
    }

    // modify below code for your problem
    int getAnswer(int temp_root){ 
        int centroid = getCentroid(temp_root); // O(N)
        int ans = 0; 

        // merging step
        // capture all answers that involve the centroid in O(N) or O(NlogN) where N = subtree_cnt[centroid]
        // add your code here
        for(int ne: adj[centroid]){
            if(rem[ne]) continue;

            vi v;
            dfs2(ne, centroid, 0, v); // usually a 2nd dfs is done to capture answers
        }



        // Conquering step, done need to change below step
        removeCentroid(centroid);
        for(int ne: adj[centroid]){
            if(rem[ne]) continue;
            ans += getAnswer(ne);
            // if(ans >= MOD) ans -= MOD; if needed
        }

        return ans;
    }
};


void solve(){
	// code starts from here
	int N;
    cin >> N;

    tree_dc tree(N);
    for(int i = 1; i <= N-1; i++){
        int u, v;
        cin >> u >> v; // 1 based indexing
        tree.add_edge(u, v);
    }

    tree.build();

    // cout << tree.getAnswer(1) << endl;
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
>>>>>>> af96ba467627664a1d8f1fac73e8602bca0eb667
}
