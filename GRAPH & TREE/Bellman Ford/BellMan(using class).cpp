#include<bits/stdc++.h>
using namespace std;
# define INF 10001

//vector <int> vec[100];
int parent[100];
int weight[100][100];
int node_value[100];
//bool visited[100];
//typedef pair <int,int>p;

class Adjacent{
    public:
         int u;
         int v;
         int w;
};
vector<Adjacent>myList;
//priority_queue < p ,vector < p > ,greater < p >  > pq;

int n,e;

void dijkstra(int startingnode)
{
    for(int i=0;i<n;i++)
    {
        node_value[i] = INF;
        parent[i] = -1;
    }

    node_value[startingnode]=0;
    for(int i=0;i<n-1;i++)
    {
            for (int j=0;j<e;j++)
            {
                int u=myList[j].u;
                int v=myList[j].v;
                int weight=myList[j].w;

                if (  ( node_value[v] > node_value[u] + weight))
                {
                    node_value[v] = node_value[u] + weight;
                    parent[v]=u;
                }

            }

    }
    for (int i=0;i<e;i++)
         {

             int u=myList[i].u;
             int v=myList[i].v;
             int weight=myList[i].w;

            if ( ( node_value[v] > node_value[u] + weight))
            {

                cout<<"Negative cycle "<<endl;
                return;
            }
        }


    cout<<"-----BELLMAN------"<<endl;
    for(int i=1;i<n;i++)
    {
        cout<<i<<"   "<<node_value[i]<<endl;
    }


}

int main()
{

    cout<<"Enter the number of node and edge: "<<endl;

    cin>>n;
    cin>>e;

    cout<<"Enter the starting point, ending point and weight of each edge: "<<endl;
    for(int i=1; i<=e; i++)
    {
        int u,v,w;
        cin>>u;
        cin>>v;
        cin>>w;

        Adjacent adj;

        adj.u=u;
        adj.v=v;
        adj.w=w;
        myList.push_back(adj);
    }


    int node=0;



    dijkstra(node);

    return 0;
}
