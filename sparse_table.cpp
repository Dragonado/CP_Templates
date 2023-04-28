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

// template ends here
const int MAXN = 200005;
const int LOG2 = 30;

vector<int> vec;
vector<pair<int,int>> p2;

int table[MAXN][LOG2];
int N;

void preprocess(){
	for(int i = 0; i < N; i++){
		table[i][0] = vec[i];
	}
	int index = 1;
	
	int t = 2;
	while(t <= N){
		for(int i = 0; i < N-t+1; i++){
			table[i][index] = min(table[i][index-1],table[i+t/2][index-1]);
		}
		index++;
		t *= 2;
	}
	
	p2.resize(N+1);
	
	t = 1;	
	index = 0;
	for(int i = 1; i <= N; i++){
		if(i == 2*t){
			index++;
			t *= 2;
		}
		p2[i] = mp(index,t);
		
	}
	
}

int query(int l, int r){
	//return 0;
	int d = r-l+1;
	int index = p2[d].first;
	
	return min(table[l][index],table[r-p2[d].second+1][index]);
}

void solve(){
	cin >> N;
	vec.resize(N);
	input(vec,N);
	
	preprocess();
	
	vector<int> smx(N),pmx(N);
	smx.back() = vec.back();
	pmx[0] = vec[0];
	
	for(int i = 1; i < N; i++){
		pmx[i] = max(pmx[i-1],vec[i]);
	} 
	for(int i = N-2; i >= 0; i--){
		smx[i] = max(smx[i+1],vec[i]);
	}
	
	for(int b = 2; b < N; b++){
		int t = smx[b];
		
		int l = lower_bound(pmx.begin(),pmx.begin()+b-2,t)-pmx.begin();
		int r = upper_bound(pmx.begin(),pmx.begin()+b-1,t)-pmx.begin();
		
		if(l == b-1 || pmx[l] != t) continue;
		//debug(b);
		//debug(l);
		//debug(r);
		//debug(t);
		//debug(pmx[l]);
		//debug(pmx[r]);
		
		//cerr << endl;
		int low = l+1, high = r;
		int mid;
		while(low <= high){
			mid = (low+high)/2;
			
			int q = query(mid,b-1);
			//debug(mid);
			//debug(b-1);
			//debug(q);
			if(q == t){
				cout << "YES" << endl;
				cout << mid << " " << b-mid<< " " << N-b << endl;
				return;
			}
			if(q > t){
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
		
		//cerr << endl;
	}
	
	cout << "NO" << endl;
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
	cin >> T;
	//T = 1;
	while(T--){
		solve();
	}
	
	//cout << getCurrentTime() << endl;
	return 0;
}
