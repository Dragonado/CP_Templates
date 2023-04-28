#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> //required
//#include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; //required
using namespace std;
// template <typename T> using ordered_set =  tree<T, null_type, less<T>,
// rb_tree_tag, tree_order_statistics_node_update>;

// ordered_set <int> s;
// s.find_by_order(k); returns the (k+1)th smallest element
// s.order_of_key(k); returns the number of elements in s strictly less than k

#define pb push_back
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
#define print(vec, l, r)                                                       \
  for (int i = l; i <= r; i++)                                                 \
    cout << vec[i] << " ";                                                     \
  cout << endl;
#define input(vec, N)                                                          \
  for (int i = 0; i < (N); i++)                                                \
    cin >> vec[i];
#define leftmost_bit(x) (63 - __builtin_clzll(x))
#define rightmost_bit(x) __builtin_ctzll(x) // count trailing zeros
#define set_bits(x) __builtin_popcountll(x)
#define pow2(i) (1LL << (i))
#define is_on(x, i) ((x)&pow2(i))      // state of the ith bit in x
#define set_on(x, i) ((x) | pow2(i))   // returns integer x with ith bit on
#define set_off(x, i) ((x) & ~pow2(i)) // returns integer x with ith bit off

#ifdef LOCAL_DEBUG
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) ;
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// auto dist = uniform_int_distribution<int>(l, r);
// use int a = dist(rng) to get a random number between [l,r] inclusive
template <typename... Args> void logger(string vars, Args &&...values) {
  cerr << vars << " = ";
  string delim = "";
  (..., (cerr << delim << values, delim = ", "));
  cerr << endl;
}

typedef long long int ll;
typedef long double ld;

const int MOD = 1e9 + 7; // 998244353;
const int MX = 2e5 + 5;
const ll INF = 1e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);
const ld EPS = 1e-8;
const int dx[4] = {1, 0, -1, 0},
          dy[4] = {0, 1, 0, -1}; // for every grid problem!!

// highly risky #defines
// #define int ll // disable when you want to make code a bit faster
#define endl '\n' // disable when dealing with interactive problems

typedef vector<int> vi;
typedef pair<int, int> pii;

const int MAXQ = 1 + 1e5;
const int MAXN = 1 + 1e5;
int lo[MAXQ], hi[MAXQ], ans[MAXQ];

vector<int> vec[MAXN];
// vec[mid] holds the value of all queries whose (lo[i] + hi[i])/2 = mid

int N, Q;

void clear() { // reset
               // reset your data strucutres used. Not low,mid,hi or ans
}

void apply(int idx) { // Apply ith update/query
}

bool possible(int idx) { // Check if the condition is satisfied
}

void work() {
  for (int i = 0; i < N; i++)
    vec[i].clear();
  for (int i = 0; i < Q; i++) {
    if (lo[i] <= hi[i])
      vec[(lo[i] + hi[i]) / 2].pb(i);
  }

  clear();
  for (int mid = 0; mid < N; mid++) {
    apply(mid);                // apply the mid-th update
    for (int ind : vec[mid]) { // Add appropriate check conditions

      if (possible(ind)) { // is the answer possible after performing the first
                           // mid updates
        ans[ind] = mid;    // change as needed
        hi[ind] = mid - 1;
      } else
        lo[ind] = mid + 1;
    }
  }
}

void parallel_binary() {
  for (int i = 0; i < Q; i++) {
    lo[i] = 0;
    hi[i] = N - 1;
    ans[i] = -1; // impossible case
  }

  bool changed = true;
  while (changed) { // O(logN)
    changed = false;

    for (int i = 0; i < Q; i++) {
      if (lo[i] <= hi[i]) {
        changed = true;
      }
    }
    work(); // O((N + Q)*cost of data structure)
  }
}

void solve() {
  // code starts from here
  // https://pastebin.com/2PAh5pMe
  // check here for implementation

  // Given N updates and Q queries. You know that for a particular query,
  // f(query, i) becomes true after the ith update.
  // YOu want to find the first i such that f(query, i) is true.

  // So for a single query we can binary search on the answer and perform
  // updates one by one. This techinque called parallel binary search does it
  // for all queries with logK factor
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
}
