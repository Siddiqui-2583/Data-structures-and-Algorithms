#include <iostream>
using namespace std;
void display_array(int a[]);
int insert_element(int a[]);
int delete_element(int a[]);
int n;  //n is the index of last element in the array
int main()
{
    // Declaration
    int ages[1000];



    // Assigning walues while initialization
    //int ages[10]={1,2,3,4,5,6,7,8,9,10};

    cout<<"Enter the number of elements to be inserted in the array: ";
    cin>>n;
    cout<<"Enter the elements to be inserted in the array: ";
    //Traversing the array

    //Assigning values after initialization

    for(int i=0; i<n; i++){
        cin>>ages[i];
    }


    display_array(ages);
    cout<<endl;

    insert_element(ages);
    display_array(ages);


    delete_element(ages);
    display_array(ages);

}
//Displaying the array
void display_array(int a[]){
    cout<<"Elements in the array: ";
    for(int i=0; i< n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

//Inserting an element in the array
int insert_element(int a[]){

    int pos, element;
    cout<<"Enter the number to be inserted: ";
    cin>>element ;
    cout<<"Enter the position at which the number is to be inserted: ";
    cin>>pos ;
    pos--; //Because indexing starts from 0
    for(int i=n-1; i >= pos; i--){
        a[i+1] = a[i];
    }
    a[pos]=element;
    n = n+1;  // increase total number of used positions
}
//Deleting an element from the array
int delete_element(int a[]){
    int pos;
    cout<<"Enter the position at which the number is to be deleted: ";
    cin>>pos ;
    for(int i=pos-1; i<n-1; i++){
        a[i]=a[i+1];
    }
    n=n-1;
}

//Finding length of the array
//cout<<sizeof(ages)/sizeof(ages[0]);
