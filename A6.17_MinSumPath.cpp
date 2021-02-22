//Submitted on leetcode
class Solution {
public:
    int helper(vector<vector<int>>& points,vector<vector<int>>& grid , int row , int col){
        int sum = 0;
        if(points[row][col]!= -1)
            return points[row][col];

        if(row == grid.size()-1 and col ==grid[row].size()-1){
            sum = grid[row][col] ;
        }
        else if(row == grid.size()-1){
            sum = grid[row][col] +  helper(points,grid,row,col+1) ;
        }
        else if(col ==grid[row].size()-1){
            sum = grid[row][col] +  helper(points,grid,row+1,col) ;
        }
        else {
            sum = grid[row][col] + min(helper(points,grid,row,col+1) ,helper(points,grid,row+1,col) );
        }
        points[row][col] = sum ;
        return sum ;   
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> points(grid.size(), vector<int>(grid[0].size(),-1));
        return helper(points,grid,0,0); ;
    }
};
