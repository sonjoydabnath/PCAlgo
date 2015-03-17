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

#define MX 5000005
#define hi 2241
long prime[MX+5];
long factor[500],n_prime,table[MX+5];
void sieve()
{
    CLR(prime);
    prime[0]=0;
    prime[1]=0;

    for(int i=4; i<=MX; i+=2)
        prime[i]=2;

    table[0]=0;
    table[1]=0;
    table[2]=1;

    for(int i=3; i<=MX; i++)
    {
        table[i]=table[i-1];
        if(prime[i]==0)
        {
            for(int j=i+i; j<=MX; j+=i)
            {
                prime[j]+=i;
            }
            table[i]++;
        }
        else if(prime[prime[i]]==0)     ///Table array ta count kore deprime number so far
            table[i]++;
    }
}

/*************************************/
/**prime[] array ta store kore i er primefactor er sum**/
/**if prime[i]=m then i er prime factor gular sum=m**/
/**i.e.  prime[10]=7 cz 2x5=10 , so 2+5=7**/
/**i.e.  prime[12]=5 cz 2X2x3=12 , so 2+3=5**/
/**if any any factor has more then 1C times it 'll be count as 1C**/
/*************************************/
/*************************************/

int main()
{
    long a,b;
    sieve();


    for(int i=0; i<50; i++)
        cout<<i<<" "<<prime[i]<<" "<<table[i]<<endl;

    /*while(scanf("%ld",&a)&&a)      ///uva 11408 Deprime
    {
        scanf("%ld",&b);
        printf("%ld\n",table[b]-table[a-1]);
    }*/
    return 0;
}

