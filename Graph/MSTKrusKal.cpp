#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int per[10000];
struct edg {
    int x, y, cost;
    bool operator <( const edg &p ) const
    {
        return cost < p.cost;
    }
};
int find( int n )
{
    if( per[n] == n ) return n;
    else find( per[n] );
}
vector<edg> G;
int mst( int nod, int edgs )
{
    int s = 0, count = 0;
    int i, j, u, v;
    for( i = 0; i <= nod; i++ ) per[i] = i;
    nod--;
    sort( G.begin(), G.end() );
    for( i = 0; i < edgs; i++ )
    {
        u = find( G[i].x );
        v = find( G[i].y );
        if( u != v )
        {
            count++;
            per[u] = v;
            s += G[i].cost;
            if( count == nod ) break;
        }
    }
    return s;
}
int main()
{
    int u, v, w, i, j;
    int nod, edgs;
    edg e;
    cin >> nod >> edgs;
    G.clear();
    for( i = 0; i < edgs; i++ )
    {
        cin >> e.x >> e.y >> e.cost;
        G.push_back( e );
    }
    int mincost = mst( nod, edgs );
    printf( "Minimum Cost is %d\n", mincost );
    return 0;
}
