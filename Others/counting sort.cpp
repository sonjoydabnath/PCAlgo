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

#define nln        puts("")                         /// print newline
#define Max(a,b,c) max(a,max(b,c))                  ///3 ta theke max
#define Min(a,b,c) min(a,min(b,c))                  ///3 ta theke min

#define FOR1(i,n)  for(i=1;i<=n;i++)
#define FOR0(i,n)  for(i=0;i<n;i++)                 ///looping
#define FORR(i,n)  for(i=n-1;i>=0;i--)
#define ALL(p)     p.begin(),p.end()

#define SET(p)     memset(p, -1, sizeof(p))
#define CLR(p)     memset(p, 0, sizeof(p))          ///memset
#define MEM(p,v)   memset(p, v, sizeof(p))

#define READ(f)    freopen(f, "r", stdin)           /// file
#define WRITE(f)   freopen(f, "w", stdout)

#define SZ(c)      (int)c.size()
#define PB(x)      push_back(x)                     ///STL defines
#define MP(x,y)    make_pair(x, y)
#define ff         first
#define ss         second

#define i64        long long int
#define f64        long double
#define PI         acos(-1.0)                        ///PI er value

const double EPS = 1e-9;                        ///constatnts
const int INF = 0x7f7f7f7f;

int dr8[8]= {1,-1,0,0,1,-1,-1,1};            ///8 direction move
int dc8[8]= {0,0,-1,1,1,1,-1,-1};
int dr4[4]= {0,0,1,-1};                      ///4 direction move
int dc4[4]= {-1,1,0,0};                      ///or adjacent dir.


int main()
{
    int arra[1000],nums[101],n,i,j,k;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&arra[i]);

    for(i=0; i<101; i++)
        nums[i]=0;              ///initialaizing
    for(i=0; i<n; i++)
        nums[arra[i]]++;        ///nums array te rakha hobe kon number ta kotobar ache .
    for(i=0; i<101; i++)
    {
        for(j=0; j<nums[i]; j++) ///ze sonkha ta zoto bar ache seta toto bar print hobr . zero bar thakle print hobe nah
            printf("%d ",i);
    }
}

///constraint: positive number sort kora zabe .
///nums array er size zoto tar ceye coto ba soman maner element nite hobe , ta na hole RTE hobe
///ekhane nums array er size 101 tai eta diye 100 er soman ba 100 er choto number k sort kora zabe  .  eta k change kore dile boro number o sort kora zabe .
