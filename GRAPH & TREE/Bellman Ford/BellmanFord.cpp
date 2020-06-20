// Program to find Bellman Ford shortest path using STL set
#include<bits/stdc++.h>
using namespace std;
# define INF 10001

int node,edge;
 int src ,dest;
struct Edge {
    int u, v, w;

};
vector<Edge>vec;
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

    // Print shortest distances stored in dist[]
    printf("Vertex   Distance from Source\n");
    for (int i = 1; i < node; ++i)
    {
         printf("\n%d -> %d \t\t %d \t", src, i, dist[i]);
         shortest_path(parent,i);
    }

}
void print( vector<bool> color)
{
    for(int i = 0; i < node; i++) {
        if( color[i] ) {
            cout << i << " ";
        }
    }
    cout << endl;;
}

void bellmanFord()
{
    int src=1;

    vector<int> dist(node, INF);
    vector<int> parent(node, -1);

    dist[src] = 0;

    int ck=1;
    for(int i=0;i<node;i++)
    {
        ck=1;
            for (int j=0;j<edge;j++)
            {

               int u=vec[j].u;
               int v=vec[j].v;
               int weight=vec[j].w;

                if ( ( dist[v] > dist[u] + weight))
                {
                    dist[v] = dist[u] + weight;
                    parent[v]=u;
                    ck=0;
                }
            }
      }
      if(ck==1){
            cout<<"No negative cycle contains"<<endl;
            min_cost(dist,parent);
      }
      else{
        vector<bool> color(node,false);
        vector<pair<int,int> >vec_pair;
         cout<<"negative cycle contains"<<endl;
         for (int j=0;j<edge;j++)
            {

               int u=vec[j].u;
               int v=vec[j].v;
               int weight=vec[j].w;
               // cout<<u<<","<<v<<" "<<weight<<" -- "<<dist[u]<<" "<<dist[v]<<endl;;
                if ( color[u]==false && ( dist[v] > dist[u] + weight))
                {
                    dist[v] = dist[u] + weight;
                    color[u]=true;
                    cout<<u<<"-"<<v<<endl;
                    vec_pair.push_back(make_pair(u,v));
                }
            }
            print(color);

      }



}


int main()
{

    freopen("input.txt","r",stdin);
    cin >> node >> edge>>src>>dest;
    for (int i = 1; i <= edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Edge NODE;
        NODE.u=u;
        NODE.v=v;
        NODE.w=w;
        vec.push_back(NODE);
    }
    bellmanFord();
}
