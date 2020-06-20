#include <bits/stdc++.h>

using namespace std;

#define white 1
#define grey  2
#define black 3

vector <int> vec[10];
vector <int> color;

int node,edge;
map<int,string>M1;
map<string,int>M;
vector<pair<string,string> >vp;

void dfs (int u)
{
    int i,n1,v;

    color[u] = grey;

    n1 = vec[u].size();     //s denotes the number of adjacent of u

    for (i=0;i<n1;i++) {
        v = vec[u][i];

         if (color[v]==white) {
            dfs(v);
        }

    }
     color[u] = black;

     cout<<u<<" ";
     cout<<M1[u]<<" ";

}



int main ()
{
    int i,j;
    int n1,n2;

    //freopen("input.txt","r",stdin);
    cin >> node>>edge;

    int n=0;
    for (i=0;i<edge;i++) {
        //cin>>n1>>n2;

        string s1,s2;
        cin>>s1>>s2;
        vp.push_back(make_pair(s1,s2));

        if(M.find(s1)==M.end()){
                M[s1]=n;
                M1[n]=s1;
                n++;
        }
        if(M.find(s2)==M.end()){
                M[s2]=n;
                M1[n]=s2;
                n++;
            }
        //vec[n1].push_back(n2);
        //vec[n2].push_back(n1);
    }
    for(auto x:vp)
    {
        //cout<<x.first<<" "<<x.second<<endl;
        n1=M[x.first];
        n2=M[x.second];

        cout<<n1<<" "<<n2<<endl;
        vec[n1].push_back(n2);
        vec[n2].push_back(n1);
    }
    /// coloring all nodes in white

    for (i=0;i<node;i++) {
        color.push_back(white);
    }
     for (i=0;i<node;i++)
        {
            if(color[i]==white)
                dfs(i);
        }


}

