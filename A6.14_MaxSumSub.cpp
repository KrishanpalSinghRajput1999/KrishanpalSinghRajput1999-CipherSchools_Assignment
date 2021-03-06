#include <iostream>
using namespace std;
 
// Constant space DP-solution to calculate the maximum sum in a given
// array with no adjacent elements considered
int maxSumSubseq(int arr[], int n)
{
    // base case
    if (n == 1) {
        return arr[0];
    }
 
    // store maximum sum until index `i-2`
    int prev_prev = arr[0];
 
    // stores maximum sum until index `i-1`
    int prev = max(arr[0], arr[1]);
 
    // start from index 2
    for (int i = 2; i < n; i++)
    {
        // `curr` stores the maximum sum until index `i`
        int curr = max(arr[i], max(prev, prev_prev + arr[i]));
        prev_prev = prev;
        prev = curr;
    }
 
    // return maximum sum
    return prev;
}
 
int main()
{
    int arr[] = { 1, 2, 9, 4, 5, 0, 4, 11, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "The Maximum sum is " << maxSumSubseq(arr, n);
 
    return 0;
}
