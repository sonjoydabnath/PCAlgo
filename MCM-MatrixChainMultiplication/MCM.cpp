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
#define i64        long long int
#define f64        long double
#define PI         acos(-1.0)                        ///PI er value

#define check(n, pos) (bool)(n & (1LL<<(pos)))       ///AND
#define biton(n, pos) (n | (1LL<<(pos)))       ///OR     }-bit opr.
#define bitoff(n, pos) (n & ~(1LL<<(pos)))     ///OFF

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

long long MOD;

struct Matrix
{
    long long mat[2][2];
    //Initiate the matrix
    void initiate()
    {
        mat[0][0]=1;
        mat[0][1]=1;
        mat[1][0]=1;
        mat[1][1]=0;
    }
    //Build Identity Matrix
    void I_matrix()
    {
        mat[0][0]=1;
        mat[0][1]=0;
        mat[1][0]=0;
        mat[1][1]=1;
    }
    Matrix operator * (const Matrix &A) const
    {
        Matrix ret;
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++)
            {
                ret.mat[i][j]=0;
                for(int k=0; k<2; k++)
                    ret.mat[i][j]+=(mat[i][k]*A.mat[k][j]);
                ret.mat[i][j]%=MOD;
            }
        }
        return ret;
    }
    void showMatrix()
    {
        puts("------");
        cout<<"|"<<mat[0][0]<<"  "<<mat[0][1]<<"|"<<endl;
        cout<<"|"<<mat[1][0]<<"  "<<mat[1][1]<<"|"<<endl;
        puts("------");
    }
};

Matrix PowerMatrix_BigMod(Matrix A,int P)
{
    if(P==0)
    {
        //base case , return the Identity Matrix
        Matrix temp;
        temp.I_matrix();
        return temp;
    }

    if(P%2==1)
        return A*PowerMatrix_BigMod(A,P-1);

    Matrix temp=PowerMatrix_BigMod(A,P/2);
    return temp*temp;
}



// this is to Find nth Fibonacci Modulo by MOD , UVA 10229
int main()
{
//#ifndef ONLINE_JUDGE
//    READ("in.txt");
//#endif
    int n,m;
    MOD=1<<20;
    Matrix A,I,B;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        MOD=1<<m;
        A.initiate();
        //B=PowerMatrix_BigMod(A,n-1);  //return nth power Matrix of given matrix A;
        //B.showMatrix();
        if( (n==0) || (n==1&&m==0) )
            puts("0");
        else
        {
            B=PowerMatrix_BigMod(A,n-1);
            printf("%lld\n",B.mat[0][0]);
        }
    }
    return 0;
}
