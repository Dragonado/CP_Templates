// taken from: https://pastebin.com/DLQ9RWwH
//https://www.youtube.com/watch?v=zcyxbcrPvqk&t=4778s Sidhant Bansal Orz

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
// #define int ll // disable when you want to make code a bit faster
#define endl '\n' // disable when dealing with interactive problems


const int N = 2e5 + 5;
 
set<int> adj[N];

vector<int> B[N];

bool isBridge[N], visited[N];

int disc[N], low[N], par[N], label[N];
int cntr;
 
void dfs_bridge(int u, int prev){ // Bridge Finding
    visited[u] = 1;
    par[u] = prev;
    disc[u] = ++cntr;
    low[u] = disc[u];
 
    for(auto v : adj[u]){
        if(v == prev)   continue;
        if(visited[v] == false){ // un-explore node, so down in DFS tree
            dfs_bridge(v, u);
            if(low[v] > disc[u])    isBridge[v] = true;
        }
        low[u] = min(low[u], low[v]); // un-explored node OR back-edge
    }
}
 
void dfs_label(int u){ // Label each bridge component
    visited[u] = 1;
    label[u] = cntr;
    for(auto v : adj[u])
        if(!visited[v])
            dfs_label(v);
}
 
int main(){
    int n, m, u, v;

    cin>>n>>m;
    while(m--){
        cin>>u>>v; // 1 based indexing
        adj[u].insert(v);
        adj[v].insert(u);

        // if u,v can have multiple edges between them then
        // https://judge.yosupo.jp/submission/35733
    }
 
    vector<pair<int, int> > bridges;
 
    cntr = 0;
    for(int i = 1; i <= n; i++) visited[i] = 0;

    dfs_bridge(1,0); 

    // if graph is not connected, uncomment below
    // for(int i = 1; i <= n; i++){
    //     if(visited[i]) continue;
    //     cntr = 0;
    //     dfs_bridge(i, 0);
    // }

    for(int i = 1; i <= n; i++){
        visited[i] = 0;
        if(isBridge[i]){
            bridges.push_back({i, par[i]});
            adj[i].erase(par[i]);
            adj[par[i]].erase(i);
        }
    }
 
    cntr = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cntr++;
            dfs_label(i);
        }
    }

    for(auto v : bridges){ // Make bridge tree (or forest if graph is not connected)
        int a = label[v.first], b = label[v.second];
        B[a].push_back(b);
        B[b].push_back(a);
    }

    return 0;
}
