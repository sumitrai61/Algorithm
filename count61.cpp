// C++ Program to implement counting sort 
#include <bits/stdc++.h> 
using namespace std; 

// counting sort function 
void count_sort(int arr[], int n) 
{ 
	// max_element() is a c++ stl function to find the 
	// maximum element from an array 
	int k = *max_element(arr, arr + n); 

	// we declare a count array and initialize the array by 
	// 0 
	int count[k + 1] = { 0 }; 

	// we count the frequency of each distinct element in 
	// the original array 
	for (int i = 0; i < n; i++) { 
		count[arr[i]]++; 
	} 

	// we perform prefix sum and update the count array 
	for (int i = 1; i <= k; i++) { 
		count[i] = count[i] + count[i - 1]; 
	} 

	// we store our answer in the ans array 
	int ans[n]; 
	for (int i = n - 1; i >= 0; i--) { 
		ans[--count[arr[i]]] = arr[i]; 
	} 

	// here we copy the contents on ans array to our 
	// original array 
	for (int i = 0; i < n; i++) { 
		arr[i] = ans[i]; 
	} 
} 

// driver code 
int main() 
{   
    cout<<"Enter number of elements: ";
    int n;
    cin>>n;
	int arr[n];
    for(int i; i<n; i++){
        cout << "Element " << i+1 << ": ";
        cin >> arr[i];  
    }
    cout<<"Array before sorting: ";
    for (int i;i<n;i++){
        cout<<arr[i]<< " "; 
    }
    cout<<endl;
	count_sort(arr, n); 
    cout<<"Array after sorting: ";
    for (int i;i<n;i++){
        cout<<arr[i]<< " "; 
    }
	return 0; 
}
