#include<bits/stdc++.h>
using namespace std;

class graph
{
    private:
    int v;
    vector<vector<int>> adjmat;

    public:
    graph(int V)
    {
        v=V;
        adjmat.resize(v,vector<int>(v,0));
    }

    void eg(int u,int v)
    {
        adjmat[u][v]=1;
        adjmat[v][u]=1;
    }

    void dfs(int i)
    {
        vector<bool>visited(v,false);
        stack<int> s;
        s.push(i);
        while(!s.empty())
        {
            int current=s.top();
            s.pop();
            if(!visited[current])
            {
                visited[current]=true;
                cout<<current<<" ";
            }
            for(int j=v-1;j>=0;j--)
            {
                if(adjmat[current][j]&& !visited[j])
                    s.push(j);
            }
        }
    }

    void dfs_rec(int i,vector<bool>& visited)
    {
        cout<<i<<" ";
        visited[i]=true;
        for(int j=0;j<v;j++)
        {
            if(!visited[j]&& adjmat[i][j]==1)
            dfs_rec(j,visited);
        }
    }

    void bfs(int i)
    {
        vector<bool> visited(v,false);
        queue<int> q;
        visited[i]=true;
        q.push(i);
        while(!q.empty())
        {
            int current=q.front();
            q.pop();
            cout<<current<<" ";
            for(int j=0;j<v;j++)
            {
                if(adjmat[current][j]==1 && !visited[j])
                {
                    visited[j]=true;
                    q.push(j);
                }
            }
        }
    }

    bool isctd() 
    {
        vector<bool>visited(v,false);
        dfs_rec(0,visited);
        for(int i=0;i<v;i++) 
        {
            if(!visited[i])
            return false;
        }
        return true;
    }

    int ctdcmp() 
    {
        vector<bool>visited(v,false);
        int cnt=0;
        for(int i=0;i<v;i++) 
        {
            if(!visited[i])
            {
                dfs_rec(i,visited);
                cnt++;
                cout<<endl;
            }
        }
        return cnt;
    }
};

int main()
{
    int v,e;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    cout<<"Enter the number of edges: ";
    cin>>e;

    graph g(v);

    cout<<"\nEnter the edges (u v) for the undirected graph:"<<endl;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        g.eg(u,v);
    }

    cout<<"\nDFS Non-Recursive traversal: ";
    g.dfs(0);
    cout<<endl;

    cout<<"DFS Recursive traversal: ";
    vector<bool>visited(v,false);
    g.dfs_rec(0,visited);
    cout<<endl;

    cout<<"BFS traversal: ";
    g.bfs(0);
    cout<<endl;
}
