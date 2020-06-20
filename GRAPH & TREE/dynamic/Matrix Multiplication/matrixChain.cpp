#include<bits/stdc++.h>
using namespace std;

vector<int>dimens;
int mat[100][100];
int bracket[100][100];
int n;
void printParenthesis(int i, int j, char &name)
{
    if (i == j)
    {
        cout << name++;
        return;
    }
    cout << "(";
    printParenthesis(i, bracket[i][j] , name);
    printParenthesis( bracket[i][j]+1, j, name);
    cout << ")";
}
void printMat()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
void matrixChainOrder()
{



    for (int i=1; i<n; i++)
        mat[i][i] = 0;      //initializing diagonal value with 0

    for (int d=1; d<n-1; d++)
    {
        for (int i=1; i<n-d; i++)
        {
            int j = i+d;
            mat[i][j] = INT_MAX;
            for (int k=i; k<=j-1; k++)
            {
                int q = mat[i][k] + mat[k+1][j] + dimens[i-1]*dimens[k]*dimens[j];
                cout<<"q:  "<<q<<endl;
                if (q < mat[i][j])
                {
                    mat[i][j] = q;
                    bracket[i][j] = k;
                    printMat();
                    cout<<endl<<endl;
                }
            }

        }
    }
    char name = 'A';

    cout << "Optimal matrix Parenthesization is : ";
    printParenthesis(1, n-1, name);
    cout << "\nOptimal Cost is : " << mat[1][n-1];
}

// 40, 20, 30, 10, 30
int main()
{
    cout<<"Enter the number of distinct dimension:  ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        dimens.push_back(a);
    }

    matrixChainOrder();
    return 0;
}
