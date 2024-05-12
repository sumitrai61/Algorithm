#include <iostream>
using namespace std;

int partition(int arr[], int l, int h)
{

	int pivot = arr[l];

	int count = 0;
	for (int i = l + 1; i <= h; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	int p = l + count;
	swap(arr[p], arr[l]);

	int i = l, j = h;

	while (i < p && j > p) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < p && j > p) {
			swap(arr[i++], arr[j--]);
		}
	}

	return p;
}

void quickSort(int arr[], int l, int h)
{

	// base case
	if (l >= h)
		return;

	// partitioning the array
	int p = partition(arr, l, h);

	// Sorting the left part
	quickSort(arr, l, p - 1);

	// Sorting the right part
	quickSort(arr, p + 1, h);
}

int main()
{
    cout<<"Enter number of element"<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter elements to be sorted: "<<endl ;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Before sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quickSort(arr, 0, n - 1);
    cout<<"After sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "; 
    }
	return 0;
}
