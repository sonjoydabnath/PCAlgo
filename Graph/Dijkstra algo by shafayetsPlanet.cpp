/******************************/
/**      SONJOY DABNATH        **/
/** University Of Chittagong, BD >>/
/**   CSE 12th batch(11-12)    **/
/******************************/
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

using namespace std;

#define nln        puts("")                         ///printnewline
#define getInt(a)  scanf("%d",&a)
#define Max(a,b,c) max(a,max(b,c))                  ///3 ta theke max
#define Min(a,b,c) min(a,min(b,c))                  ///3 ta theke min

#define FOR1(i,n)  for(i=1;i<=n;i++)
#define FOR0(i,n)  for(i=0;i<n;i++)                 ///looping
#define FORR(i,n)  for(i=n-1;i>=0;i--)
#define ALL(p)     p.begin(),p.end()

#define SET(p)     memset(p,-1,sizeof(p))
#define CLR(p)     memset(p,0,sizeof(p))          ///memset
#define MEM(p,v)   memset(p,v,sizeof(p))

#define READ(f)    freopen(f, "r", stdin)           /// file
#define WRITE(f)   freopen(f, "w", stdout)

#define SZ(c)      (int)c.size()
#define PB(x)      push_back(x)                     ///STL defines
#define MP(x,y)    make_pair(x,y)
#define ff         first
#define ss         second

#define LI         long int
#define LLI        long long int
#define f64        long double
#define PI         acos(-1.0)                        ///PI er value


void CI(int &_x)
{
    scanf("%d",&_x);
}
void CI(int &_x,int &_y)
{
    CI(_x);
    CI(_y);
}
void CI(int &_x,int &_y,int &_z)
{
    CI(_x);
    CI(_y,_z);
};
void CI(int &_a,int &_b,int &_c,int &_d)
{
    CI(_a,_b);
    CI(_c,_d);
}

template<typename T> void getarray(T a[],int b,int e)
{
    for(int i=b; i<e+b; i++) cin>>a[i];
}
template<typename T> void printarray(T a[],int b,int e)
{
    for(int i=b; i<e-1+b; i++) cout<<a[i]<<" ";
    cout<<a[e-1+b]<<endl;
}

template <typename T> T BigMod (T b,T p,T m)
{
    if (p == 0) return 1;
    if (p%2 == 0)
    {
        T s = BigMod(b,p/2,m);
        return ((s%m)*(s%m))%m;
    }
    return ((b%m)*(BigMod(b,p-1,m)%m))%m;
}
template <typename T> T ModInv (T b,T m)
{
    return BigMod(b,m-2,m);
}

const double EPS=1e-9;                              ///constatnts
const int INF=0x7f7f7f7f;

int dr8[8]= {1,-1,0,0,1,-1,-1,1};            ///8 direction move
int dc8[8]= {0,0,-1,1,1,1,-1,-1};
int dr4[4]= {0,0,1,-1};                      ///4 direction move
int dc4[4]= {-1,1,0,0};                      ///or adjacent dir.
int kn8r[8]= {1,2,2,1,-1,-2,-2,-1};          ///knight moves
int kn8c[8]= {2,1,-1,-2,-2,-1,1,2};

#define check(n, pos) (n & (1<<(pos)))       ///AND
#define biton(n, pos) (n | (1<<(pos)))       ///OR     ///bit opr.
#define bitoff(n, pos) (n & ~(1<<(pos)))


#define mx 100002
vector<int>g[mx],cost[mx];
struct node
{
    int u,w;
    node(int a,int b)
    {
        u=a;
        w=b;
    }
    bool operator < ( const node& p ) const
    {
        return w > p.w;
    }
};
int d[mx],par[mx];
int dijkstra(int n)
{
    memset(d,INF,sizeof(d));  //অনেক বড় একটা মান বসাতে!
    memset(par,-1,sizeof(par));
    priority_queue<node>q;
    q.push(node(1,0));
    d[1]=0;
    while(!q.empty())
    {
        node top=q.top();
        q.pop();
        int u=top.u;

        if(u==n) return d[n];
        for(int i=0; i<(int)g[u].size(); i++)
        {
            int v=g[u][i];
            if(d[u]+cost[u][i]<d[v])
            {
                d[v]=d[u]+cost[u][i];
                par[v]=u;
                q.push(node(v,d[v]));
            }
        }
    }
    return -1;
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0; i<e; i++)
    {
        int u,v;
        int w;
        cin>>u>>v>>w;
        g[u].push_back(v);
        g[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    int ret=dijkstra(n);
    if(ret==-1) puts("No path!");
    else
    {
        int u=n;
        vector<int>out;
        while(u!=-1)
        {
            out.push_back(u);
            u=par[u];
        }
        reverse(out.begin(),out.end());
        for(int i=0; i<(int)out.size(); i++)
            cout<<out[i]<<" ";
        puts("");

    }
}
