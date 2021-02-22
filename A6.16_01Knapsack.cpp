#include <iostream>
using namespace std;
// Values (stored in array `v`)
// Weights (stored in array `w`)
// Total number of distinct items `n`
// Knapsack capacity `W`
int knapsack(int v[], int w[], int n, int W)
{
    // `T[i][j]` stores the maximum value that can be attained with
    // weight less than or equal to `j` using items up to first `i` items
    int T[n+1][W+1];
 
    for (int j = 0; j <= W; j++) {
        T[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        // consider all weights from 0 to maximum capacity `W`
        for (int j = 0; j <= W; j++)
        {
            // don't include the i'th element if `j-w[i-1]` is negative
            if (w[i-1] > j) {
                T[i][j] = T[i-1][j];
            }
            else {
                // find the maximum value by excluding or including the i'th item
                T[i][j] = max(T[i-1][j],
                            T[i-1][j-w[i-1]] + v[i-1]);
            }
        }
    }
    return T[n][W];
}
int main()
{
    // input: a set of items, each with a weight and a value
    int v[] = { 20, 5, 10, 40, 15, 25 };
    int w[] = { 1, 2, 3, 8, 7, 4 };
    int W = 10;
    int n = sizeof(v) / sizeof(v[0]);
    cout << "Knapsack value is " << knapsack(v, w, n, W);
    return 0;
}
