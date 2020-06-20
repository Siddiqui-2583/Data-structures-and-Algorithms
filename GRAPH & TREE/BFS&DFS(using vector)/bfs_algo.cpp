#include <bits/stdc++.h>

using namespace std;

#define white 1
#define grey  2
#define black 3



vector <int> vec[10];
vector <int> color;
vector <int> distance;
vector <int> parent;

queue <int> q;
int Node,Edge;

void bfs (int s)
{
    int u,i,v,Size;

    color[s] = grey;
    q.push(s);

    while (!(q.empty())){

        u = q.front();
        q.pop();

        cout<<u<<" ";

        Size = vec[u].size();

        for (i=0;i<Size;i++) {
            v = vec[u][i];

            if (color[v]==white) {
                q.push(v);
                color[v] = grey;
            }
        }
    }
}
int main ()
{
    int i,j;
    int n1,n2;

    freopen("input.txt","r",stdin);

    cin  >> Node;
    cin  >> Edge;

    for (i=0;i<Edge;i++) {

        cin>>n1>>n2;
        vec[n1].push_back(n2);
        vec[n2].push_back(n1);
    }

    color.push_back(1);
    //coloring all nodes white
    for (i=1;i<=Node;i++) {
        color.push_back(white);
    }

    //print_connected_nodes ();

    bfs (1);

    return 0;
}
