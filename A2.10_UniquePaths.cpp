#include<iostream>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int dp[m][n];
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                dp[i][j] = 0;
            }
        }
        
        dp[0][0] = 1;
        
        for(int j = 1; j < n; ++j){
            dp[0][j] = dp[0][j - 1];
        }
        
        for(int i = 1; i < m; ++i){
            dp[i][0] = dp[i - 1][0];
        }
        
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
int main
{
    Solution obj;
    int m,n;
    cin>>m>>n;
    int result=obj.uniquePaths(m,n);
    return 0;

}