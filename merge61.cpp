#include <iostream>
using namespace std;
void Merge(int A[], int l, int mid, int r) {
    int i= l,j= mid+1,k=l;
    int B[100];
    while(i<=mid && j<=r){
        if (A[i]<A[j]){
            B[k++] = A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }
    for(i;i<=mid;i++){
            B[k++] = A[i];
    }
    for(j;j<=r;j++){
            B[k++] = A[j];
    }
    for(i=l;i<=r;i++){
            A[i] = B[i];
    }
}

void MergeSort(int A[],int l,int r){
    int mid;
    if(l<r){
        mid = (l+r)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,r);
        Merge(A,l,mid,r);
    }
}

int main(){
    cout<<"Enter Size of Array:"<<endl;
    int n;
    cin>>n;
    int Arr[n];
    cout<<"Enter Elements of Array: "<<endl;
    for (int i=0;i<n;i++){
        cin>>Arr[i];
    }
    cout<<"Entered Array is:"<<" ";
    for (int i=0;i<n;i++){
        cout<<Arr[i]<<" ";
    }
    cout<<"\nArray After Merge Sort:"<<" ";
    MergeSort(Arr,0,n-1);
    for (int i=0;i<n;i++)
        cout<<Arr[i]<<" ";
}