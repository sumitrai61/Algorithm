#include <iostream>
using namespace std;

int Partition(int A[],int l,int h){
    int pivot = A[l];
    int i =l,j=h;
    while(i<j){
        do
        {
            i++;
        } while (A[i]<=pivot);
        do
        {
            j--;
        } while (A[j]>pivot);
        if(i<j){
            swap(A[i],A[j]);
        }
    }
    swap(A[l],A[j]);
    return j;  
}

void QuickSort(int A[],int l,int h){
    if(l<h){
        int j = Partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}

int main(){
    cout<<"Enter number of element"<<endl;
    int n;
    cin>>n;
    int arr[n+1];
    arr[n] = 99999999; //assigning a large value(for infinity purpose)
    cout<<"Enter elements to be sorted: "<<endl ;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Before sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    QuickSort(arr, 0, n);
    cout<<"After sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "; 
    }
	return 0;
}
