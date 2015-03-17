#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
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
#define i64u       unsigned long long int
#define f64        long double
#define PI         acos(-1.0)                        ///PI er value

#define check(n, pos) (bool)(n & (1LL<<(pos)))      ///AND
#define biton(n, pos) (n | (1LL<<(pos)))            ///OR     }-bit opr.
#define bitoff(n, pos) (n & ~(1LL<<(pos)))          ///OFF


// reading and writing case
#define readcase int cas,kase=0;CI(cas);while((cas--)&&(++kase))
#define printcase printf("Case %d:",kase)


//debugging infinite variable
#define debug(a...)               {cout<<"Line= "<<__LINE__<<" ->  ";Dbug,a,#a;Dbug.printall();cout<<endl;}

struct debugger {
    vector<string> vars;
    template<typename T> debugger& operator , ( const T v ) {
        stringstream ss;
        ss << v, vars.push_back( ss.str() );
        return *this;
    }
    void printall() {
        int j = 0, l = vars.size();
        for( int i = 0; i < ( l - 1 ); i++ ) {
            if( i )cout << ", ";
            for( j; j < vars[l - 1].size(); j++ ) {
                if( vars[l - 1][j] == ',' ) {
                    j++;
                    break;
                }
                cout << vars[l - 1][j];
            }
            cout << " = " << vars[i];
        }
        vars.clear();
    }

} Dbug;



int CI( int &_x ) {
    return scanf( "%d", &_x );
}
int CI( int &_x, int &_y ) {
    return scanf( "%d %d", &_x, &_y );
}
int CI( int &_x, int &_y, int &_z ) {
    return scanf( "%d %d %d", &_x, &_y, &_z );
}
int CI( int &_a, int &_b, int &_c, int &_d ) {
    return scanf( "%d %d %d %d", &_a, &_b, &_c, &_d );
}

template<typename T> void getarray( T a[], int b, int e ) {
    for( int i = b; i < e + b; i++ )
        cin >> a[i];
}

template<typename T> void printarray( T a[], int b, int e ) {
    for( int i = b; i < e - 1 + b; i++ )
        cout << a[i] << " ";
    if( e - 1 + b >= 0 )
        cout << a[e - 1 + b] << endl;
}

template<typename T> void printV( vector<T> v ) {
    int sz = v.size();
    if( sz )
        cout << v[0];
    for( int i = 1; i < sz; i++ )
        cout << " " << v[i];
    nln;
}

template <typename T> T gcd( T a, T b ) {
    if( b == 0 ) return a;
    return gcd( b, a % b );
}

template <typename T> T BigMod ( T b, T p, T m ) {
    if ( p == 0 ) return 1;
    if ( p % 2 == 0 ) {
        T s = BigMod( b, p / 2, m );
        return ( ( s % m ) * ( s % m ) ) % m;
    }
    return ( ( b % m ) * ( BigMod( b, p - 1, m ) % m ) ) % m;
}

template <typename T> T ModInv ( T b, T m ) {
    return BigMod( b, m - 2, m );
}

template<class T> inline void read( T &x ) {
    bool Minus = 0;
    char c;
    for( c = getchar(); c <= 32; c = getchar() ) ;
    if( c == '-' ) Minus = 1, c = getchar();
    for( x = 0; c > 32; c = getchar() ) x = x * 10 + c - '0';
    if( Minus ) x = -x;
}

char getc() {
    char c;
    for( c = getchar(); c <= 32; c = getchar() );
    return c;
}

const double EPS = 1e-9;                    ///constatnts
const int INF = ( 1 << 30 ) - 1;
const i64 LINF = ( 1ll << 62 ) - 1;

int dr8[8] = {1, -1, 0, 0, 1, -1, -1, 1};    ///8 direction move
int dc8[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dr4[4] = {0, 0, 1, -1};                  ///4 direction move
int dc4[4] = { -1, 1, 0, 0};                 ///or adjacent dir.
int kn8r[8] = {1, 2, 2, 1, -1, -2, -2, -1};  ///knight moves
int kn8c[8] = {2, 1, -1, -2, -2, -1, 1, 2};


///____________________________Main Coding Starts From Here________________________///


#define SIZE 8000
vector< vi > Graph, ReGraph;
stack<int> Stack;
bool inStack[SIZE * 2 + 10];
int node, edge;
int comp[SIZE * 2 + 10];
int low[SIZE * 2 + 10];
int disc[SIZE * 2 + 10], timer_, comp_count;


int getNode( int n ) {
    if( n > 0 ) {
        return 2 * n - 2;
    }
    return 2 * ( -n ) - 1;
}

void Tarjan( int u ) {
    low[u] = disc[u] = ++timer_;
    Stack.push( u );
    inStack[u] = 1;

    int v, i;
    rep0( i, Graph[u].size() ) {
        v = Graph[u][i];
        if( disc[v] == -1 ) {
            Tarjan( v );
            low[u] = min( low[u], low[v] );
        }
        else if( inStack[v] ) {
            low[u] = min( low[u], disc[v] );
        }
    }

    if( low[u] == disc[u] ) {
        while( Stack.top() != u ) {
            comp[Stack.top()] = comp_count;
            inStack[Stack.top()] = 0;
            Stack.pop();
        }
        comp[Stack.top()] = comp_count;
        inStack[Stack.top()] = 0;
        Stack.pop();
        comp_count++;
    }
}

void SCC() {
    SET( low );
    SET( disc );
    CLR( inStack );
    int i;
    while( !Stack.empty() )Stack.pop();
    timer_ = 0;
    comp_count = 0;
    rep0( i, 2 * node ) {
        if( low[i] == -1 )
            Tarjan( i );
    }
}


void solve2sat() {
    SCC();
    int i, k = 1;
    vector<int> solu;
    for( i = 0; i < 2 * node; i += 2 ) {
        if( comp[i] == comp[i + 1] ) {
            puts( "No" );
            return;
        }
        if( comp[i] > comp[i + 1] )
            solu.pb( k );
        k++;
    }
    puts( "Yes" );
    cout << solu.size();
    rep0( i, solu.size() )
    cout << " " << solu[i];
    nln;
}


void init() {
    int i;
    Graph.assign( 2 * node, vector<int>() );
}


void showGraph() {
    int i, j;
    rep0( i, Graph.size() ) {
        cout << " Node = " << i << " -> ";
        rep0( j, Graph[i].size() ) {
            cout << Graph[i][j] << " ";
        }
        nln;
    }
}


/*
*Prob: LOJ1251
*Algo: 2-SAT
*Tutorial: http://e-maxx.ru/algo/2_sat
*Implemented by: SONJOY DABNATH
**/


int main() {
#ifndef ONLINE_JUDGE
//    READ( "in.txt" );
//    WRITE("out.txt");
#endif //ONLINE_JUDGE

    int i, j, k, l, n, m, q, a, b, c;
    readcase {
        CI( edge, node );
        init();
        rep0( i, edge ) {
            CI( a, b );
            // -a means !a, negation of a
            Graph[getNode( b )].pb( getNode( -a ) );
            Graph[getNode( a )].pb( getNode( -b ) );
        }
        printcase;
        spc;
        solve2sat();
    }
    return 0;
}
