#include <iostream>
using namespace std;
int binarySearch(int a[], int searchElement);
int n;
int main()
{
    cout<<"Enter the number of elements to be inserted in the array: ";
    cin>>n;

    int ar[n];

    cout<<"Enter the elements(in sorted order) to be inserted in the array: ";
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int searchElement;
    cout<<"Enter the element to be searched in the array: ";
    cin>>searchElement;
    int i=binarySearch(ar,searchElement);
    if(i != -1)
        cout << searchElement<<" is found at position: "<<i+1<<endl;
    else
        cout << searchElement << " is not found in the array."<<endl;
}


int binarySearch(int a[], int searchElement)
{
   int left,mid,right;
   left=0;
   right=n-1;

   while(left<=right){
        mid=(left+right)/2;

        if(a[mid] == searchElement)
            return mid;
        else if(a[mid] < searchElement)
            left=mid+1;
        else
            right = mid-1;
   }
    return -1;

}
/*
Time Complexity
Average: O(log n)
Best: O(1)
Worst: O(n)
*/
