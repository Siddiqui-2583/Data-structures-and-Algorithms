#include <bits/stdc++.h>

using namespace std;

#define white 1
#define grey  2
#define black 3

int node,edge;

vector <int> vec[10];
vector <int> color;
vector <int> dist;

void dfs (int u)
{
    int i,s,v;

    color[u] = grey;
    s = vec[u].size();

    for (i=0;i<s;i++) {
        v = vec[u][i];


        if (color[v]==white) {
            dist[v]=dist[u]+1;
            dfs(v);
        }
    }

    color[u] = black;
   // cout<<u<<" ";
}


int main ()
{
    int i,j;
    int n1,n2;

    freopen("input.txt","r",stdin);

    cin  >> node;
    cin  >> edge;

    for (i=0;i<edge;i++) {

        cin>>n1>>n2;
        vec[n1].push_back(n2);
        vec[n2].push_back(n1);
    }

    /// coloring all nodes in white

    for (i=0;i<=node;i++) {
        color.push_back(white);
        dist.push_back(0);
    }

  //  print_connected_nodes ();

    dfs(1);

    for(int i=1;i<=node;i++)
        cout<<"distance of "<<i<<" from source is: "<<dist[i]<<endl;
    return 0;
}

