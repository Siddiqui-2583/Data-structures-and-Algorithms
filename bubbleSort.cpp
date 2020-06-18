#include <iostream>
using namespace std;
void display_array(int a[]);
int n;
int * bubbleSort(int a[]);
int main()
{
    cout<<"Enter the number of elements to be inserted in the array: ";
    cin>>n;

    int ar[n];

    cout<<"Enter the elements to be inserted in the array: ";
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    bubbleSort(ar);
    display_array(ar);

}


int * bubbleSort(int a[]){
    for(int i=0; i < n-1; i++){
        for(int j=0; j < n-i-1; j++){
            if(a[j] > a[j+1])
                swap(a[j],a[j+1]);
        }
    }
    return a;
}


void display_array(int a[]){
    cout<<"Elements in the array: ";
    for(int i=0; i< n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
