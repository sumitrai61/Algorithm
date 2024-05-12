// program to implement a heap sort

#include <stdio.h>
#include <iostream>
using namespace std;

void heapify(int arr[],int i,int n){
    // finding largest element among the node, it's left child and it's right child
    int largest=i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,largest,n);
    }
    
}

void heapsort(int arr[],int len){
    // building max heap 
    for(int i=(len/2 -1);i>=0;--i){
        heapify(arr,i,len);
    }
    // applying heap sort
    for(int i=len-1;i>0;--i){
        swap(arr[0],arr[i]);
        heapify(arr,0,i);
    }

}
int main(){
    cout<<"Program to implement heapsort"<<endl;
    int len;
    cout<<"enter the length of the array:";
    cin>>len;
    int array[len];
    cout<<"enter the array elements "<<endl;
    for(int i=0;i<len;++i){
        cout<<"enter the element at "<<i+1<<" position:";
        cin>>array[i];
    }
    cout<<"original array is "<<endl;
    cout<<"[";
    for(int i=0;i<len;++i){
        cout<<array[i]<<" ,";
    }
    cout<<"]"<<endl;
    cout<<"array sorted after applying heap sort "<<endl;
    heapsort(array,len);
    cout<<"[";
    for(int i=0;i<len;++i){
        cout<<array[i]<<" ,";
    }
    cout<<"]"<<endl;
     
}
