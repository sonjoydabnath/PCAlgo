#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <set>
#include <math.h>

#define pi acos(-1.0)
#define N 1000000

using namespace std;

struct List
{
    int start;
    int end;
    int distance;
} a [100 * 100]; // vertex * vertex

int parent [100]; // total vertex

bool cmp (List p, List q)
{
    if ( p.distance < q.distance ) return true;
    return false;
}

void reset ()
{
    for ( int i = 0; i < 100; i++ )
        parent [i] = i;
}

int parentOf (int n)
{
    if ( n == parent [n] ) return n;
    return parent [n] = parentOf ( parent [n] );
}

int main ()
{
    int edges;
    scanf ("%d", &edges);

    reset ();

    int length_a = 0;

    for ( int i = 1; i <= edges; i++ )
    {
        int v1, v2, dist;
        a [length_a].start = v1;
        a [length_a].end = v2;
        a [length_a++].distance = dist;
    }

    sort (a, a + length_a, cmp);

    int outputCost = 0;
    int selectedEdges = edges - 1;

    for ( int i = 0; i < length_a && selectedEdges; i++ )
    {
        int p = parentOf (a [i].start);
        int q = parentOf (a [i].end);

        if ( p != q )
        {
            parent [p] = q;
            selectedEdges--;
            outputCost += a [i].distance;
        }
    }

    printf ("%d\n", outputCost);

    return 0;
}
