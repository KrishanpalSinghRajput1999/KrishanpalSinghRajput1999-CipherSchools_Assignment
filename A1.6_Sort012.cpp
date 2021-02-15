#include<iostream>
#include <bits/stdc++.h> 
using namespace std; 
void printArr(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
}  
void sortArr(int arr[], int n) 
{ 
	int i, count0 = 0, count1 = 0, count2 = 0; 
	for (i = 0; i < n; i++) { 
		switch (arr[i]) { 
		case 0: 
			count0++; 
			break; 
		case 1: 
			count1++; 
			break; 
		case 2: 
			count2++; 
			break; 
		} 
	}  
	i = 0; 
	while (count0 > 0) { 
		arr[i++] = 0; 
		count0--; 
    }
	while (count1 > 0) { 
		arr[i++] = 1; 
		count1--; 
	}  
	while (count2 > 0) { 
		arr[i++] = 2; 
		count2--; 
	} 
	printArr(arr, n); 
} 
int main() 
{ 
	int arr[] = { 0, 1, 2, 0, 1, 1, 1, 2, 2, 0, 0, 1 }; 
	int n = sizeof(arr) / sizeof(int); 

	sortArr(arr, n); 

	return 0; 
} 
