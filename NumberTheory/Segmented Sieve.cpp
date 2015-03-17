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

#define rep(i,a,b)  for(i=a;i<=b;i++)
#define rep0(i,n)   for(i=0;i<n;i++)
#define rep1(i,n)   for(i=1;i<=n;i++)                 ///looping
#define rev(i,a,b)  for(i=a;i>=b;i--)
#define rev0(i,n)   for(i=n-1;i>=0;i--)
#define rev1(i,n)   for(i=n;i>=1;i--)
#define forstl(i,v) for(i=0;i<v.size();i++)
#define forit(v)    for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(p)      p.begin(),p.end()

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

#define LLI        long long int
#define i64        long long int
#define i64u       unsigned long long int
#define f64        long double
#define PI         acos(-1.0)                        ///PI er value

#define check(n, pos)  (bool)(n & (1LL<<(pos)))      ///AND
#define biton(n, pos)  (n | (1LL<<(pos)))            ///OR     }-bit opr.
#define bitoff(n, pos) (n & ~(1LL<<(pos)))          ///OFF


// reading and writing case
#define readcase  int cas,kase=0;CI(cas);while((cas--)&&(++kase))
#define printcase printf("Case %d:",kase)


//debugging infinite variable
bool deb_mode = 0;
#define debug(a...)        if(deb_mode){cout<<"Line= "<<__LINE__<<" ->  ";Dbug,a,#a;Dbug.printall();cout<<endl;}

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

const int MAXN = ( int )1e5;



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
#include<cassert>

using namespace std;

#define nln        puts("")                         ///printnewline
#define Max(a,b,c) max(a,max(b,c))                  ///3 ta theke max
#define Min(a,b,c) min(a,min(b,c))                  ///3 ta theke min
#define sqr(x)     (x)*(x)

#define Z(x)       fabs(x)<EPS
#define iqu(x,y)   Z(fabs(x-y))

#define FOR1(i,n)  for(i=1;i<=n;i++)
#define FOR0(i,n)  for(i=0;i<n;i++)                 ///looping
#define FORR(i,n)  for(i=n-1;i>=0;i--)
#define ALL(p)     p.begin(),p.end()

#define SET(p)     memset(p,-1,sizeof(p))
#define CLR(p)     memset(p,0,sizeof(p))            ///memset
#define MEM(p,v)   memset(p,v,sizeof(p))

#define READ(f)    freopen(f, "r", stdin)           /// file
#define WRITE(f)   freopen(f, "w", stdout)

#define vi         vector<int>
#define vll        vector<long long>
#define pii        pair<int,int>
#define SZ(c)      (int)c.size()
#define PB(x)      push_back(x)                     ///STL defines
#define MP(x,y)    make_pair(x,y)
#define ff         first
#define ss         second

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
};
char getc() {
    char c;
    for( c = getchar(); c <= 32; c = getchar() );
    return c;
}

const double EPS = 1e-9;                     ///constatnts
const int INF = ( 1 << 30 ) - 1;
const i64 LINF = ( 1ll << 62 ) - 1;

int dr8[8] = {1, -1, 0, 0, 1, -1, -1, 1};    ///8 direction move
int dc8[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dr4[4] = {0, 0, 1, -1};                  ///4 direction move
int dc4[4] = { -1, 1, 0, 0};                 ///or adjacent dir.
int kn8r[8] = {1, 2, 2, 1, -1, -2, -2, -1};  ///knight moves
int kn8c[8] = {2, 1, -1, -2, -2, -1, 1, 2};

///____________________________Main Coding Starts From Here________________________///


//segmented sieve starts
#define upto 47000
bool prime[upto];
vector<int> primes;
void sieve() {
    prime[0] = 1;
    prime[1] = 1;
    prime[2] = 0;
    primes.PB( 2 );
    for( int i = 2; i < upto; i++ ) {
        if( !prime[i] ) {
            primes.PB( i );
            for( int j = i + i; j < upto; j += i ) {
                prime[j] = 1;
            }
        }
    }
}

bool isPrime( int n ) {
    if( n <= upto )
        return !prime[n];
    int lim = primes.size();
    for( int i = 0; i < lim && primes[i] < n; i++ )
        if( n % primes[i] == 0 )
            return 0;
    return 1;
}
//segmented sieve ends


//UVa-10140 Prime Distance
//Algo:Segmented Sieve

int main() {
#ifndef ONLINE_JUDGE
//    READ("in.txt");
//    WRITE("out.txt");
    deb_mode = 1;
#endif


    int i, j;

    sieve();

    int L, U;
    while( CI( L, U ) == 2 ) {
        int C1, C2, D1, D2;
        int Max = 0, Min = 1000000000;
        int a = -1, b = -1;
        for( i = L; i <= U; i++ ) {
            if( isPrime( i ) ) {
                a = i;
                if( b != -1 ) {
                    if( ( a - b ) > Max ) {
                        D1 = b;
                        D2 = a;
                        Max = a - b;
                    }
                    if( ( a - b ) < Min ) {
                        C1 = b;
                        C2 = a;
                        Min = a - b;
                    }
                }
                b = a;
            }
        }

        if( Max ) {
            cout << C1 << "," << C2 << " are closest, " << D1 << "," << D2 << " are most distant.\n";
        }
        else cout << "There are no adjacent primes.\n";
    }
    return 0;
}

