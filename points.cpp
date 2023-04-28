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

/**
 * https://github.com/kth-competitive-programming/kactl/blob/master/content/geometry/Point.h
 * Author: Ulf Lundstrom
 * Date: 2009-02-26
 * License: CC0
 * Source: My head with inspiration from tinyKACTL
 * Description: Class to handle points in the plane.
 * 	T can be e.g. double or long long. (Avoid int.)
 * Status: Works fine, used a lot
 */
// #pragma once

#define double long double
const double pi = acos(-1);
/**
 * https://github.com/kth-competitive-programming/kactl/blob/master/content/geometry/Point.h
 * Author: Ulf Lundstrom
 * Date: 2009-02-26
 * License: CC0
 * Source: My head with inspiration from tinyKACTL
 * Description: Class to handle points in the plane.
 * 	T can be e.g. double or long long. (Avoid int.)
 * Status: Works fine, used a lot
 */
// #pragma once

template<typename T>
struct Point {
    T x, y;
    Point(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    template<typename S> Point(const Point<S> &p) : x((T) p.x), y((T) p.y) {}
    Point operator + (const Point &other) const {return Point(x + other.x, y + other.y);}
    Point operator - (const Point &other) const {return Point(x - other.x, y - other.y);}
    Point operator * (T c) const {return Point(x * c, y * c);}
    Point operator / (T c) const {return Point(x / c, y / c);}
    Point& operator += (const Point &other) {return *this = *this + other;}
    Point& operator -= (const Point &other) {return *this = *this - other;}
    Point& operator *= (T c) {return *this = *this * c;}
    Point& operator /= (T c) {return *this = *this / c;}
    bool operator < (const Point &other) const {return tie(x, y) < tie(other.x, other.y);}
    bool operator <= (const Point &other) const {return tie(x, y) <= tie(other.x, other.y);}
    bool operator > (const Point &other) const {return tie(x, y) > tie(other.x, other.y);}
    bool operator >= (const Point &other) const {return tie(x, y) >= tie(other.x, other.y);}
    bool operator == (const Point &other) const {return tie(x, y) == tie(other.x, other.y);}
    bool operator != (const Point &other) const {return tie(x, y) != tie(other.x, other.y);}
    T mag2() const {return x * x + y * y;}
    double mag() const {return sqrtl(mag2());}
    Point unit() const {return *this / mag();}
    Point perp() const {return Point(-y, x);}
    Point normal() const {return perp().unit();}
    double angle() const {return atan2(y, x);}
    Point rot(double ang) const {return Point(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang));}
    friend T dot(const Point &a, const Point &b) {return a.x * b.x + a.y * b.y;}
    friend T cross(const Point<T> &a, const Point<T> &b) {return a.x * b.y - a.y * b.x;}
    friend T dist2(const Point<T> &a, const Point<T> &b) {return (a - b).mag2();}
    friend double dist(const Point<T> &a, const Point<T> &b) {return (a - b).mag();}
    friend T ccw(const Point<T> &a, const Point<T> &b, const Point<T> &o) {return cross(a - o, b - o);}
    friend double angle(const Point<T> &a, const Point<T> &b) {return abs(atan2(cross(a, b), dot(a, b)));}
    friend Point<T> rot(const Point<T> &p, const Point<T> &o, double ang) {return o + (p - o).rot(ang);}
    friend ostream& operator << (ostream &os, const Point &p) {return os << "(" << p.x << ", " << p.y << ")";}
    friend istream& operator >> (istream &istream, Point<T> &p){cin >> p.x >> p.y; return istream;}
};


typedef Point<int> P;

// position of p3 relative to line going through p1->p2
// if sgn == 1: p3 is LEFT
// else if sgn == 0: then p3 touching the line
// else if sgn == -1: p3 is RIGHT
int toLeftSign(const P &p1, const P &p2, const P &p3){
    int sgn = (p3.y-p1.y)*(p2.x-p1.x) - (p2.y-p1.y)*(p3.x-p1.x);
    if(sgn < 0) return -1;
    else if(sgn == 0) return 0;
    else return 1;
}

// gives the 2*signed area of triangle formed by p1, p2, p3
int getDoubleTriangleArea(const P &p1, const P &p2, const P &p3){
    int area = p1.x*(p2.y-p3.y) - p1.y*(p2.x-p3.x) + 1*(p2.x*p3.y - p2.y*p3.x);
    return area; 
}

// returns the 2*unsigned area of the polygon, vec should have adjacent vertices
int getDoublePolygonArea(const vector<P> &vec){
	assert(vec.size() > 2);
	if(vec.size() == 3) return getDoubleTriangleArea(vec[0], vec[1], vec[2]);

	int ans = 0, N = vec.size();
	P origin(0, 0);
	
	for(int i = 0; i < N; i++){
		ans += getDoubleTriangleArea(vec[i], vec[(i+1)%N], origin);
	}
	return abs(ans);
}


void solve(){
	// code starts from here
	int N;
	cin >> N;

	Point<double> p0, pn2;
	cin >> p0.x >> p0.y;
	cin >> pn2.x >> pn2.y;

	double theta = pi*(N-2); // angle between any two adjacent sides
	theta /= N;

	Point temp = p0-pn2;
	double d = temp.mag();
	double l, s= 0;
	
	int n = N/2;
	s = 1.0/cos(theta/2)*sin(n*(pi-theta)/2.0)*sin(n*(pi-theta)/2.0);
	// double a = theta/2;

	// for(int i = 0; i < N/2; i++){
	// 	s += cos(a);
	// 	a = (theta+a-pi);
	// }
	
	l = d/s;

	Point<double> p1(l*cos(theta/2), -l*sin(theta/2));
	// cout << setprecision(10) << s << " " <<  l << endl;

	double phi = acos((pn2.x -p0.x)/d);
	if(phi < 0) phi += pi;
	p1 = p1.rot(phi);
	p1 = p1 + p0;
	cout << setprecision(20) << p1.x << " " << p1.y << endl;
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
}
