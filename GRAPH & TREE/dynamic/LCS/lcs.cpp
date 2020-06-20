/* Dynamic Programming implementation of LCS problem */
#include <bits/stdc++.h>
using namespace std;

set<string> findLCS(string X, string Y, int m, int n,int *mat[][1000000])
{

    set<string> s;
    if (m == 0 || n == 0)
    {
        return s;
    }

    if (X[m - 1] == Y[n - 1])
    {
        set<string> tmp = findLCS(X, Y, m - 1, n - 1,mat);
        for (string str : tmp)
            s.insert(str + X[m - 1]);
    }

    // If the last characters of X and Y are not same
    else
    {
        if (mat[m - 1][n] >= mat[m][n - 1])
            {
                s = findLCS(X, Y, m - 1, n,mat);
            }
        if (mat[m][n - 1] >= mat[m - 1][n])
        {
            set<string> tmp = findLCS(X, Y, m, n - 1,mat);
            s.insert(tmp.begin(), tmp.end());
        }
    }
    return s;
}
void lcs(char X[], char Y[], int m, int n )
{
    int mat[m+1][n+1];
   for (int i=0; i<=m; i++)
   {
         for (int j=0; j<=n; j++)
         {
               if (i == 0 || j == 0)
               {
                   mat[i][j] = 0;
               }

               else if (X[i-1] == Y[j-1])
                 {
                     // diagonal value+1
                     mat[i][j] = mat[i-1][j-1] + 1;
                 }
               else
               {
                   // max of upper and left value
                   mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
               }

     }
   }

           //cout << "LCS of " << X << " and " << Y << " is " ;

           int result = mat[m][n];
           cout<<"longest common subsequence length:  "<<result<<endl;

           list<int>lcs;
           for(int i = m, j = n;i > 0 && j > 0;)
           {
              if (X[i-1] == Y[j-1])
              {
                  lcs.push_front(X[i-1]) ;
                  i--;
                  j--;
              }
              else if (mat[i-1][j] > mat[i][j-1])i--;
              else j--;
           }
        //printing all LCS
       // set<string> tmp=findLCS(X, Y, m, n,*mat);
        for(auto x:lcs)
        {
            cout<<x<<" ";
        }

  }
int main()
{

  int n,m;
  cin>>m>>n;
  char arr[m+1],arr1[n+1];
  for(int i=0;i<m;i++)
  {
      cin>>arr[i];
  }
  for(int i=0;i<n;i++)
  {
      cin>>arr1[i];
  }
  lcs(arr, arr1, m, n);

  return 0;
}
