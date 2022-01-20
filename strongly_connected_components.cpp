// taken from: https://pastebin.com/DLQ9RWwH
//https://www.youtube.com/watch?v=zcyxbcrPvqk&t=4778s Sidhant Bansal Orz
//https://judge.yosupo.jp/submission/35801 my soln

#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

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


const int N = 2e5 + 5;

vector<int> adj[N], adjr[N]; // make it set if graph is not simple

vector<int> CT[N]; // Component Tree (technically a DAG)
int sz[N], label[N];

vector<int> SCC[N]; // contains vertices of the same SCC

int fin_order_inc[N]; // contains vertices in sorted order of finishing time

bool visited[N];

int cntr;
 
void dfs_scc(int u){ // finding exit time in Gr
    visited[u] = true;
 
    for(auto v : adjr[u]){
        if(visited[v] == true) continue;
        dfs_scc(v);
    }

    fin_order_inc[++cntr] = u;
}
 
void dfs_label(int u){ // Label each SCC
    visited[u] = true;
    label[u] = cntr;
    sz[label[u]]++;
    SCC[label[u]].pb(u);
    
    for(auto v : adj[u])
        if(!visited[v])
            dfs_label(v);
}

void dfs_CT(int u){ // creating Component Tree
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v]) dfs_CT(v);

        if(label[u] != label[v]) CT[label[u]].pb(label[v]);
    }
}


bool cmp(const pair<int,int> &a, const pair<int,int>  &b){
    return b.first < a.first;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, u, v;

    cin>>n>>m;

    while(m--){
        cin>>u>>v; // 1 based indexing
        // u++;v++;// uncomment if input is 0 based indexing
        if(u == v) continue;
        
        adj[u].pb(v);
        adjr[v].pb(u);

        // adj[u].insert(v);
        // adjr[v].insert(u);
    }
    ///////////////////////////////////////////////////////////
    cntr = 0;
    for(int i = 1; i <= n; i++) sz[i] = visited[i] = 0;

    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        dfs_scc(i);
    }

    ///////////////////////////////////////////////////////////
    for(int i = 1; i <= n; i++) visited[i] = 0;
 
    cntr = 0;

    // last elemnt of find_order_inc is source in Gr and sink in G

    for(int i = n; i >= 1; i--){
        int u = fin_order_inc[i];
        if(visited[u]) continue;

        cntr++;
        dfs_label(u);
    }
    ///////////////////////////////////////////////////////////

    for(int i = 1; i <= n; i++) visited[i] = 0;
 
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        dfs_CT(i);   
    }

    ///////////////////////////////////////////////////////////

    int n_CT = cntr; //number of vertices in CT
    // Note: n_CT, n_CT-1, n_CT-2 ... 3,2,1 are in top sort order, edges go from left to right
    return 0;
}
