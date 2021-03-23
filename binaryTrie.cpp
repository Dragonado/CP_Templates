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
#define num_of_bits 20

const int MAXN = (1<< num_of_bits);
vector<int> tree(2*MAXN, 0);

void insert(int t, int index = 0, int bit = num_of_bits-1){
    tree[index]++;
    
    if(bit < 0) return; // leaf

    if(t & (1LL << bit)){ // go right
        insert(t, 2*index + 2, bit-1);
    }
    else{ // go left
        insert(t, 2*index + 1, bit-1);
    }
}

int cnt(int t, int K, int index = 0, int bit = num_of_bits-1){
    if(bit < 0) return tree[index]; // XOR is equal to K

    int p2 = (1<<bit);

    bool y1 = (t & p2);
    bool y2 = (K & p2);
    int ans = 0;

    if(y1 == true && y2 == true){
        ans = cnt(t, K, 2*index + 1, bit-1); // only hope is to go left
    }

    else if(y1 == true && y2 == false){
        ans += tree[2*index+1]; // everything in left are good
        ans += cnt(t, K, 2*index + 2, bit-1); // right maybe good
    }

    else if(y1 == false && y2 == true){
        ans = cnt(t, K, 2*index + 2, bit-1); // only hope is to go right
    }

    else if(y1 == false && y2 == false){
        ans += tree[2*index+2]; // everything in right are good
        ans += cnt(t, K, 2*index+1, bit-1); // left maybe good
    }

    return ans;
}

// algo to calculate number of pairs in 2 arrays such that a[i]^b[j] >= K where ^ is XOR
// using binary trie data structure
void solve(){

    // insert(2);
    // insert(2);
    // insert(3);
    // insert(3);
    // insert(3);
    // insert(0);
    // insert(0);
    // insert(1);


    // for(int i = 0; i <= 6; i++) cout << tree[i] << " ";
    // cout << endl;
   
    // cout << cnt(2, 1) << endl;
    int M, K;
    cin >> M >> K;

    vector<int> x(M), y(M);
    input(x, M);
    input(y, M);

    int ans = 0;

    for(int i = 0; i < M; i++) insert(x[i]);

    for(int i = 0; i < M; i++){
        ans += cnt(y[i], K);
    }

    cout << ans << endl;
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
	// cin >> T;

	while(T--){
		solve();
	}
	
	//cerr << getCurrentTime() << endl;
	return 0;
}
