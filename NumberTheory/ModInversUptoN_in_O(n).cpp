vector<i64> ModInverseArray( int n, i64 m ) {
    vector<i64> modInverse( n + 1, 0 );
    modInverse[1] = 1;
    for( int i = 2; i <= n; i++ ) {
        modInverse[i] = ( -( m / i ) * modInverse[m % i] ) % m + m;
    }
    return modInverse;
}
