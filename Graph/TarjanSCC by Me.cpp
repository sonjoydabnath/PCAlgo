#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string.h>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

#define spc        printf(" ")
#define nln        puts("")                         ///printnewline
#define Max(a,b,c) max(a,max(b,c))                  ///3 ta theke max
#define Min(a,b,c) min(a,min(b,c))                  ///3 ta theke min
#define sqr(x)     (x)*(x)

#define z(x)       fabs(x)<EPS
#define iqu(x,y)   z(fabs(x-y))

#define rep(i,a,b) for(i=a;i<=b;i++)
#define rep0(i,n)  for(i=0;i<n;i++)
#define rep1(i,n)  for(i=1;i<=n;i++)                 ///looping
#define per(i,a,b) for(i=a;i>=b;i--)
#define per0(i,n)  for(i=n-1;i>=0;i--)
#define per1(i,n)  for(i=n;i>=1;i--)
#define all(p)     p.begin(),p.end()

#define SET(p)     memset(p,-1,sizeof(p))
#define CLR(p)     memset(p,0,sizeof(p))            ///memset
#define MEM(p,v)   memset(p,v,sizeof(p))

#define READ(f)    freopen(f, "r", stdin)           /// file
#define WRITE(f)   freopen(f, "w", stdout)

#define vi         vector<int>
#define vll        vector<long long>
#define pii        pair<int,int>
#define pll        pair<long long,long long>
#define sz(c)      (int)c.size()
#define pb(x)      push_back(x)                     ///STL defines
#define mp(x,y)    make_pair(x,y)
#define xx         first
#define yy         second

#define LI         long int
#define i64        long long int
#define f64        long double
#define PI         acos(-1.0)                        ///PI er value

#define check(n, pos) (bool)(n & (1LL<<(pos)))      ///AND
#define biton(n, pos) (n | (1LL<<(pos)))            ///OR     }-bit opr.
#define bitoff(n, pos) (n & ~(1LL<<(pos)))          ///OFF


int CI(int &_x) {
    return scanf("%d",&_x);
}
int CI(int &_x,int &_y) {
    return scanf("%d %d",&_x,&_y);
}
int CI(int &_x,int &_y,int &_z) {
    return scanf("%d %d %d",&_x,&_y,&_z);
}
int CI(int &_a,int &_b,int &_c,int &_d) {
    return scanf("%d %d %d %d",&_a,&_b,&_c,&_d);
}

template<typename T> void getarray(T a[],int b,int e) {
    for(int i=b; i<e+b; i++)
        cin>>a[i];
}
template<typename T> void printarray(T a[],int b,int e) {
    for(int i=b; i<e-1+b; i++)
        cout<<a[i]<<" ";
    if(e-1+b>=0)
        cout<<a[e-1+b]<<endl;
}
template<typename T> void printV(vector<T> v) {
    int sz=v.size();
    if(sz)
        cout<<v[0];
    for(int i=1; i<sz; i++)
        cout<<" "<<v[i];
    nln;
}
template <typename T> T gcd(T a,T b) {
    if(b==0) return a;
    return gcd(b,a%b);
}
template <typename T> T BigMod (T b,T p,T m) {
    if (p == 0) return 1;
    if (p%2 == 0) {
        T s = BigMod(b,p/2,m);
        return ((s%m)*(s%m))%m;
    }
    return ((b%m)*(BigMod(b,p-1,m)%m))%m;
}
template <typename T> T ModInv (T b,T m) {
    return BigMod(b,m-2,m);
}
template<class T> inline void read(T &x) {
    bool Minus=0;
    char c;
    for(c=getchar(); c<=32; c=getchar()) ;
    if(c=='-') Minus=1,c=getchar();
    for(x=0; c>32; c=getchar()) x=x*10+c-'0';
    if(Minus) x=-x;
};
char getc() {
    char c;
    for(c=getchar(); c<=32; c=getchar());
    return c;
}

const double EPS=1e-9;                       ///constatnts
const int INF=(1<<30)-1;
const i64 LINF=(1ll<<62)-1;

int dr8[8]= {1,-1,0,0,1,-1,-1,1};            ///8 direction move
int dc8[8]= {0,0,-1,1,1,1,-1,-1};
int dr4[4]= {0,0,1,-1};                      ///4 direction move
int dc4[4]= {-1,1,0,0};                      ///or adjacent dir.
int kn8r[8]= {1,2,2,1,-1,-2,-2,-1};          ///knight moves
int kn8c[8]= {2,1,-1,-2,-2,-1,1,2};

//debugging multi variable
//#define printLine cout <<"Line= "<<__LINE__ <<" ->  ";
//#define print_dbg(x) cout<<" "#x"="<<x<<", ";
//#define dbg1(a) {printLine; print_dbg(a);nln;}
//#define dbg2(a,b) {printLine; print_dbg(a); print_dbg(b); nln;}
//#define dbg3(a,b,c) {printLine; print_dbg(a); print_dbg(b); print_dbg(c); nln;}
//#define dbg4(a,b,c,d) {printLine; print_dbg(a); print_dbg(b); print_dbg(c); print_dbg(d); nln;}
//#define dbg5(a,b,c,d,e) {printLine; print_dbg(a); print_dbg(b); print_dbg(c); print_dbg(d); print_dbg(e); nln;}
//#define dbg6(a,b,c,d,e,f) {printLine; print_dbg(a); print_dbg(b); print_dbg(c); print_dbg(d); print_dbg(e); print_dbg(f); nln;}

//debugging infinite variable
#define debug(a...) {cout<<"Line= "<<__LINE__<<" ->  ";Dbug,a,#a;Dbug.printall();cout<<endl;}
struct debugger
{
    vector<string> vars;
    template<typename T> debugger& operator , (const T v)
    {
        stringstream ss;
        ss<<v;
        vars.push_back(ss.str());
        return *this;
    }

    void printall() {
        int l=vars.size();
        int j=0;
        for(int i=0; i<(l-1); i++) {
            if(i)cout<<", ";
            for(j; j<vars[l-1].size(); j++) {
                if(vars[l-1][j]==',') {
                    j++;
                    break;
                }
                cout<<vars[l-1][j];
            }
            cout<<" = ";
            cout<<vars[i];
        }
        vars.clear();
    }

} Dbug;

// reading and writing case
#define readcase int cas,kase=0;CI(cas);while((cas--)&&(++kase))
#define printcase printf("Case %d:",kase)

///____________________________Main Coding Starts From Here________________________///

#define MAX 100000
vector<int> g[MAX+7];
stack<int> stackMember;
bool inStak[MAX+7];
int low[MAX+7],disc[MAX+7],_time;
vector<int> componants[MAX+7];
int comp_count;
int vertex,edge;

void Tarjan(int u) {
    low[u]=disc[u]=++_time;
    stackMember.push(u);
    inStak[u]=1;

    int v,i;
    rep0(i,g[u].size()) {
        v=g[u][i];
        if(disc[v]==-1) {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(inStak[v]) {
            low[u]=min(low[u],disc[v]);
        }
    }

    if(low[u]==disc[u]) {
        while(stackMember.top()!=u) {
            componants[comp_count].pb(stackMember.top());
            inStak[stackMember.top()]=0;
            stackMember.pop();
        }
        componants[comp_count].pb(stackMember.top());
        inStak[stackMember.top()]=0;
        stackMember.pop();
        comp_count++;
    }
}

void SCC() {
    SET(low);
    SET(disc);
    CLR(inStak);
    int i;
    while(!stackMember.empty())stackMember.pop();
    rep0(i,MAX)componants[i].clear();
    _time=0;
    comp_count=0;
    rep0(i,vertex) {
        if(low[i]==-1)
            Tarjan(i);
    }

}


int main() {
#ifndef ONLINE_JUDGE
//    READ("in.txt");
//    WRITE("out.txt");
#endif // ONLINE_JUDGE
    int i,j,n;
    CI(vertex,edge);
    rep0(i,edge){
        int u,v;
        CI(u,v);
        g[u].pb(v);
    }
    SCC();
    rep0(i,comp_count){
        cout<<"Componant:"<<i<<"\n";
        rep0(j,componants[i].size()){
            cout<<componants[i][j]<<" ";
        }
        nln;
    }
    return 0;
}






/*

Input:
11 17
0 1 0 3
1 2 1 4
2 0 2 6
3 2
4 5 4 6
5 6 5 7 5 8 5 9
6 4
7 9
8 9
9 8

Output:
Componant:0
8 9
Componant:1
7
Componant:2
5 4 6
Componant:3
3 2 1 0
Componant:4
10


*/
