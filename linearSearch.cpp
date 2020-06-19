#include <iostream>
using namespace std;
void linearSearch(int a[], int searchElement);
int n;
int main()
{
    cout<<"Enter the number of elements to be inserted in the array: ";
    cin>>n;

    int ar[n];

    cout<<"Enter the elements to be inserted in the array: ";
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int searchElement;
    cout<<"Enter the element to be searched in the array: ";
    cin>>searchElement;
    linearSearch(ar,searchElement);

}


void linearSearch(int a[], int searchElement)
{
    bool isFound;
    for(int i=0; i<n;i++){
        if(a[i] == searchElement){
            cout << searchElement<<" is found at position: "<< (i+1)<<endl;
            isFound = true;
            break;
        }
    }
    if(isFound == false)
        cout<< searchElement << " is not found in the array."<<endl;

}
