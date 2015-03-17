///Breaze Finding in a Graph
#include<iostream>
#include<vector>
using namespace std;

struct Edge
{
    int a,b;
    Edge() {}
    Edge(int aa,int bb): a(aa),b(bb) {}
};
vector<int> G[10002];
vector<Edge> BreazeList;
int visited[10002];
int start[10002],low[10002];
int Time;

void Breaze(int u,int par=-1)
{
    visited[u]=1;
    start[u]=low[u]=++Time;
    int v,child=0;
    for(int i=0; i<G[u].size(); i++)
    {
        v=G[u][i];
        if(v==par) continue;
        if(visited[v]) low[u]=min(low[u],start[v]);
        else
        {
            child++;
            Breaze(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>start[u])
                BreazeList.push_back(Edge(u,v)); ///u-v Edge is a Breeze
        }
    }
}
int main()
{
    //
    //memset by zero -> visited[], clear BreazeList
    //set Time=0;
    //then call Breaze(source,-1) function in a Graph
    return 0;
}
