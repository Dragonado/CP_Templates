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

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }

    friend istream& operator>>(istream &istream, P &p){cin >> p.x >> p.y; return istream;}
};

// position of p3 relative to line going through p1->p2
// if sgn == 1: p3 is LEFT
// else if sgn == 0: then p3 touching the line
// else if sgn == -1: p3 is RIGHT
int toLeftSign(const Point<int> &p1, const Point<int> &p2, const Point<int> &p3){
    int sgn = (p3.y-p1.y)*(p2.x-p1.x) - (p2.y-p1.y)*(p3.x-p1.x);
    if(sgn < 0) return -1;
    else if(sgn == 0) return 0;
    else return 1;
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
	double d = temp.dist();
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
	p1 = p1.rotate(phi);
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
