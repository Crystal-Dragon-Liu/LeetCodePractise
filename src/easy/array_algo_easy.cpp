
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
}