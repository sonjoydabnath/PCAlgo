#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
int cost[1000][1000];
vector<int> G[1000];
int visit[1000];
struct data{
    int x,y,cost;
    bool operator < ( const data& p ) const
    {
        return cost > p.cost;
    }
};
priority_queue<data> pq;
int main()
{
    int u,v,i,value,n,j,k,edg,s=0;
    int start;
    printf("Enter nodes & edgs?\n");
    scanf("%d%d",&n,&edg);
    for(i=0;i<edg;i++)
    {
        scanf("%d%d%d",&u,&v,&value);
        G[u].push_back(v);
        G[v].push_back(u);
        cost[u][v]=value;
        cost[v][u]=value;
    }
    printf("Enter starting node\n");
    scanf("%d",&start);
    visit[start]=2;
    n--;
    for(i=0;i<G[start].size();i++)
    {
        data p;
        v=G[start][i];
        p.x=start;
        p.y=v;
        p.cost=cost[start][v];
        pq.push(p);
    }
    while(n)
    {
        data q;
        while(!pq.empty())
        {
            q=pq.top();
            pq.pop();
            if(visit[q.x]!=visit[q.y])
                break;
        }
        if(!visit[q.y]) k=q.y;
        visit[k]=2;
        printf("%d %d %d\n",q.x,q.y,q.cost);
        n--;
        s+=q.cost;
        for(i=0;i<G[k].size();i++)
        {
            data p;
            v=G[k][i];
            if(visit[v]) continue;
            //cout<<"ak"<<" "<<v<<endl;
            p.x=k;
            p.y=v;
            p.cost=cost[k][v];
            pq.push(p);
        }
    }
    printf("Total cost %d\n",s);
    return 0;
}
