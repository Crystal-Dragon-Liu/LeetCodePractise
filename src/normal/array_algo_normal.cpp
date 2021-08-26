#include "common/utils.h"
#include "common/solution.h"
#include <math.h>

    // ! 1. the definition of DP array and its index.
    // ! 2. recursion formula.
    // ! 3. initialize the dp
    // ! 4. the order of traversal 
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
//=========================================================================================
// ? normal 343. Integer Break
// Given an integer n, break it into the sum of k positive integers, 
// where k >= 2, and maximize the product of those integers.
// Return the maximum product you can get.
//=========================================================================================
int Solution::integerBreak(int n)
{
    // ! 1. the definition of DP array and its index.
    // dp[i] stands for the the max sum of k  postive integers which are split by i 
    // ! 2. recursion formula.
    // dp[i] =  max(dp[i], max(dp[i-j] * j, j * (i-j)))
    // ! 3. initialize the dp
    // dp[2] = 1, dp[1], dp[0] would not be initialized in that these value are meanless.
    // ! 4. the order of traversal 
    // i from 3 to n, j from 1 to i - 1

    std::vector<int> dp(n + 1);
    dp[2] = 1;
    for(int i = 3; i <= n; i++)
    {
        for(int j = 1; j < i - 1; j++)
        {
            dp[i] = std::max(dp[i], std::max(dp[i - j] * j, (i-j) * j));
        }
    }
    return dp[n];
}
//=========================================================================================
// ? 416. Partition Equal Subset Sum
// Given a non-empty array nums containing only positive integers, 
// find if the array can be partitioned into two subsets such that 
// the sum of elements in both subsets is equal.
//=========================================================================================
bool Solution::canPartition(std::vector<int>& nums)
{
    // this problem should be converted to a 01 backpack problem.
    // 1. the volumn of bagpack -> sum/2
    // 2. each num should only used for one time.
    // 3. the value of each num stands for both weight and value of item.

    // ! 1. the definition of DP array and its index.
    // dp[i] stands for that when there is a bagpack with total weights i,
    // the max sum of subset is dp[i] 
    // ! 2. recursion formula.
    // ! 3. initialize the dp
    // ! 4. the order of traversal 
    return false;
}