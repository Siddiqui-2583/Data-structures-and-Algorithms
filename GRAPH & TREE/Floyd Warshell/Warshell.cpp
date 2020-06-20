// C Program for Floyd Warshall Algorithm
#include<bits/stdc++.h>
using namespace std;

#define INF 9999

int V,E;
int parent[100][100];

void printPath(int i,int j)
{
    vector<int>path;
    path.push_back(j);
    int dest=j;
       while(i!=j )
       {
           if(parent[i][j]==-1)break;
            else
            {
                j=parent[i][j];
                path.push_back(j);
            }
       }

    reverse(path.begin(),path.end());
    for(int i=0;i<path.size();i++)
    {
        if(path.size()==1 && path[i]==dest)cout<<"No path exists ";
        else cout<<path[i]<<" ";
    }


}

void printdistance(int dist[][100])
{

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout<<"INF ";
            else
                cout<<dist[i][j]<<" ";



        }
        printf("\n");
    }
}
void printParentMatrix()
{

     for (int i = 0; i < V; i++)
     {
          for (int j = 0; j < V; j++)
            {
                cout<<parent[i][j]<<" ";
            }
            cout<<endl;
     }
}
void AllPairshortestPath()
{
    for (int i = 0; i < V; i++)
     {
          for (int j = 0; j < V; j++)
            {
                if(i!=j)
                {
                    cout<<"Path from "<<i<<" to "<<j<<"  is:  ";
                    printPath(i,j);
                }
                cout<<endl;
            }
            cout<<endl;
     }
}
void floydWarshall (int dist[][100])
{
    for (int i = 0; i < V; i++)
     {
          for (int j = 0; j < V; j++)
            {
                if(dist[i][j]==0 || dist[i][j]==INF)
                    parent[i][j]=-1;
                else parent[i][j]=i;
            }
     }

    int  i, j, k;

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    parent[i][j]=parent[k][j];

                }

            }
        }
    }

    for (int i = 0; i < V; i++)
        {
            if (dist[i][i] < 0)
            {
                cout<<"Negative cycle detected"<<endl;
                return;
            }
        }

    cout<<"All pair shortest distance are: \n";
    printdistance(dist);

    cout<<"All pair shortest paths are\n";
    AllPairshortestPath ();
}


// driver program to test above function
int main()
{
     freopen("input.txt","r",stdin);
    int graph[100][100];
    cout<<"Enter the number of vertices: "<<endl;
     cin>>V;
     for (int i = 0; i < V; i++)
     {
          for (int j = 0; j < V; j++)
            {
                cin>> graph[i][j];
            }
     }

    floydWarshall(graph);



    cout<<"final parent matrix is: \n";
    printParentMatrix();
    return 0;
}
