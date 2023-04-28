#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> //required
//#include <ext/pb_ds/tree_policy.hpp> //required

<<<<<<< HEAD
// using namespace __gnu_pbds; //required
using namespace std;
// template <typename T> using ordered_set =  tree<T, null_type, less<T>,
// rb_tree_tag, tree_order_statistics_node_update>;
=======
//using namespace __gnu_pbds; //required 
using namespace std;
//template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
>>>>>>> af96ba467627664a1d8f1fac73e8602bca0eb667

// ordered_set <int> s;
// s.find_by_order(k); returns the (k+1)th smallest element
// s.order_of_key(k); returns the number of elements in s strictly less than k

<<<<<<< HEAD
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
=======
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
>>>>>>> af96ba467627664a1d8f1fac73e8602bca0eb667

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

ll power(ll x, ll n, ll m = MOD) {
  if (x == 0 && n == 0)
    return 0; // undefined case
  ll res = 1;
  while (n > 0) {
    if (n % 2)
      res = (res * x) % m;
    x = (x * x) % m;
    n /= 2;
  }
  return res;
=======
const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
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
>>>>>>> af96ba467627664a1d8f1fac73e8602bca0eb667
}

clock_t startTime;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
<<<<<<< HEAD
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
int inv(int x, int m = MOD) { return power(x, m - 2, m); }
int getRandomNumber(int l, int r) {
  uniform_int_distribution<int> dist(l, r);
  return dist(rng);
}

// https://github.com/the-tourist/algo/blob/master/misc/debug.cpp
template <typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A> string to_string(A v) {
=======
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
>>>>>>> af96ba467627664a1d8f1fac73e8602bca0eb667
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
<<<<<<< HEAD
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL_DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) ;
=======
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL_DEBUG
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
	#define debug(...) ;
>>>>>>> af96ba467627664a1d8f1fac73e8602bca0eb667
#endif

// highly risky #defines
// #define int ll // disable when you want to make code a bit faster
#define endl '\n' // disable when dealing with interactive problems

typedef vector<int> vi;
typedef pair<int, int> pii;
<<<<<<< HEAD
typedef array<int, 2>
    edge; // for graphs, make it array<int,3> for weighted edges

#include <unistd.h>
char OB[65536];
int OP;
inline char RC() {
  static char buf[65536], *p = buf, *q = buf;
  return p == q && (q = (p = buf) + read(0, buf, 65536)) == buf ? -1 : *p++;
}
inline int R() {
  static char c;
  int a;
  while ((c = RC()) < '0')
    ;
  a = c ^ '0';
  while ((c = RC()) >= '0')
    a *= 10, a += c ^ '0';
  return a;
}
inline void W1(int n) {
  static char buf[12], p;
  if (n < 0)
    OB[OP++] = '-', n *= -1;
  p = 0;
  while (n)
    buf[p++] = '0' + (n % 10), n /= 10;
  for (--p; p >= 0; --p)
    OB[OP++] = buf[p];
  OB[OP++] = ' ';
  if (OP > 65520)
    write(1, OB, OP), OP = 0;
}
inline void W2(int n) {
  static char buf[12], p;
  if (n < 0)
    OB[OP++] = '-', n *= -1;
  p = 0;
  while (n)
    buf[p++] = '0' + (n % 10), n /= 10;
  for (--p; p >= 0; --p)
    OB[OP++] = buf[p];
  OB[OP++] = '\n';
  if (OP > 65520)
    write(1, OB, OP), OP = 0;
}

void solve() {
  /*
      1. You cant use #define int ll, instead convert all occurences of 'int' to
  'll' using Ctrl + H
  2. W1 prints an integer with a space ender.
  3. W2 prints an integer with a line ender.
  4. add write(1, OB, OP) before end of program
  reference: https://codeforces.com/contest/1591/submission/138905812
  */
}

signed main() {
  int T = 1;
  T = R();

  for (int _t = 1; _t <= T; _t++) {
    solve();
  }

  write(1, OB, OP);
  return 0;
=======
typedef array<int,2> edge; // for graphs, make it array<int,3> for weighted edges

#include<unistd.h>
char OB[65536]; int OP;
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}
inline void W1(int n){static char buf[12],p;if(n<0)OB[OP++]='-',n*=-1;p=0;while(n)buf[p++]='0'+(n%10),n/=10;for(--p;p>=0;--p)OB[OP++]=buf[p];OB[OP++]=' ';if(OP>65520)write(1,OB,OP),OP=0;}
inline void W2(int n){static char buf[12],p;if(n<0)OB[OP++]='-',n*=-1;p=0;while(n)buf[p++]='0'+(n%10),n/=10;for(--p;p>=0;--p)OB[OP++]=buf[p];OB[OP++]='\n';if(OP>65520)write(1,OB,OP),OP=0;}
 

void solve(){
    /*
	1. You cant use #define int ll, instead convert all occurences of 'int' to 'll' using Ctrl + H
    2. W1 prints an integer with a space ender.
    3. W3 prints an integer with a line ender.
    4. add write(1, OB, OP) before end of program
    reference: https://codeforces.com/contest/1591/submission/138905812 
    */
}

signed main(){
	int T = 1;
    T = R();

	for(int _t = 1; _t <= T; _t++){
		solve();
	}
	
    write(1, OB, OP);
	return 0;
>>>>>>> af96ba467627664a1d8f1fac73e8602bca0eb667
}
