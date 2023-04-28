#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp> //required
//#include <ext/pb_ds/tree_policy.hpp> //required
// using namespace __gnu_pbds; //required
// template <typename T> using ordered_set =  tree<T, null_type, less<T>,
// rb_tree_tag, tree_order_statistics_node_update>;

// ordered_set <int> s;
// s.find_by_order(k); returns the (k+1)th smallest element
// s.order_of_key(k); returns the number of elements in s strictly less than k

#define pb push_back
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define leftmost_bit(x) (63 - __builtin_clzll(x))
#define rightmost_bit(x) __builtin_ctzll(x) // count trailing zeros
#define set_bits(x) __builtin_popcountll(x)
#define pow2(i) (1LL << (i))
#define is_on(x, i) ((x)&pow2(i))      // state of the ith bit in x
#define set_on(x, i) ((x) | pow2(i))   // returns integer x with ith bit on
#define set_off(x, i) ((x) & ~pow2(i)) // returns integer x with ith bit off
#define fi first
#define se second

typedef long long int ll;
typedef long double ld;

const int MOD = 1e9 + 7; // 998244353;
const int MX = 2e5 + 5;
const ll INF = 3e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);
const ld EPS = 1e-8;
const int dx[4] = {1, 0, -1, 0},
          dy[4] = {0, 1, 0, -1}; // for every grid problem!!

// hash map and operator overload from
// https://www.youtube.com/watch?v=jkfA0Ts6YBA Custom hash map
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
template <typename T1, typename T2> // Key should be integer type
using safe_map = unordered_map<T1, T2, custom_hash>;

// Operator overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) {
  return (istream >> p.first >> p.second);
}
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) {
  return (ostream << p.first << " " << p.second);
}

template <typename T> // cin >> array<T, 2>
istream &operator>>(istream &istream, array<T, 2> &p) {
  return (istream >> p[0] >> p[1]);
}
template <typename T> // cout << array<T, 2>
ostream &operator<<(ostream &ostream, const array<T, 2> &p) {
  return (ostream << p[0] << " " << p[1]);
}

template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v) {
  for (auto &it : v)
    cin >> it;
  return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
  for (auto &it : c)
    cout << it << " ";
  return ostream;
}
clock_t startTime;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
int getRandomNumber(int l, int r) {
  uniform_int_distribution<int> dist(l, r);
  return dist(rng);
}

// https://github.com/the-tourist/algo/blob/master/misc/debug.cpp
template <typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A> string to_string(A v) {
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
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL_DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) ;
#endif

#define int ll    // disable when you want to use atcoder library
#define endl '\n' // disable when dealing with interactive problems

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef array<int, 2>
    edge; // for graphs, make it array<int,3> for weighted edges

// #include <atcoder/all>
// using namespace atcoder;
constexpr int MAXA = 1e9;

struct line {
  int m, b;

  int eval(int x) { return m * x + b; }
};

struct node {
  line l;
  node *left_child, *right_child;

  node() {
    l = line(0, INF);
    left_child = right_child = NULL;
  }

  node(line li) {
    l = li;
    left_child = right_child = NULL;
  }

  ~node() {
    delete left_child;
    delete right_child;
    left_child = NULL;
    right_child = NULL;
  }
};

node *add(node *cur, int L, int R, line l) {
  if (cur == NULL) {
    node *ans = new node(line(l));
    return ans;
  }
  int mid = (L + R) / 2;
  if (cur->l.eval(mid) > l.eval(mid))
    swap(cur->l, l);

  if (cur->l.eval(L) <= l.eval(L) && cur->l.eval(R) <= l.eval(R))
    return cur;

  if (cur->l.eval(L) > l.eval(L)) {
    cur->left_child = add(cur->left_child, L, mid, l);
  } else {
    cur->right_child = add(cur->right_child, mid + 1, R, l);
  }

  return cur;
}

int query(node *cur, int L, int R, int p) {
  if (cur == NULL)
    return INF;
  int mid = (L + R) / 2;
  int ans = cur->l.eval(p);

  if (p <= mid)
    ans = min(ans, query(cur->left_child, L, mid, p));
  else
    ans = min(ans, query(cur->right_child, mid + 1, R, p));
  return ans;
}

void solve() {
  // https://judge.yosupo.jp/submission/136537
  // https://www.youtube.com/watch?v=-StmrE2gY44
  int N, Q;
  cin >> N >> Q;

  node *head = new node;

  for (int m, b, i = 0; i < N; i++) {
    cin >> m >> b;
    add(head, -MAXA, MAXA, line(m, b));
  }

  int p, m, b;
  for (int t, i = 0; i < Q; i++) {
    cin >> t;
    if (t == 1) {
      cin >> p;
      cout << query(head, -MAXA, MAXA, p) << endl;
    } else {
      cin >> m >> b;
      add(head, -MAXA, MAXA, line(m, b));
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // startTime = clock();

  int T = 1;
  // cin >> T;

  for (int _t = 1; _t <= T; _t++) {
    solve();
  }

  // cerr << getCurrentTime() << endl;
  return 0;
}
