#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
	int i, key , j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
int main()
{
	cout<<"Enter number of element:";
	int n ;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Entered  array is : ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	insertionSort(arr,n);
	cout<<"Sorted array is : ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}