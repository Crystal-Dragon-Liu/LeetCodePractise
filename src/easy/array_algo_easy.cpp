
#include "common/utils.h"
#include "common/solution.h"
/* 15. 3Sum*/

//------------------------------------------------------------------------
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.
//------------------------------------------------------------------------
std::vector<std::vector<int>> Solution::threeSum(std::vector<int>& nums)
{
    return std::vector<std::vector<int> >();
}


//=========================================================================================
// ? 509. Fibonacci Number
// The Fibonacci numbers, 
// commonly denoted F(n) form a sequence, 
// called the Fibonacci sequence, 
// such that each number is the sum of the two preceding ones, 
// starting from 0 and 1. That is,
//=========================================================================================

int Solution::fib(int n)
{
    // TODO there are five steps need to clarify
    // ! 1. the definition of DP array and its index.
    // dp[i] stands for the i-th fib array's value.
    // ! 2. recursion formula.
    // dp[i] = dp[i - 1] + dp[i -2]
    // ! 3. how to initialize the dp array.
    // firstly dp[0], dp[1] both are set to 1
    //  according to the definition of Fibonacci Number.
    // ! 4. the order of traversal.
    // index from 2 to the end,
    // because the dp array at index 1 and 0 is what we have known.
    // ! debug.
    if(n < 2) return n;
    std::vector<int> fib(n + 1, 0);
    fib[1] = 1;
    for(std::size_t i = 2; i < fib.size(); i++)
        {fib[i] = fib[i-1] + fib[i-2];}
    return fib[n];
} 

//=========================================================================================
// ? 70. Climbing Stairs
// You are climbing a staircase. 
// It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. 
// In how many distinct ways can you climb to the top?
//=========================================================================================
int  Solution::climbStairs(int n)
{
    // TODO there are five steps need to clarify
    // ! 1. the definition of DP array and its index.
    // dp[i] to reach the i-th floor, we have dp[i] ways.
    // ! 2. recursion formula.
    // dp[i] = dp[i-1] +dp[i-2]?????
    // ! 3. initialize the dp
    // dp [1] = 1, dp[2] = 2
    // notice that dp[0] make no sense according to the definition of dp array.
    // ! 4. the order of traversal 
    // from dp[3] to dp[n]
    std::vector<int> dp(n+1, 1);
    if(n >= 2) dp[2] = 2;
    if(n <= 2) return dp[n];
    for(std::size_t i = 3; i < dp.size(); i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    // auto dpIter = dp.begin();
    // while(dpIter != dp.end())
    // {
    //     std::cout << (*dpIter) << " ";
    //     dpIter++;
    // }
    // std::cout << std::endl;
    return dp[n];
}

int  Solution::climbStairsDP(int n, int m)
{
    // ? m stands for that the maximum stairs is set to m
    // ! 1. the definition of DP array and its index.
    // dp[i] stands for that there are dp[i] ways to reach the stairs when there is i stairs
    // ! 2. recursion formula.
    // dp[j] += dp[j - i]
    // ! 3. initialize the dp
    // dp[0] = 1
    std::vector<int> dp(n + 1, 0);
    for(int j = 0; j <= n; j++)
        for(int i = 0; i <= m; i++)
        {
            if(j - i >= 0)
                dp[j] += dp[j - i];
        }
    return dp[n];
}

//=========================================================================================
// ? 746. Min Cost Climbing Stairs
// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
// Once you pay the cost, you can either climb one or two steps.
// You can either start from the step with index 0,
//  or the step with index 1.
// Return the minimum cost to reach the top of the floor.

// Example 1:

// Input: cost = [10,15,20]
// Output: 15
// Explanation: Cheapest is: start on cost[1], pay that cost, and go to the top.
// Example 2:

// Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6
// Explanation: Cheapest is: start on cost[0], and only step on 1s, skipping cost[3].
//=========================================================================================
    // ! 1. the definition of DP array and its index.
    // ! 2. recursion formula.
    // ! 3. initialize the dp
    // ! 4. the order of traversal 

int  Solution::minCostClimbingStairs(std::vector<int>& cost)
{
    // TODO there are five steps need to clarify
    // ! 1. the definition of DP array and its index.
    // dp[i] stands for the lowest cost for reaching the i-th floor.
    // ! 2. recursion formula.
    // dp[i] = min(dp[i-1], dp[i-2])
    // ! 3. initialize the dp
    // dp[0] = whatever, dp[1] = cost[1], dp[2] = cost[2]
    // ! 4. order of traversal
    // dp[3] - dp[n]
        // if(cost.size() <= 2) return std::min(dp[0], dp[1]);
    // ? the problem: the definition is not clear.
    std::vector<int> dp(cost.size());
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(std::size_t i = 2; i < cost.size(); i++)
    {
        dp[i] = std::min(dp[i-2], dp[i - 1]) + cost[i];
    }
    // auto dpIter = dp.begin();
    // while(dpIter != dp.end())
    // {
    //     std::cout << (*dpIter) << " ";
    //     dpIter++;
    // }
    // std::cout << std::endl;
    return std::min(dp[cost.size() - 1], dp[cost.size() -2]);
}
