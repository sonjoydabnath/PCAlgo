int Mu[MAX + 7];
int P[MAX + 7];
void GenMu() {
        Mu[1] = 1;
        for( int i = 2; i <= MAX; i++ ) {
                if( P[i] == 0 ) {
                        P[i] = i;
                        Mu[i] = 1;
                        for( int j = i + i; j <= MAX; j += i ) {
                                if( P[j] == 0 ) P[j] = i;
                                if( P[j / P[j]] == P[j] ) {
                                        Mu[j] = 0; //non square-free
                                }
                                else {
                                        Mu[j] = -1 * Mu[j / P[j]]; //square-free nums
                                }
                        }
                }
        }
}

int main() {
#ifndef ONLINE_JUDGE
//    READ("in.txt");
//    WRITE("out.txt");
        deb_mode = 1;
#endif
        if( deb_mode )
                srand( int( time( NULL ) ) );
        int i, j, k, l, n, m, q, a, b, c;

        if( deb_mode )
                cerr << "EXECUTION TIME = " << ( 1.0 * clock() ) / CLOCKS_PER_SEC << " SECONDS\n";
        return 0;
}
