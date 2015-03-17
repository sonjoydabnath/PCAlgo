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
int cnt;                     ///swap operation koyta holo ta count korte caile


vector<int> marge(const vector<int> &left_V,const vector<int> &right_V)
{
    vector<int> result;
    int left_size=left_V.size();
    int right_size=right_V.size();
    int left_idx=0;
    int right_idx=0;

    while(left_idx<left_size&&right_idx<right_size)
    {
        if(left_V[left_idx]<right_V[right_idx])
        {
            result.push_back(left_V[left_idx]);
            left_idx++;

            //cnt+=(right_size-right_idx);
        }
        else
        {
            result.push_back(right_V[right_idx]);
            right_idx++;

            cnt+=(left_size-left_idx);           ///swap operation koyta holo ta count korte caile
        }
    }

    while(left_idx<left_size)
    {
        result.push_back(left_V[left_idx]);
        left_idx++;
    }

    while(right_idx<right_size)
    {
        result.push_back(right_V[right_idx]);
        right_idx++;
    }

    return result;
}


vector<int> merge_sort(vector<int> &vec)
{
    if(vec.size()==1)return vec;

    vector<int>::iterator middle=vec.begin()+(vec.size()/2);

                                                ///২ ভাগ করা হলে ভাগ ২ টি কে জোড়া লাগানো র জন্য
    vector<int>leftV(vec.begin(),middle);
    vector<int>rightV(middle,vec.end());

    leftV=merge_sort(leftV);
    rightV=merge_sort(rightV);

    return marge(leftV,rightV);          ///merge func কে কল করে জোড়া লাগায়ে ভেক্টর কে রিটারন করা

}



int main()
{
    vector<int>number;
    int n,kase,a;
    while(cin>>n)
    {
        if(n==0)
            break;
        number.clear();
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a);
            number.push_back(a);
        }

        cnt=0;          ///swap operation koyta holo ta count korte caile

        vector<int> res = merge_sort(number);

        for(int i=0,sz=res.size(); i<sz; i++)
            cout<<res[i]<<" ";
        cout<<endl;

        cout<<"Number Of sawp operation: "<<cnt<<endl;   ///swap operation koyta holo ta count korte caile
    }
    return 0;
}

