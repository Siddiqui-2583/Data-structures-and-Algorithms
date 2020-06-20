#include<bits/stdc++.h>
#define ll long long
//#define clr(arr, 0) memset(arr, 0, sizeof(arr))
#define vll vector<long long>
#define lne '\n'
#define spc ' '
#define fst first
#define sec second
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileopen system("input.txt"); freopen("input.txt","r",stdin); FILE *f=freopen("output.txt","w",stdout);
#define fileclose fclose(f); system("output.txt");
using namespace std;

int parent[5005],Rank[5005];


void Make_Set(int x){
    parent[x]=x;
    Rank[x]=1;
}

int Find(int x){
    if(x!=parent[x])
        parent[x]=Find(parent[x]);
    return parent[x];
}
//union by rank
int Union(int x, int y){
     x=Find(x);
     y=Find(y);

    if(x!=y)
    {
        parent[x]=y;
        Rank[y]+=Rank[x];
    }
}


int main()
{
    int C,R;
    while(scanf("%d %d", &C, &R) == 2 && C)
    {
        map<string,int>M;
        for(int i=1;i<=C;i++)
        {
            string s;
            cin>>s;
            M[s]=i;
            Make_Set(i);
        }
        for(int i=1;i<=R;i++)
        {
            string s1,s2;
            cin>>s1>>s2;
            int j,k;
            j=M[s1];
            k=M[s2];
            Union(j,k);
    }

     int ans = 0;
     for(int i = 1; i <= C; i++)
        {
            ans=max(Rank[i],ans);
        }
        cout<<ans<<endl;
    }
}
