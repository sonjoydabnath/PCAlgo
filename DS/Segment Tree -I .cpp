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
}
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

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

#define mx 100001
int arr[mx];
int tree[mx*3];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=tree[Left]+tree[Right];
}
int query(int node,int b,int e,int i,int j)
{
    if (i > e || j < b)          //বাইরে চলে গিয়েছে
        return 0;
    if (b >= i && e <= j)        //রিলেভেন্ট সেগমেন্ট
        return tree[node];
    int Left=node*2;             //আরো ভাঙতে হবে
    int Right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(Left,b,mid,i,j);
    int p2=query(Right,mid+1,e,i,j);
    return p1+p2;                   //বাম এবং ডান পাশের যোগফল
}
void update(int node,int b,int e,int i,int newvalue)
{
    if(i > e || i < b)      //বাইরে চলে গিয়েছে
        return;
    if (b >= i && e <= i) //রিলেভেন্ট সেগমেন্ট
        {
            tree[node]=newvalue;
            return;
        }
    int Left=node*2;   //আরো ভাঙতে হবে
    int Right=node*2+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,newvalue);
    update(Right,mid+1,e,i,newvalue);
    tree[node]=tree[Left]+tree[Right];
}

///-----print d tree-------///
void printTree(int node,int b,int e)
{
//    cout<<"Node = "<<tree[node].minValue<<" "<<tree[node].indx<<" range "<<b<<"-"<<e<<endl;
    if(b==e)
        return;
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    printTree(left,b,mid);
    printTree(right,mid+1,e);
}
///**********************************///


int main()
{
    //READ("in");
    int n,i;
    cin>>n;
    FOR1(i,n)
    cin>>arr[i];
    init(1,1,n);
    update(1,1,n,2,0);
    cout<<query(1,1,n,1,3)<<endl;
    update(1,1,n,2,2);
    cout<<query(1,1,n,2,2)<<endl;
    return 0;
}
