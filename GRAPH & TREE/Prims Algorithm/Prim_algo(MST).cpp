// STL implementation of modified Prims algorithm for MST
#include<bits/stdc++.h>
using namespace std;
# define INF 10001

vector <pair<int, int> > adj[1000];
int minimum_weight;

int n ;
void addEdge(int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));

}
void primMST()
{
    set<pair<int,int> >s;

    int src = 0;
    vector<int> key(n, INF);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    s.insert(make_pair(0, src));
    key[src] = 0;

    while (!s.empty())
    {
        auto it  = s.begin();
        int u=(it->second);
        s.erase(it);

        visited[u] = true;
        // Traverse all adjacent of u
        for (auto x : adj[u])
        {
            // Get vertex label and weight of current adjacent of u

            int v = x.first;
            int weight = x.second;

            // If v is not in MST and weight of (u,v) is smaller
            // than current key of v
            if (!visited[v] && key[v] > weight)
            {
                key[v] = weight;
                s.insert(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    // Print edges of MST using parent array
    for (int i = 1; i < n; ++i)
       {
                printf("%d - %d---%d\n", parent[i], i,key[i]);
                minimum_weight+=key[i];
       }

        cout<<"minimum weight: "<<minimum_weight<<endl;
}

int main()
{

    int m;
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            addEdge( u, v, w);

        }

    primMST();

    return 0;
}

