#include <iostream>
using namespace std;
void display_array(int a[]);
int n;
int * selectionSort(int a[]);
int main()
{
    cout<<"Enter the number of elements to be inserted in the array: ";
    cin>>n;

    int ar[n];

    cout<<"Enter the elements to be inserted in the array: ";
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    selectionSort(ar);
    display_array(ar);

}


int * selectionSort(int a[]){
    int i,j,index_min;

    for(i=0; i<n-1; i++){
        index_min=i;
        for(j=i+1; j<n; j++){
            if(a[j] < a[index_min])
                index_min=j;
        }
        if(index_min != i)
            swap(a[i],a[index_min]);
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


