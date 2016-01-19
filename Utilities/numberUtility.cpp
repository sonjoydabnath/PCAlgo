/**
* SOME NUMBER THEORY ALGOs
* Collected From: Igor Naverniouk
**/

/**
 * Euclidean algorithm. Works on non-negative integers.
 **/
int gcd( int a, int b ) { return( b == 0 ? a : gcd( b, a % b ) ); }
long long gcd( long long a, long long b ) { return( b == 0 ? a : gcd( b, a % b ) ); }
template<class Int > Int gcd( Int a, Int b ) { return( b == 0 ? a : gcd( b, a % b ) ); }

/**
 * A triple of integers
 * USED BY: egcd, msolve, inverse, ldioph
 **/
template< class Int >
struct Triple {
    Int d, x, y;
    Triple( Int q, Int w, Int e ) : d( q ), x( w ), y( e ) {}
};

/**
 * Extended GCD
 * Given nonnegative a and b, computes d = gcd( a, b )
 * along with integers x and y, such that d = ax + by
 * and returns the triple (d, x, y).
 * WARNING: needs a small modification to work on
 *      negative integers (operator% fails).
 * REQUIRES: struct Triple
 * USED BY: msolve, inverse, ldioph
 **/
template< class Int >
Triple< Int > egcd( Int a, Int b ) {
    if( !b ) return Triple< Int >( a, Int( 1 ), Int( 0 ) );
    Triple< Int > q = egcd( b, a % b );
    return Triple< Int >( q.d, q.y, q.x - a / b * q.y );
}

/**
 * Modular Linear Equation Solver
 * Given a, b and n, solves the equation ax = b (mod n)
 * for x. Returns the vector of solutions, all smaller
 * than n and sorted in increasing order. The vector is
 * empty if there are no solutions.
 * #include <vector>
 * REQUIRES: struct Triple, egcd
 **/
#include<vector>
using namespace std;
template< class Int >
vector< Int > msolve( Int a, Int b, Int n ) {
    if( n < 0 ) n = -n;
    Triple< Int > t = egcd( a, n );
    vector< Int > r;
    if( b % t.d ) return r;
    Int x = ( b / t.d * t.x ) % n;
    if( x < Int( 0 ) ) x += n;
    for( Int i = 0; i < t.d; i++ )
        r.push_back( ( x + i * n / t.d ) % n );
    return r;
}

/**************************************
 * Linear Diophantine Equation Solver *
 **************************************
 * Solves integer equations of the form ax + by = c
 * for integers x and y. Returns a triple containing
 * the answer (in .x and .y) and a flag (in .d).
 * If the returned flag is zero, then there are no
 * solutions. Otherwise, there is an infinite number
 * of solutions of the form
 *          x = t.x + k * b / t.d,
 *          y = t.y - k * a / t.d;
 * where t is the returned triple, and k is any
 * integer.
 * REQUIRES: struct Triple, egcd
 **/
template< class Int >
Triple< Int > ldioph( Int a, Int b, Int c ) {
    Triple< Int > t = egcd( a, b );
    if( c % t.d ) return Triple< Int >( 0, 0, 0 );
    t.x *= c / t.d;
    t.y *= c / t.d;
    return t;
}

/*******************
 * Modular Inverse *
 *******************
 * Given a and n, solves ax = 1 (mod n).
 * Returns 0 if there is no solution.
 * REQUIRES: struct Triple, egcd
 **/
template< class Int >
Int inverse( Int a, Int n ) {
    Triple< Int > t = egcd( a, n );
    if( t.d > Int( 1 ) ) return Int( 0 );
    Int r = t.x % n;
    return( r < Int( 0 ) ? r + n : r );
}

/************************************
 * Continued Fractions of Rationals *
 ************************************
 * Returns the continued fraction of the rational
 * number m/n. The resulting finite sequence of
 * integers is pushed to the end of 'ans'.
 * Complexity: O( log n )
 * #include <vector>
 **/
template< class Int >
void contFract( Int m, Int n, vector< Int > &ans ) {
    while( n ) {
        ans.push_back( m / n );
        m %= n;
        m ^= n ^= m ^= n;
    }
}
