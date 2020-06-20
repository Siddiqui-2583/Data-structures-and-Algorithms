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

int parent[26],Rank[26];

void Make_Set(int x){
    parent[x]=x;
    Rank[x]=0;
}

int Find(int x){
    if(x!=parent[x])
        parent[x]=Find(parent[x]);
    return parent[x];
}
//union by rank
int Union(int &x, int &y){
    int PX=Find(x);
    int PY=Find(y);

    if(Rank[PX]>Rank[PY])
        parent[PY]=PX;
    else{
        parent[PX]=PY;
        if(Rank[PX]==Rank[PY])
            Rank[PY]++;
    }
}

int main(){
    int T,n,x,y,ans;
    char c;
    string s;

    scanf("%d\n\n",&T);


    for(int tc=1;tc<=T;tc++){
        getline(cin,s);
        n=s[0]-'A'+1;

        ans=n;
        for(int i=0;i<n;i++)
            Make_Set(i);

        while(1){
         if(!getline(cin,s) || s.empty()) break;


            x=s[0]-'A';
            y=s[1]-'A';

            if(Find(x)!=Find(y)){
                Union(x,y);
                ans--;
            }
        }


        cout<<ans<<lne;
    }

    return 0;
}
