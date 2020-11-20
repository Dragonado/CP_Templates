#include <bits/stdc++.h>
using namespace std;

#define MOD (1000000000+7)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) x.begin(), x.end()
#define print(vec,l,r) for(int i = l; i <= r; i++) cout << vec[i] <<" "; cout << endl;
#define forf(i,a,b) for(int i = (a); i < (b); i++)
#define forr(i,a,b) for(int i = (a); i > (b); i--)
#define input(vec,N) for(int i = 0; i < (N); i++) cin >> vec[i];
#define debug(x) cerr << #x << " = " << x << endl;

// template starts

// template ends here


int N, M; // no of vertices and no of edges
int l;
vector<vector<int>> adj,lift;
vector<int> tin,tout;
int T_of_tin= 0;

void resizeAll(){
	adj.clear();
	tin.clear();
	tout.clear();

	adj.resize(N);
	tin.resize(N);
	tout.resize(N);
	lift.assign(N, vector<int>(l + 1));
}

void input_graph(){
	for(int i = 0; i < M; i++){
		int t1,t2;
		cin >> t1 >> t2;
		//t1--;t2--; // assuming the input is 1 based!!
		
		adj[t1].pb(t2);
		adj[t2].pb(t1);
	}
}

void dfs(int root,int parent){
	
	tin[root] = T_of_tin++;
	
	lift[root][0] = parent;
	for(int i = 1; i <= l; i++){
		lift[root][i] = lift[lift[root][i-1]][i-1];
	}
	
	for(int i = 0; i < (int)adj[root].size(); i++){
		int child = adj[root][i];
		if(child == parent)continue;
		
		dfs(child,root);
	}	
	tout[root] = T_of_tin++;
}

bool is_ancestor(int u, int v){
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca(int u, int v){
	if(is_ancestor(u,v)) return u;
	if(is_ancestor(v,u)) return v;
	
	for(int i = l; i >= 0; i--){
		//debug(u);
		//debug(v);
		//debug(is_ancestor(u,v));
		//cerr << endl;
		if(!is_ancestor(lift[u][i],v)) u = lift[u][i];
	}
	//debug(u);
	//debug(lift[u][0]);
	return lift[u][0];
}

int distance(int u, int v){
	int node = lca(u,v);
	
	
	int d1 = 0, d2 = 0;
	for(int i = l; i >= 0; i--){
		//debug(i);
		//debug(lift[u][i]);
		//debug(is_ancestor(lift[u][i],node));
		
		//cerr << endl;
		//debug(lift[v][i]);
		//debug(is_ancestor(lift[v][i],node));
		//cerr << endl;
		if(!is_ancestor(lift[u][i],node)){
			d1 += 1<<i;
			u = lift[u][i];
		}
		if(!is_ancestor(lift[v][i],node)){
			d2 += 1<<i;
			v = lift[v][i];
		}
	}
	return d1+d2+2-(node == u)-(node == v);
}

// IMPORTANT: Everything here is 1 based index!!!!
void solve(){
	// code starts from here
	srand(time(0));
	cin >> N;
	
	l = ceil(log2(N));
	M = N-1; // by default tree
	//cin >> M; //comment if tree
	N++;
	resizeAll();
	input_graph();
	
	dfs(1,0);
	tin[0] = 0;
	tout[0] = INT_MAX;

	// thing to remember:
	// Make sure everything is zero based indexing
	// Make sure to check each component of the graph
	// Memory overflow. Try making int to int
}

int main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int T;
	T = 1;
	while(T--){
		solve();
	}

	return 0;
}
