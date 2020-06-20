// Program to find Dijkstra's shortest path using STL set
#include<bits/stdc++.h>
using namespace std;
# define INF 10001

vector <pair<int, int> > adj[1000];
int n, m;

void addEdge(int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}
void shortest_path(vector<int>parent,int j)
{
     // If j is source
    if (parent[j] == - 1)
        {
            cout<<j<<" ";
            return;
        }


    shortest_path(parent, parent[j]);

    printf("%d ", j);
}
void min_cost(vector<int>dist,vector<int>parent)
{
    int src = 0;
    // Print shortest distances stored in dist[]
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
    {
         printf("\n%d -> %d \t\t %d \t", src, i, dist[i]);
         shortest_path(parent,i);
    }

}
void dizkstra()
{
    int src=0;

    set< pair<int, int> > s;
    vector<bool> visited(n, false);
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);

    s.insert(make_pair(0, src));
    dist[src] = 0;

    while (!s.empty())
    {
        auto it = s.begin();
        int u = it->second ;
        s.erase(it);
        visited[u] = true;

       for (auto x : adj[u])
        {

            int v = x.first;
            int weight = x.second;

            if (!visited[v]&& dist[u]!=INF && ( dist[v] > dist[u] + weight))
            {

                dist[v] = dist[u] + weight;
                s.insert(make_pair(dist[v], v));
                parent[v]=u;
            }
        }
    }
    min_cost(dist,parent);

}


int main()
{
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge( u, v, w);
    }
    dizkstra();
}
