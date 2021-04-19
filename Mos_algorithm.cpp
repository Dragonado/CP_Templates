//https://codeforces.com/contest/86/submission/113484953
// the below code is used to find the mode a range l,r. Uses randomization instead of std::set
#include<bits/stdc++.h>
#define int long long
#define rg int 
#define il inline
#define M 300005
#define N 300005

using namespace std;
int n,m,l,r,ans,len;
int a[N], b[M];

struct did{
    int l,r,id,ans;
}q[M];

set<pair<int,int>> s;
int freq[N];

il int read() {
    int f=1,s=0; char ch=getchar();
    while(!isdigit(ch)) (ch=='-')&&(f=-1),ch=getchar();
    while(isdigit(ch)) s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
    return f*s; 
}
il void print(int x)  {
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);putchar(x%10+'0');
}
   il bool cmp(did x,did y) {
	return b[x.l]^b[y.l]?x.l<y.l:b[x.l]&1?x.r<y.r:x.r>y.r;
}
il void add(int x) {
    freq[a[x]]++;
}
il void del(int x) {
    freq[a[x]]--;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getMode(int l, int r){
    int mx = 0;
    auto dist = uniform_int_distribution<int>(l, r);
// use int a = dist(rng) to get a random number between [l,r] inclusive
    for(int i = 0; i < 40; i++){
        int index = dist(rng);
        mx = max(mx, freq[a[index]]);
    }
    return mx;
}

il void answer(int l, int r){
    ans = getMode(l, r);
}
il bool cmp2(did x,did y) {
    return x.id<y.id;
}
signed main() {
    n=read(),m=read(); len=n/sqrt(m*2/3)+1;
    
    for(int i = 0; i <= n; i++) freq[i] = 0;

    for(rg i=1;i<=n;++i) a[i]=read(),b[i]=(i-1)/len+1;
    for(rg i=1;i<=m;++i) q[i].l=read(),q[i].r=read(),q[i].id=i;

    sort(q+1,q+m+1,cmp);
    l=1,r=0;
    for(rg i=1;i<=m;++i) {
        int ql=q[i].l,qr=q[i].r;
        while(l<ql) del(l++);
        while(l>ql) add(--l);
        while(r<qr) add(++r);
        while(r>qr) del(r--);
        answer(q[i].l, q[i].r);
        q[i].ans= ans;
        
    } 
    sort(q+1,q+m+1,cmp2);
    for(rg i=1;i<=m;++i) print(q[i].ans),putchar('\n');
    return 0;
}
// Format of input: everything 1 based indexing
// N Q
// v1 v2 v3 ... vN
// l1 r1
// l2 r2
// .
// lQ rQ