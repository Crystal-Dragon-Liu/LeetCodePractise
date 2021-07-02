#include "common/utils.h"
#include "common/solution.h"



//=========================================================================================
// ? 62. Unique Paths
// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram 
// below).
// The robot can only move either down or right at any point in time. 
// The robot is trying to reach the bottom-right corner of the grid 
// (marked 'Finish' in the diagram below).
// How many possible unique paths are there?
//=========================================================================================

int   Solution::uniquePaths(int m, int n)
{
    // TODO there are five steps need to clarify
    // ! 1. the definition of DP array and its index.
    // dp[i][j] stands for that from position [0, 0], there are dp[i][j] ways to reach the
    // position [i, j]
    // ! 2. recursion formula.
    // dp[i][j] could be come up by dp[i][j-1] and dp[i-1][j]
    // ! 3. initialize the dp
    // dp[i][0] and dp[0][j], i= 0, 1, 2, 3, ..., m; j = 0, 1, 2, 3, ... , n;
    // are set to 1; 
    // ! 4. the order of traversal
    // traverse the grip from [1, 1]
    if(m < 2 || n < 2) return 1;
    std::vector<std::vector<int> > dp(m, std::vector<int>(n, 0));
    /// initialize dp array.
    for(std::size_t i = 0; i < dp.size(); i++) dp[i][0] = 1;
    for(std::size_t j = 0; j < dp[0].size(); j++) dp[0][j] = 1;
    /// traverse arrays.
    for(std::size_t i = 1; i < dp.size(); i++)
    {
        for(std::size_t j = 1; j < dp[0].size(); j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}





//=========================================================================================
// ? normal 63. Unique Paths II
// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time. 
// The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
// Now consider if some obstacles are added to the grids. 
// How many unique paths would there be?
// An obstacle and space is marked as 1 and 0 respectively in the grid.
//=========================================================================================
int  Solution::uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
{
    // ! 1. the definition of DP array and its index.
    // dp[i][j] stands for that from position [0, 0], there are dp[i][j] ways to reach the
    // position [i, j]
    // ! 2. recursion formula.
    // dp[i][j]  = if obstacleGrid[i][j] != 1 dp[i-1][j] + dp[i][j-1] else 0
    // ! 3. initialize the dp
    // dp[i][0] and dp[0][j], i= 0, 1, 2, 3, ..., m; j = 0, 1, 2, 3, ... , n;
    // are set to 1; but when obstacleGrid[i][0], obstacleGrid[0][j] is set to 1, the value of DP at 
    // same position should be 0.
    // ! 4. the order of traversal
    // traverse the grip from [1, 1]
    std::size_t m = obstacleGrid.size();
    std::size_t n = obstacleGrid[0].size();
    std::vector<std::vector<int> > dp(m, std::vector<int>(n, 0));
    /// notice that when  the value of dp at position [i, 0] or [0, j] where the value of obstacleGrid is set
    /// to 1, all of other values of dp behind that would be set to 0.
    for(std::size_t i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
    for(std::size_t j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
    for(std::size_t i = 1; i < m; i++)
    {
        for(std::size_t j = 1; j < n; j++)
        {
            if(obstacleGrid[i][j] != 1)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}
