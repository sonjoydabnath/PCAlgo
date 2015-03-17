/******************************/
/**      SONJOY DABNATH        **/
/** University Of Chittagong, BD >>/
/**   CSE 12th batch(11-12)    **/
/******************************/
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
#include <stack>
#include <list>
#include <algorithm>
using namespace std;

#define nln        puts("")                         ///printnewline
#define Max(a,b,c) max(a,max(b,c))                  ///3 ta theke max
#define Min(a,b,c) min(a,min(b,c))                  ///3 ta theke min

#define FOR1(i,n)  for(i=1;i<=n;i++)
#define FOR0(i,n)  for(i=0;i<n;i++)                 ///looping
#define FORR(i,n)  for(i=n-1;i>=0;i--)
#define ALL(p)     p.begin(),p.end()

#define SET(p)     memset(p,-1,sizeof(p))
#define CLR(p)     memset(p,0,sizeof(p))          ///memset
#define MEM(p,v)   memset(p,v,sizeof(p))

#define READ(f)    freopen(f, "r", stdin)           /// file
#define WRITE(f)   freopen(f, "w", stdout)

#define SZ(c)      (int)c.size()
#define PB(x)      push_back(x)                     ///STL defines
#define MP(x,y)    make_pair(x,y)
#define ff         first
#define ss         second

#define LI         long int
#define LLI        long long int
#define f64        long double
#define PI         acos(-1.0)                        ///PI er value

template<typename T> void getarray(T a[],int n)
{
    for(int i=0; i<n; i++) cin>>a[i];
}
template<typename T> void printarray(T a[],int n)
{
    for(int i=0; i<n-1; i++) cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
}

const double EPS=1e-9;                              ///constatnts
const int INF=0x7f7f7f7f;

int dr8[8]= {1,-1,0,0,1,-1,-1,1};            ///8 direction move
int dc8[8]= {0,0,-1,1,1,1,-1,-1};
int dr4[4]= {0,0,1,-1};                      ///4 direction move
int dc4[4]= {-1,1,0,0};                      ///or adjacent dir.
int kn8r[8]= {1,2,2,1,-1,-2,-2,-1};          ///knight moves
int kn8c[8]= {2,1,-1,-2,-2,-1,1,2};

int main()
{
    //READ("input.txt");
    int kase,i,j,k,r,len;
    char str[]= {'a','b','c','d'};
    bool first=0;
    int mask,x;
    string result;
    vector<string> resultfinal;

    for(i=(1<<4)-1; i>=0; i--)
        {
            for(j=0; j<4; j++)
                {
                    if(((1<<j)&i)!=0)
                        result+=(str[j]);
                }
            resultfinal.push_back(result);
            result.clear();
        }
    for(i=0; i<16; i++)
        cout<<resultfinal[i]<<endl;
    return 0;
}
