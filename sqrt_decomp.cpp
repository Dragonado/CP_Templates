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

#define MOD            (1000000000+7) // change as required
#define pb(x)          push_back(x)
#define mp(x,y)        make_pair(x,y)
#define all(x)         x.begin(), x.end()
#define print(vec,l,r) for(int i = l; i <= r; i++) cout << vec[i] <<" "; cout << endl;
#define input(vec,N)   for(int i = 0; i < (N); i++) cin >> vec[i];
#define debug(x)       cerr << #x << " = " << (x) << endl;

typedef long long int ll;

// start of highly risky #defines

#define int ll // disable when you want to make code a bit faster
#define endl '\n' // disable when dealing with interactive problems

// End of highly risky #defines

// template ends here

const int MAXN = 30000;
const int BLOCK_SIZE = 200; // ~ sqrt(MAXN)
// always choose BLOCK_SIZE > sqrt(N)

vector<vector<int>> vec(BLOCK_SIZE);
vector<int> v;

int f(int R, int K){
	if(R < 0) return 0;
	
	int index = R/BLOCK_SIZE;
	assert(index < BLOCK_SIZE);
	
	int cnt = 0;
	
	for(int i = 0; i < index; i++){ // sqrt(N)
		auto it = lower_bound(all(vec[i]),K+1);  //log(sqrt(N))
		cnt += (vec[i].end()-it);
	}
	
	for(int i = index*BLOCK_SIZE; i <= R; i++){ // sqrt(N)
		if(v[i] > K) cnt++;
	}
	return cnt;
}

void solve(){
	// code starts from here
	int n;
	cin >> n;
	
	v.resize(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
		
		assert(i/BLOCK_SIZE < BLOCK_SIZE);
		vec[i/BLOCK_SIZE].pb(v[i]);
	}
	
	for(int i = 0; i < BLOCK_SIZE; i++) sort(all(vec[i]));
	
	int Q;
	cin >> Q;
	while(Q--){
		int l,r,k;
		cin >> l >> r >> k;
		
		l--;r--;
		cout << f(r,k)-f(l-1,k) << endl;
	}
	
}


clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

signed main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	//startTime = clock();
	
	int T;
	//cin >> T;
	T = 1;
	while(T--){
		solve();
	}
	
	//cout << getCurrentTime() << endl;
	return 0;
}
