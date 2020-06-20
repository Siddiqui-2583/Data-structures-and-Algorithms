#include <bits/stdc++.h>
#define MAX 25001
#define MAX1 1001
using namespace std;

struct edge {
    int u, v, w;

};
bool comp(edge x,edge y)
{
    return x.w < y.w;
}
int parent[MAX];
vector<edge> e;

void make_set(int x)
{
     parent[x] = x;
}
int find(int r)
{
    if(parent[r] == r)
        {
      return r;
    }
    else parent[r]=find(parent[r]);
}
int mst(int n)
{
    sort(e.begin(), e.end(),comp);

    for (int i = 1; i <= n; i++)
        {
            make_set(i);
           }
    int Count = 0;
    int s = 0;
    for (int i = 0; i < e.size(); i++) {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if (u != v) {
            parent[u] = v;
            Count++;
            s += e[i].w;
            if (Count == n - 1)
                break;
        }
    }

    for (int i = 0; i < n-1; ++i)
       {
            cout<<i<<"-"<<parent[i]<<endl;
       }
    return s;
}

int main()
{

    int n, m;
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        edge get;
        get.u = u;
        get.v = v;
        get.w = w;
        e.push_back(get);
    }
    cout <<"Minimum cost is: "<< mst(n) << endl;
    return 0;
}
