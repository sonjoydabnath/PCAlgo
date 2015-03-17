#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<vector>
#include<map>
#include<queue>
#include<ctime>
using namespace std;
int N = 1000005, status[1000006];
int main()
{
    int i, j, sqrtN;
    for( i = 2; i <= N; i++ )
        if(i%2==1)status[i] = 0;
    else status[i]=1;

    sqrtN = int( sqrt((double)N) );

    for( i = 3; i <= sqrtN; i += 2 )
    {
        if( status[i] == 0 )
        {
            for( j = i * i; j <= N; j += i + i )
                status[j] = 1;
        }
    }
    status[0]=1;
    status[1]=1;
    status[2]=0;
    //printf("2 ");
    /*for( i =0; i <= 100; i++ )
    {
        if( status[i] == 0 )
            printf("%d ", i);
    }
    //puts("");
    //for( i = 2; i <= 100; i += 1 )

    return 0;*/
}
