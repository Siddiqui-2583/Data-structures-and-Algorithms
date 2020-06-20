// program for 0-1 Knapsack problem
#include <bits/stdc++.h>
using namespace std;
int capacity;
int n;
struct Item{
    int val;
    int wt;
};
vector<Item>vec;
void printknapSack()
{
    int i, j;
    int mat[n + 1][capacity + 1];

    for (i = 0; i <= n; i++)
        {
        for (j = 0; j <= capacity; j++)
         {
            if (i == 0 || j == 0)
            {
                mat[i][j] = 0;
            }
            else if (vec[i - 1].wt <= j)
            {
                mat[i][j] = max( vec[i - 1].val +  mat[i - 1][j - vec[i - 1].wt ] , mat[i - 1][j]);
            }
            else
            {
                //initial with value of previous row
                 mat[i][j] = mat[i - 1][j];
            }

        }
    }
     for (i = 0; i <= n; i++)
        {
        for (j = 0; j <= capacity; j++)
         {
              cout<<mat[i][j]<<" ";
         }
         cout<<endl;
         }
    // stores the result of Knapsack
    int res = mat[n][capacity];
    printf("%d\n", res);

    j = capacity;
    for (i = n; i > 0 && res > 0; i--) {
        if (res != mat[i - 1][j])
        {
            // This item is included.
            printf("%d kg ", vec[i - 1].wt);

            j = j - vec[i - 1].wt;
            res=mat[i-1][j];
        }
    }
    cout<<"included"<<endl;
}
int main()
{
   cout<<"Enter the number of items:  ";
   cin>>n;
   cout<<"Enter the capacity:  ";
   cin>>capacity;

   for(int i=0;i<n;i++)
   {
       int val,wt;
       cin>>val>>wt;
       Item get;
       get.val=val;
       get.wt=wt;
       vec.push_back(get);
   }

    printknapSack();

    return 0;
}
