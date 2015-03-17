#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
int lis( int *arr, int n )
{
    int *lis, i, j, max = 0;
    lis = (int*) malloc ( sizeof( int ) * n );
    for ( i = 0; i < n; i++ )
        lis[i] = 1;
    for ( i = 1; i < n; i++ )
        for ( j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    for ( i = 0; i < n; i++ )
        if ( max < lis[i] )
            max = lis[i];
    /* Free memory to avoid memory leak */
    free( lis );
    return max;
}

int main()
{
    int arr[10]= {1,2,3,2,4,6,8,7,5,10};
    int n=10;
    cout<<lis(arr,n)<<endl;
}
