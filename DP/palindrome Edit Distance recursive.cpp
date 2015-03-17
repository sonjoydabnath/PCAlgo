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
int N,K,nums[10005];
int Recur(int cost,int p,int q)
{
       if(p>=q || cost>K)  return cost;
       else
       {
          if(nums[p]==nums[q])
          return Recur(cost,p+1,q-1);
          else
          return min(Recur(cost+1,p,q-1),Recur(cost+1,p+1,q));
       }

}

int main()
{
    int kase,i,j,cas;
    cin>>kase;
    for(cas=1;cas<=kase;cas++)
    {
        cin>>N>>K;
        for(i=0;i<N;i++)
            scanf("%d",&nums[i]);
        int cost=Recur(0,0,N-1);
        printf("Case %d: ",cas);
        if(cost==0)printf("Too easy\n");
        else if(cost>K)printf("Too difficult\n");
        else printf("%d\n",cost);
    }
}
