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

#define nln        puts("")                         ///printnewline
#define Max(a,b,c) max(a,max(b,c))                  ///3 ta theke max
#define Min(a,b,c) min(a,min(b,c))                  ///3 ta theke min
#define sqr(x)     (x)*(x)

#define z(x)       fabs(x)<EPS
#define iqu(x,y)   Z(fabs(x-y))

#define rep(i,a,b) for(i=a;i<=b;i++)
#define rep0(i,n)  for(i=0;i<n;i++)
#define rep1(i,n)  for(i=1;i<=n;i++)                 ///looping
#define repr(i,n)  for(i=n-1;i>=0;i--)
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

#define READCASE int cas,kase=0;CI(cas);while((cas--)&&(++kase))
#define printCase printf("Case %d: ",kase)
#define dbg(x) cout <<"Line= "<<__LINE__ <<" ->  "<< #x " = " << (x) << endl;

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

///____________________________Main Coding Starts From Here________________________///


struct node{
    int endmark;
    node *next[26];
    node(){
        int i;
        endmark=0;
        rep0(i,26)
        next[i]=NULL;
    }
};

node *root;

void insert(string str){
    int i;
    int len=str.size();
    node *curr=root;
    rep0(i,len){
        int id=str[i]-'a';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
    }
    curr->endmark=1;
}

bool search(string str){
    int i,len=str.size();
    node *curr=root;
    rep0(i,len){
        int id=str[i]-'a';
        if(curr->next[id]==NULL)
            return false;
        curr=curr->next[id];
    }
    return curr->endmark;
}

void del(node *curr){
    int i;
    rep0(i,26){
        if(curr->next[i]!=NULL)
            del(curr->next[i]);
    }

    delete(curr);
}


int main() {
//    READ("in.txt");
//    WRITE("out.txt");
    int i,j,n;
    string str;
    root=new node();
    puts("ENTER THE NUMBER OF WORDS");
    CI(n);
    rep0(i,n){
        cin>>str;
        insert(str);
    }
    puts("ENTER THE NUMBER OF QUERY");
    int q;
    CI(q);
    while(q--){
         cin>>str;
         if(search(str))
            puts("FOUND");
         else puts("NOT FOUND");
    }
    del(root);
    return 0;
}

