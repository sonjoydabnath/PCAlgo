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

void printbin( int n ) {
    for( int i = 31; i >= 0; i-- )
        cout << ( bool )( n & ( 1 << i ) );
    nln;
}


// 1 ^ 2 ^ 3 ^ ... ^ N = ?
i64 getXorUpto( i64 N ) {
    i64 M = N + 1;
    i64 R = 0LL;
    for( int i = 0; i < 60; i++ ) {
        i64 U = 1LL << i;
        i64 V = 1LL << ( i + 1 );
        i64 G = M / V;
        G *= U;
        i64 Y = M % V;
        if( Y > U ) G += ( Y - U );
        if( G & 1LL )
            R |= ( 1LL << i );
    }
    return R;
}

/* guess A[1] = 1, A[2] = 1 ^ 2, A[3] = 1 ^ 2 ^ 3, ..... A[N] = 1 ^ 2 ^ 3 ^ ... ^ N
to get A[1] ^ A[2] ^ A[3] ^ .... ^ A[N] call this function */
i64 getCumXorUpto( i64 N ) {
    if( N % 2 == 0 ) {
        return 2LL * getXorUpto( N >> 1 );
    }
    else {
        N = ( N + 1 ) >> 1;
        i64 T = getXorUpto( N - 1 ) * 2LL;
        return T ^ ( N & 1 );
    }
}



int main() {
    int i, j;

    // Bit Hacks
    puts( "Looping over all non-zero submask of a binary mask" );
    int mask = 127;
    for ( int submask = mask; submask != 0; submask = ( submask - 1 ) & mask ) {
        printbin( submask );
        cout << submask << endl;
    }

    cout << "\nLooping over all set bits of a binary mask\n";
    for ( int m = mask; m != 0; m &= ( m - 1 ) ) {
        printbin( ( ( m & ( m - 1 ) ) ^ m ) );
        cout << ( ( m & ( m - 1 ) ) ^ m ) << endl;
    }


    bitset<64> foo;
//    cin >> foo;
    int n = 127;

    foo = bitset<64>( n );
//   converting integer to binary string
    string str = foo.to_string();
    cout << str << "\n";

//    converting binary string to integer
    foo = bitset<64>( str );
    n = foo.to_ulong();
    cout << n << "\n";

    return 0;
}
