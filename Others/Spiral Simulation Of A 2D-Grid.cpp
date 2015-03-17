#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string.h>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define nln        puts("")                         ///printnewline
#define getInt(a)  scanf("%d",&a)
#define Max(a,b,c) max(a,max(b,c))                  ///3 ta theke max
#define Min(a,b,c) min(a,min(b,c))                  ///3 ta theke min
#define sqr(x)     (x)*(x)

#define Z(x) x<EPS
#define iqu(x,y) Z(fabs(x-y))

#define FOR1(i,n)  for(i=1;i<=n;i++)
#define FOR0(i,n)  for(i=0;i<n;i++)                 ///looping
#define FORR(i,n)  for(i=n-1;i>=0;i--)
#define ALL(p)     p.begin(),p.end()

#define SET(p)     memset(p,-1,sizeof(p))
#define CLR(p)     memset(p,0,sizeof(p))            ///memset
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

#define check(n, pos) (n & (1<<(pos)))       ///AND
#define biton(n, pos) (n | (1<<(pos)))       ///OR     }-bit opr.
#define bitoff(n, pos) (n & ~(1<<(pos)))     ///OFF

#define dbg(x) cout <<"Line= "<<__LINE__ <<" ->  "<< #x " = " << (x) << endl;

void CI(int &_x)
{
    scanf("%d",&_x);
}
void CI(int &_x,int &_y)
{
    CI(_x);
    CI(_y);
}
void CI(int &_x,int &_y,int &_z)
{
    CI(_x);
    CI(_y,_z);
}
void CI(int &_a,int &_b,int &_c,int &_d)
{
    CI(_a,_b);
    CI(_c,_d);
}

template<typename T> void getarray(T a[],int b,int e)
{
    for(int i=b; i<e+b; i++)
        cin>>a[i];
}
template<typename T> void printarray(T a[],int b,int e)
{
    for(int i=b; i<e-1+b; i++)
        cout<<a[i]<<" ";
    cout<<a[e-1+b]<<endl;
}
template <typename T> T BigMod (T b,T p,T m)
{
    if (p == 0)
        return 1;
    if (p%2 == 0)
    {
        T s = BigMod(b,p/2,m);
        return ((s%m)*(s%m))%m;
    }
    return ((b%m)*(BigMod(b,p-1,m)%m))%m;
}
template <typename T> T ModInv (T b,T m)
{
    return BigMod(b,m-2,m);
}
template<class T> inline void read(T &x)
{
    bool Minus=0;
    char c;
    for(c=getchar(); c<=32; c=getchar())
        ;
    if(c=='-')
        Minus=1,c=getchar();
    for(x=0; c>32; c=getchar())
        x=x*10+c-'0';
    if(Minus)
        x=-x;
};
char getc()
{
    char c;
    for(c=getchar(); c<=32; c=getchar())
        ;
    return c;
}

const double EPS=1e-9;                       ///constatnts
const int INF=0x7f7f7f7f;

int dr8[8]= {1,-1,0,0,1,-1,-1,1};            ///8 direction move
int dc8[8]= {0,0,-1,1,1,1,-1,-1};
int dr4[4]= {0,0,1,-1};                      ///4 direction move
int dc4[4]= {-1,1,0,0};                      ///or adjacent dir.
int kn8r[8]= {1,2,2,1,-1,-2,-2,-1};          ///knight moves
int kn8c[8]= {2,1,-1,-2,-2,-1,1,2};

string dec2bin(int n)
{
    string str="";
    int bin=0,base=1;
    while(n)
    {
        int rem=n%2;
        n/=2;
        str+=(rem+'0');
    }
    reverse(str.begin(),str.end());
    while(str.size()!=5)
    {
        str='0'+str;
    }
    return str;
}

string str2bin(char *str)
{
    string S="";
    for(int i=0; i<strlen(str); i++)
    {
        if(str[i]==' ')
            S+=dec2bin(0);
        else if(str[i]>='A'&&str[i]<='Z')
            S+=dec2bin(str[i]-64);
    }
    return S;
}

int main()
{
    int T,ks=1,i,j,k;
    char str[100];
    int R,C;
    CI(T);
    while(T--)
    {
        CI(R,C);
        getchar();
        gets(str);

        string coded=str2bin(str);

        //spiral visiting on mat[25][25] grid starts here
        int mat[25][25];
        int ups=1,upe=C,upI=1;
        int rts=2,rte=R,rtI=C;
        int los=C-1,loe=1,loI=R;
        int lts=R-1,lte=2,ltI=1;
        int idx=0,len=coded.size();
        while(1)
        {
            if(ups>upe)
                break;
            for(i=ups; i<=upe; i++)
            {
                if(idx<len)
                    mat[upI][i]=coded[idx++]-'0';
                else mat[upI][i]=0;
            }
            ups++;
            upe--;
            upI++;

            if(rts>rte)
                break;
            for(i=rts; i<=rte; i++)
            {
                if(idx<len)
                    mat[i][rtI]=coded[idx++]-'0';
                else mat[i][rtI]=0;
            }
            rts++;
            rte--;
            rtI--;

            if(los<loe)
                break;
            for(i=los; i>=loe; i--)
            {
                if(idx<len)
                    mat[loI][i]=coded[idx++]-'0';
                else mat[loI][i]=0;
            }
            los--;
            loe++,loI--;

            if(lts<lte)
                break;
            for(i=lts; i>=lte; i--)
            {
                if(idx<len)
                    mat[i][ltI]=coded[idx++]-'0';
                else mat[i][ltI]=0;
            }
            lts--;
            lte++;
            ltI++;
        }
        //spiral visiting ENDs
/*

1 -> 2 -> 3 -> 4
               v
5 -> 6 -> 7    8
^         v    v
9    a <- b    c
^              v
d <- e <- f <- g

*/

        cout<<ks++<<" ";
        for(i=1; i<=R; i++)
        {
            for(j=1; j<=C; j++)
            {
                cout<<mat[i][j];
            }
        }
        nln;
    }
}

