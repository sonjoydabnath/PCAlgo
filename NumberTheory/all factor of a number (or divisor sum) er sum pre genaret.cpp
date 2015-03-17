#include <cctype> // knapsack Item print http://codepad.org/CDN8Aum3
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

#define Max(a,b,c) max(a,max(b,c))      ///3 ta theke max
#define Min(a,b,c) min(a,min(b,c))      ///3 ta theke min
#define Pi acos(-1.0)                   ///PI er value

#define ALL(p) p.begin(),p.end()
#define MP(x, y) make_pair(x, y)

#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

int ans[1005];
int main()                            ///divsum of 12 =1+2+3+4+6+12
{
    int i,j,k,l,tmp,n,cas = 1;

    int factor_sum[1001];

    factor_sum[1] = 1;
    for( i = 2,j = 3; i <= 1000; i++,j++)
        //a[i].num = i,
        factor_sum[i] = j;
    for( i = 2; i <= 33; i++)
    {
        for( j = i*i; j < 1001; j += i)
        {
            factor_sum[j] += i;
            tmp = j/i;
            if( tmp != i)
                factor_sum[j] += tmp;
        }
    }


    for( i = 1000; i >= 1; i--)
    {
        if( factor_sum[i] <= 1000 && ans[factor_sum[i]] == 0)
            ans[factor_sum[i]] = i;//a[i].num;
    }

    while( scanf("%d",&n) && n)
    {
        if( ans[n] )
            printf("Case %d: %d\n",cas++,ans[n]);
        else
            printf("Case %d: -1\n",cas++);
    }

    return 0;
}

