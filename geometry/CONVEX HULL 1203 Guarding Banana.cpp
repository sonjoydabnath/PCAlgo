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

const double EPS=1e-10;                       ///constatnts
const int INF=0x7f7f7f7f;

#define nln        puts("")                         ///printnewline
#define getInt(a)  scanf("%d",&a)
#define Max(a,b,c) max(a,max(b,c))                  ///3 ta theke max
#define Min(a,b,c) min(a,min(b,c))                  ///3 ta theke min

#define Z(x) (x < EPS)
#define iqu(x,y) Z(fabs(x-y))
#define sqr(x) ((x)*(x))

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

int dr8[8]= {1,-1,0,0,1,-1,-1,1};            ///8 direction move
int dc8[8]= {0,0,-1,1,1,1,-1,-1};
int dr4[4]= {0,0,1,-1};                      ///4 direction move
int dc4[4]= {-1,1,0,0};                      ///or adjacent dir.
int kn8r[8]= {1,2,2,1,-1,-2,-2,-1};          ///knight moves
int kn8c[8]= {2,1,-1,-2,-2,-1,1,2};

struct Vector
{
    double x,y;
    void scan()
    {
        scanf("%lf %lf",&x,&y);
    }
    void print()
    {
        printf("(%lf,%lf)\n",x,y);
    }
    Vector(double x=0,double y=0)
    {
        this->x=x;
        this->y=y;
    }
    double mag2()
    {
        return sqr(x)+sqr(y);
    }
    double mag()
    {
        return sqrt(mag2());
    }
};

double dotp(Vector a, Vector b)
{
    return a.x*b.x+a.y*b.y;
}
double crossp(Vector a, Vector b)
{
    return a.x*b.y - a.y*b.x;
}
Vector operator-(Vector a,Vector b)
{
    return Vector(a.x-b.x, a.y-b.y);
}

int Turn(Vector &V0,Vector &V1,Vector &V2)
{
    double v=crossp((V1-V0),(V2-V0));
    if(fabs(v)<EPS)return 0;
    if(v>0)return 1;
    return -1;
}

Vector V[100007];
int hull[100007];

bool cmp(Vector V1,Vector V2)
{
    int t=Turn(V[0],V1,V2);
    if(!t)
    {
        return (V1-V[0]).mag2()<(V2-V[0]).mag2();
    }
    return t>0;
}

int cHull(int N)
{
    int loleft=0,i=0,top=0;
    if(N<=2)
    {
        hull[top++]=0;
        if(N==2)
            hull[top++]=1;
        return top;
    }
    for(i=1; i<N; i++)
    {
        if(V[loleft].y==V[i].y)
        {
            if(V[loleft].x>V[i].x)
                loleft=i;
        }
        if(V[loleft].y>V[i].y)
            loleft=i;
    }
    swap(V[0],V[loleft]);
    sort(V+1,V+N,cmp);
    hull[top++]=0;
    hull[top++]=1;
    for(i=2; i<N; i++)
    {
        while(Turn(V[hull[top-2]],V[hull[top-1]],V[i])<1&&top>1)
            top--;
        hull[top++]=i;
    }
    return top;
}

double angel_b2in(Vector v0,Vector v1,Vector v2)
{
    double p=dotp(v0-v1,v2-v1);
    double mmag=(v0-v1).mag()*(v2-v1).mag();
    if(Z(mmag))
        return 0.0;
    //dbg(p);dbg(mmag);
    double theta=(acos(p/mmag));
    //dbg(theta);
    int f=(theta/(2*PI));
    //dbg(f);
    theta=theta-(f*2*PI);
    //dbg(theta);
    return theta;
}

int main()
{
    //READ("in.txt");
    int T,ks=1,N,i,top;
    double d;
    //cout<<d<<endl;
    //cout<<sin(d)<<endl;
    CI(T);
    while(T--)
    {
        CI(N);
        for(i=0; i<N; i++)
            V[i].scan();
        int top=cHull(N);
        hull[top]=hull[0];
        double ans=2*PI;
        for(i=0; i<top; i++)
        {
            double angl=angel_b2in(V[hull[i]],V[hull[(i+1)%top]],V[hull[(i+2)%top]]);
            //ans+=(V[hull[i]]-V[hull[i+1]]).mag();
            ans=min(ans,angl);
        }
        ans=(180*ans)/PI;
        cout<<"Case "<<ks++<<": ";
        printf("%.10lf\n",ans);
    }
    return 0;
}


