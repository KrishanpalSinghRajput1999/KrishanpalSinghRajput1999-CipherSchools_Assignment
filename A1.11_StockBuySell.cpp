#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int maxProfit(int prices[], int N)
{
	int n = N;
	int cost = 0;
	int maxCost = 0;

	if (n == 0) 
	{
		return 0;
	}
	// Store the first element of array 
	// in a variable
	int min_price = prices[0];

	for(int i = 0; i < n; i++)
	{
		// Now compare first element with all 
		// the element of array and find the 
		// minimum element
		min_price = min(min_price, prices[i]);
		// Since min_price is smallest element of the
		// array so subtract with every element of the
		// array and return the maxCost
		cost = prices[i] - min_price;

		maxCost = max(maxCost, cost);
	}
	return maxCost;
}
int main()
{
	int prices[] = { 7, 1, 5, 3, 6, 4 };
	int N = sizeof(prices) / sizeof(prices[0]);
	
	cout << maxProfit(prices, N);

	return 0;
}

