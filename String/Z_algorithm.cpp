vector<int> z(MAX + 7);

void z_func( string s ) {
    int N = z[0] = s.size();
    int L = 0, R = 0;
    for( int i = 1; i < N; i++ ) {
        if( i > R ) {
            L = R = i;
            while( R < N && s[R - L] == s[R] )R++;
            z[i] = R - L;
            R--;
        }
        else {
            int k = i - L;
            if( z[k] + i <= R ) z[i] = z[k];
            else {
                L = i;
                while( R < N && s[R - L] == s[R] )R++;
                z[i] = R - L;
                R--;
            }
        }
    }
}
