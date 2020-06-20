// STL implementation of modified Prims algorithm for MST
#include<bits/stdc++.h>
using namespace std;
# define INF 10001

vector <pair<int, int> > adj[1000];
int total_weight=0;
int minimum_weight;
int unused_weight;

map<string,bool>M;
int n ;
void addEdge(int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}
void primMST()
{

   // priority_queue< pair<int, int> , vector <pair<int, int> > , greater<pair<int, int> > > pq;
    set<pair<int,int> >s;

    int src = 0;
    vector<int> key(n, INF);
    vector<int> parent(n, -1);
    vector<int> parent1(n, -1);

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
                string U=to_string(parent[i]);
                string V=to_string(i);
                string U1=U+V;
                string U2=V+U;
                M[U1]=false;
                M[U2]=false;
                printf("%d - %d---%d\n", parent[i], i,key[i]);
                minimum_weight+=key[i];
       }

        cout<<"minimum weight: "<<minimum_weight<<endl;
        unused_weight=total_weight-minimum_weight;
        cout<<"unused weight: "<<unused_weight<<endl;
    for(auto it1: M)
    {
         string str=it1.first;
        reverse(str.begin(),str.end());
        if(M[str]==true)M[str]=false;
        if(it1.second==true)
        {

            cout<<it1.first<<endl;

        }
    }

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
        string U=to_string(u);
        string V=to_string(v);
        string U1=U+V;
        string U2=V+U;
        M[U1]=true;
        M[U2]=true;

        total_weight+=w;
         addEdge( u, v, w);
        }


    primMST();

    return 0;
}
