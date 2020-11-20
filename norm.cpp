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

void solve(){
	// code starts from here
	
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
