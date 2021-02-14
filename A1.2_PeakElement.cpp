#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int findPeak(int arr[], int n)
{
	// first or last element is peak element
	if (n == 1) 
	return arr[0];
	if (arr[0] >= arr[1])
		return 0;
	if (arr[n - 1] >= arr[n - 2])
		return n - 1;
	for (int i = 1; i < n - 1; i++) 
  {
		if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
			return i;
	}
}
int main()
{
	int arr[] = { 1, 5, 30, 6, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout<< findPeak(arr, n);
	return 0;
}
