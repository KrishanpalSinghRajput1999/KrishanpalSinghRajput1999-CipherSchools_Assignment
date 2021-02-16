#include <algorithm> 
#include <iostream> 
using namespace std; 
void printSmall(int arr[], int n, int k) 
{ 
	// For each arr[i] find whether 
	// it is a part of n-smallest 
	// with insertion sort concept 
	for (int i = k; i < n; ++i) 
	{ 
		// find largest from first k-elements 
		int max_var = arr[k-1]; 
		int pos = k-1; 
		for (int j=k-2; j>=0; j--) 
		{			 
			if (arr[j] > max_var) 
			{ 
				max_var = arr[j]; 
				pos = j; 
			} 
		} 
		// if largest is greater than arr[i] 
		// shift all element one place left 
		if (max_var > arr[i]) 
		{ 
			int j = pos; 
			while (j < k-1) 
			{ 
				arr[j] = arr[j+1]; 
				j++; 
			} 
			// make arr[k-1] = arr[i] 
			arr[k-1] = arr[i]; 
		} 
	} 
	// print result 
	for (int i=0; i<k; i++) 
		cout << arr[i] <<" "; 
				
} 
int main() 
{ 
	int arr[] = {5, 8,15,1,6, 7, 3, 6, 2, 9 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 5; 
	printSmall(arr, n, k); 
	return 0; 
} 
