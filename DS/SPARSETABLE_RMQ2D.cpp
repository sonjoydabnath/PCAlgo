int N, M, grid[1010][1010];
int lg2[1111];
int SPARSE[11][1111][11][1111];

void RMQ2D_build() {
        for( int i = 1; i <= 1000; i++ ) lg2[i] = log2( i );

        for( int ir = 0; ir < N; ir++ ) {
                for( int ic = 0; ic < M; ic++ ) {
                        SPARSE[0][ir][0][ic] = grid[ir + 1][ic + 1]; //SPARSE table is 0-based indexed, grid array is 1-based indexed
                }

                for( int jc = 1; jc <= lg2[M]; jc++ ) {
                        for( int ic = 0; ic + ( 1 << ( jc - 1 ) ) < M; ic++ ) {
                                SPARSE[0][ir][jc][ic] = max( SPARSE[0][ir][jc - 1][ic], SPARSE[0][ir][jc - 1][ic + ( 1 << ( jc - 1 ) )] );
                        }
                }
        }

        for( int jr = 1; jr <= lg2[N]; jr++ ) {
                for( int ir = 0; ir < N; ir++ ) {
                        for( int jc = 0; jc <= lg2[M]; jc++ ) {
                                for( int ic = 0; ic < M; ic++ ) {
                                        SPARSE[jr][ir][jc][ic] = max( SPARSE[jr - 1][ir][jc][ic], SPARSE[jr - 1][ir + ( 1 << ( jr - 1 ) )][jc][ic] );
                                }
                        }
                }
        }
}

int RMQ2D_query( int r1, int c1, int r2, int c2 ) {
        //0-based indexing broH!!
        int lenR = ( r2 - r1 + 1 );
        int lenC = ( c2 - c1 + 1 );
        int lggR = lg2[lenR];
        int lggC = lg2[lenC];

        int mx1 = max( SPARSE[lggR][r1][lggC][c1], SPARSE[lggR][r1][lggC][c2 + 1 - ( 1 << lggC )] );
        int mx2 = max( SPARSE[lggR][r2 + 1 - ( 1 << lggR )][lggC][c1], SPARSE[lggR][r2 + 1 - ( 1 << lggR )][lggC][c2 + 1 - ( 1 << lggC )] );
        return max( mx1, mx2 );
}
