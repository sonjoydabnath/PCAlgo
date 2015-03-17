#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
# define MAX 10000
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    unsigned e,n,i,j;
    vector edge[MAX];
    vector cost[MAX];
    map in,out;
    scanf("%u %u",&n,&e);
    for(i=0; i<e; i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        edge[x].push_back(y);
        cost[x].push_back(1);
    }
    printf("Connected :\n");
    for(j=1; j<=n; j++)
    {
        printf("%d :",j);
        for(i=0; i < edge[j].size() ; i++)
        {
            in[edge[j][i]]++;
            printf("%d ",edge[j][i]);
        }
        cout<<endl;
        out[j]=edge[j].size();
    }
    printf("Indegree Outdegree: \n");
    for(j=1; j> %d out<< %d\n",j,in[j],out[j]);
            return 0;
        }
