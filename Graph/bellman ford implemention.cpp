// bellman ford implemention in C++
#include <cstdio>
#include <vector>

#define INF (1<<31 - 1)
#define NIL -1

using namespace std;

class bford
{

public:

    class edge
    {
    public:
        int u, v, w;
    };

    int nVertex;
    int *d, *p;
    vector<edge> elist;

    bford( )
    {
        d = new int[0];
        p = new int[0];
        elist.clear();
    }

    bool function( int s, int nVertex )
    {

        d = new int[(const int)nVertex+1];
        p = new int[(const int)nVertex+1];

        int i, j, w, u, v;
         // init_single_source( s ) {
        for (i=0 ; i<=nVertex ; i++)
        {
            d[i] = INF;
            p[i] = NIL;
        }
        d[s] = 0;
         // }

        for (i=0 ; i<nVertex-1 ; i++)
        {
            for ( j=0 ; j<elist.size() ; j++)
            {
                // relax( elist[j].u, elist[j].v, elist[j].w ) {
                u = elist[j].u;
                v = elist[j].v;
                w = elist[j].w;

                if (d[v] > d[u]+w)
                {
                    d[v] = d[u]+w;
                    p[v] = u;
                }
                // }
            }
        }

        for (i=0 ; i<elist.size() ; i++)
        {
            if ( d[ elist[i].v ] > d[ elist[i].u ] + elist[i].w )
            {
                return false;
            }
        }
        return true;
    }

};

int main( void )
{

    int i, u, v, w, nVertex, nEdge;

    bford grp;
    scanf("%d",&nVertex);

    scanf("%d",&nEdge);

    for (i=0 ; i<nEdge ; i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        grp.elist.push_back(bford::edge {u,v,w});
    }

    printf("%s\n",(grp.function( 1, nVertex )?"True":"False"));

    for (i=1 ; i<=nVertex ; i++)
    {
        printf("%d - %d\n",i, grp.d[i]);
    }


    return 0;

}
