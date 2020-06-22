#include <iostream>
using namespace std;
void display_array(int a[]);
int n;
int * insertionSort(int a[]);
int main()
{
    cout<<"Enter the number of elements to be inserted in the array: ";
    cin>>n;

    int ar[n];

    cout<<"Enter the elements to be inserted in the array: ";
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    insertionSort(ar);
    display_array(ar);

}


int * insertionSort(int a[]){
    int i,j,k,item;
    for(i=1;i<n;i++){
        item = a[i];

        j=i-1;
        while(j >=0 && a[j] > item){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=item;
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

