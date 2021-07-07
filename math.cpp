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
ll power(ll a, ll b, ll m){
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll inv(ll a, ll p){
	return power(a,p-2,p);
}

const int MAX = 2e5 + 1;
vector<ll> fact, invfact;

ll nCr(int n, int r){
	if(n < r || n < 0 || r < 0) return 0;
	ll ans = (fact[n]*invfact[r])%MOD;
	ans *= invfact[n-r];
	ans %= MOD;

	return ans;
}
vector<vector<ll> > multiply(vector<vector<ll> > &a, vector<vector<ll> > &b, ll p){
	int r1,c1,r2,c2;
	r1 = a.size(); c1 = a[0].size();
	r2 = b.size(); c2 = b[0].size();

	vector<vector<ll> > result(r1,vector<ll>(c2,0));

	if(c1 != r2) return result;

	for(int i = 0; i < r1; i++){
		for(int j = 0; j < c2; j++){
			for(int k = 0; k < c1; k++){
				result[i][j] += a[i][k]*b[k][j];
				result[i][j] %= p;
			}
		}
	}
	return result;
}
vector<vector<ll> > power(vector<vector<ll> >&a,ll n, ll p){
	int r = a.size();
	vector<vector<ll> > result(r,vector<ll>(r,0));
	for(int i = 0; i < r; i++) result[i][i] = 1;

	while(n > 0){
		if(n%2 == 1){
			result = multiply(result,a,p);
		}
		n /= 2;
		a = multiply(a,a,p);
	}
	return result;
}
// template ends here

void solve(){
	// code starts from here
	
}

signed main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	fact.resize(MAX);
	invfact.resize(MAX);

	fact[0] = invfact[0] = 1;

	for(int i = 1; i < MAX; i++){
		fact[i] = (fact[i-1]*i)%MOD;
		invfact[i] = inv(fact[i], MOD);
	}
	
	int T;
	cin >> T;
	//T = 1;
	while(T--){
		solve();
	}

	return 0;
}
