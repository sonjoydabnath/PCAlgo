///Articulation Points Finding in a Graph
#include<iostream>
#include<vector>
using namespace std;

vector<int> G[10002];
bool articpoints[10002];
int visited[10002];
int start[10002],low[10002];
int Time;

void ArticulationPoint(int u,int par=-1)
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
            ArticulationPoint(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=start[u])
                articpoints[u]=1; ///u is a articulation point
        }
    }
    if(par==-1)                  ///if it's the root of dfs tree
        articpoints[u]=child>1?1:0; /// if root have more than one child root is artic. point itself.
}
int main()
{
    //
    //memset by zero -> visited[],articpoints[]
    //set Time=0;
    //Then call the function in a graph
    return 0;
}
