#include <bits/stdc++.h>
using namespace std;

class solution
{
    public:
    vector<int>dijkstra(int v,vector<vector<int>>adj[],int s)
    {
        vector<bool>explored(v,0);
        vector<int>dist(v,INT_MAX);
        dist[s]=0;
        int cnt=v;

        while(cnt--)
        {
            int node=-1,val=INT_MAX;
            for(int i=0;i<v;i++)
            {
                if(!explored[i] && val>dist[i])
                {
                    node=i;
                    val=dist[i];
                }
            }
            if(node==-1)
            break;
            explored[node]=1;

            for(int j=0;j<adj[node].size();j++)
            {
                int neighbour=adj[node][j][0];
                int weight=adj[node][j][1];

                if(!explored[neighbour] && dist[node]+weight<dist[neighbour])
                {
                    dist[neighbour]=dist[node]+weight;
                }
            }
        }
        return dist;
    }
};

int main()
{
    int v=5;
    vector<vector<int>>adj[v];

    adj[0].push_back({1,2});
    adj[0].push_back({4,1});
    adj[1].push_back({2,3});
    adj[2].push_back({3,6});
    adj[4].push_back({2,2});
    adj[4].push_back({3,1});

    solution obj;
    vector<int>res=obj.dijkstra(v,adj,0);

    cout<<"Shortest dist from:\n";
    for(int i=0;i<v;i++)
    cout<<"Node"<<i<<"->"<<res[i]<<"\n";
}