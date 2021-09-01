#include "common/utils.h"
#include "common/solution.h"
#include <math.h>
#include <algorithm>
#include <numeric>
#include <unordered_set>
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
    // dp[i] = max ( dp[i], dp[i - num[i]]+ num[i] )
    // ! 3. initialize the dp
    // make each element set to 0;
    // ! 4. the order of traversal
    // totally like bag problem.

    // get sum / 2
    int sum = 0;
    for (std::size_t i = 0; i < nums.size(); i++) {sum += nums[i];}    
    std::cout << "sum / 2: " << sum / 2 << std::endl;
    std::vector<int> dp(10001, 0);
    if(sum % 2 == 1) return false;
    // the weight of bag -> sum /2
    int target = sum/2;
    for(std::size_t i = 0; i < nums.size(); i++)
        for(int j = target; j >= nums[i]; j--)
            dp[j] = std::max(dp[j - nums[i]] + nums[i], dp[j]);
    if(dp[target] == target)
        return true;
    else
        return false; 
}


//=========================================================================================
// You are given an array of integers stones where stones[i] is the weight of the ith stone.

// We are playing a game with the stones. On each turn, we choose any two stones and smash them together.
// Suppose the stones have weights x and y with x <= y. The result of this smash is:

// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.

// Return the smallest possible weight of the left stone. If there are no stones left, return 0.

// Example 1:

// Input: stones = [2,7,4,1,8,1]
// Output: 1
// Explanation:
// We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
// we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
// we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
// we can combine 1 and 1 to get 0, so the array converts to [1], then that's the optimal value.
// Example 2:

// Input: stones = [31,26,33,21,40]
// Output: 5

//=========================================================================================

int   Solution::lastStoneWeightII(std::vector<int>& stones)
{
    // this problem could be converted to a 01 backpack problem.
    // element of stones stand for weights of items.
    // element of stones also stand for value of items.

    // the problem could be switched to that we should figure out a solution 
    // that could divide stones into 2 equal parts.
    // ! 1. the definition of DP array and its index.
    // dp[i] stands for that the maximum weights of bag whose capacity is i.
    // ! 2. initialize the dp
    // dp[0] -> 0, dp[i] (i != 0) -> 0
    // ! 3. recursion formula.
    // dp[i] = std::max(dp[i - stones[i]] + stones[i], dp[i])
    // ! 4. the order of traversal
    // totally same with typical bag problem.
    int sum = 0;
    for (std::size_t i = 0; i < stones.size(); i++) {sum += stones[i];}  
    int target = sum / 2;
    std::vector<int> dp(target + 1, 0);
    for(std::size_t i = 0; i < stones.size(); i++)
        for(int j = target; j >= stones[i]; j--)
            dp[j] = std::max(dp[j - stones[i]] + stones[i], dp[j]);
    return sum - dp[target] - dp[target];
    // after dp, the dp[target] is the result of spliting. the rest of weight is equal
    // to sum - dp[target] * 2
}

//=========================================================================================
// ? 494. Target Sum
// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

//  

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

//=========================================================================================

int Solution::findTargetSumWays(std::vector<int>& nums, int target)
{
    // the problem could be converted to a bag problem.
    // in which we need to find all the ways to get a target num by plusing 
    // or minusing the element of nums.
    // so there may be a formula which is " left - right = target "
    // left stands for the positive subset of nums.
    // right stands for the nagative subset of nums.
    // and left plus right should equal to sum which is fixed.
    // so we could derive that ->
    // left + right = sum  (->) right = sum - left (->)
    // left - right = target  (->) left - ( sum - left)  = target (->)
    // left * 2 = target + sum (->)
    // left = (target + sum) / 2
    //! because the left should be precisely calculated by (target + sum) / 2
    //! so if the left is rounded down, there is no return for this problem.

    // ! 1. the definition of DP array and its index.
    // dp[i] stands for there are dp[i] ways to fill the bag when the capacity of bag is set to i.
    // ! 2. The recursive formula
    // dp[j]  += dp[j - nums[i]]
    // according to the definition of DP array, we know what the dp[j - nums[i]] means,
    // and if there is a item weighting nums[i] we would consider, dp[j] = dp[j - nums[i]]
    // without consider the item weighting nums[i], dp[j] would be the another dp[j] which stands for
    // that there are dp[j] ways to fill the bag with capacity of bag is set to i - 1;
    // so we should consider both two dp[j] which are matched to differnt numbers of items.
    // dp[j] = dp[j] + dp[j - nums[i]]
    //  (1)     (2)         (3)

    //summary
    // (1) dp[j] means there are dp[j] ways to fill the bag when capcaity of bag is set to j
    // (2) dp[j] means there are dp[j] ways to fill the bag when capcaity of bag is set to j without considering
    //     the items[i]
    // (3) dp[j - nums[i]] there are dp[j - nums[i]] ways to fill the bag when capcaity of bag is set to j - nums[i]
    //     which is totally same as dp[j] which stands for there are dp[j] ways to fill the bag
    //     when capcaity of bag is set to j considering the items[i]
    
    // ! 3. initialize the dp
    // dp[0] should set to 1 , enabling The recursive formula works.
    // dp[0] = 1 stands for that

    int sum = 0;
    for(std::size_t i = 0; i < nums.size(); i++)
        sum += nums[i];
    if((target + sum) < 0 ) return 0;
    if(target > sum) return 0;
    if((target + sum) % 2 == 1) return 0;
    int weight = (target + sum) / 2;
    //initialize dp
    std::vector<int> dp(weight + 1, 0); 
    dp[0] = 1;

    // recursive formula.
    for(std::size_t i = 0; i < nums.size(); i++)
        for(int j = weight; j >= nums[i]; j--)
            dp[j] += dp[j - nums[i]];

    // calculate target.
    return dp[weight];
}

//=========================================================================================
// ? 474. Ones and Zeroes
// You are given an array of binary strings strs and two integers m and n.

// Return the size of the largest subset of strs such that there are 
// at most m 0's and n 1's in the subset.

// A set x is a subset of a set y if all elements of x are also elements of y.

// Example 1:

// Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
// Output: 4
// Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"},
// so the answer is 4.
// Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
// {"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
// Example 2:

// Input: strs = ["10","0","1"], m = 1, n = 1
// Output: 2
// Explanation: The largest subset is {"0", "1"}, so the answer is 2.
//=========================================================================================

int   Solution::findMaxForm(std::vector<std::string>& strs, int m, int n)
{
    // ! 1. the definition of DP array and its index.
    // dp[i][j] stands for that the count of maximum subset with no more than i 0 and j 1.
    // ! 2. initialize the dp
    // all dp[i][j] should equal to 0
    if(m < 0 || n < 0)
        return 0;
    std::vector<std::vector<int> > dp(m + 1, std::vector<int>(n + 1, 0));
    // ! 2. The recursive formula
    // dp[i][j] = dp[i - numZero][j - numOne] + 1
    int numZero = 0;
    int numOne  = 0;
    for(std::size_t s = 0; s < strs.size(); s++){
        // get the numZero and nmrOne
        for(char c: strs[s])
            if(c == '0') numZero++;
            else numOne++;
        // std::cout << "str: " << strs[s] << std::endl;
        // std::cout << "count 1 : " << numOne << std::endl;
        // std::cout << "count 0 : " << numZero << std::endl;
        // std::cout << "-------------------------------------" << std::endl;
        for(int i = m; i >= numZero; i--)
            for(int j = n; j >= numOne; j--)
                dp[i][j] = std::max(dp[i][j], dp[i - numZero][j - numOne] + 1);
        numZero = 0;
        numOne  = 0;
    }
    return dp[m][n];
}

//=========================================================================================
// ? 518. Coin Change 2
// You are given an integer array coins representing coins of different denominations 
// and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount.
// If that amount of money cannot be made up by any combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.
// The answer is guaranteed to fit into a signed 32-bit integer.
// Example 1:

// Input: amount = 5, coins = [1,2,5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
// Example 2:

// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.
// Example 3:

// Input: amount = 10, coins = [10]
// Output: 1
//=========================================================================================

int  Solution::change(int amount, std::vector<int>& coins)
{
    // ! 1. the definition of DP array and its index.
    // dp[j] stands for that there are dp[j] ways to fill the back whose capacity is set to j
    
    // ! 2. recursive formula.
    // dp[j] += dp[j - coins[i]]
    // before plus the dp[j - coins[i]], dp[j] stands for that there are dp[j] ways to fill the 
    // bag whos capacity is set to J, without considering coins[i]
    // to update the dp[j], we should additionally plus dp[j - coins[i]] which stands for the num
    // of combination considering coins[i].

    // ! 1. initialize dp
    // dp[0] = 1    
    std::vector<int> dp(amount+1, 0);
    dp[0] = 1;
    // for(std::size_t i = 0; i < coins.size(); i++)
    // {
    //     std::cout << "============ coins[" << i << "]->" <<  coins[i] << " ============" << std::endl;
    //     for(int j = coins[i]; j <= amount; j++)
    //         {
    //             dp[j] += dp[j - coins[i]];
    //             for(int dp_element: dp)
    //                 std::cout << dp_element << ", ";
    //             std::cout << std::endl;
    //         }
    //     // each combination would only be considered once.
    // }

    // change the order
    for(int j = 0; j <= amount; j++){
        std::cout << "============ bag[" << j << "] ============" << std::endl;
        for(std::size_t i = 0; i < coins.size(); i++){
            if(j - coins[i] >= 0)
            {
                dp[j] += dp[j-coins[i]];
                for(int dp_element: dp)
                    std::cout << dp_element << ", ";
                std::cout << std::endl;
            }
            // this order would result in that a dp[j] updated incorrectly, such as
        }
    }
    return dp[amount];
}

//=========================================================================================
// Given an array of distinct integers nums and a target integer target, 
// return the number of possible combinations that add up to target.
// The answer is guaranteed to fit in a 32-bit integer.

// Example 1:

// Input: nums = [1,2,3], target = 4
// Output: 7
// Explanation:
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// Note that different sequences are counted as different combinations.
// Example 2:

// Input: nums = [9], target = 3
// Output: 0
//  

// Constraints:
// 1 <= nums.length <= 200
// 1 <= nums[i] <= 1000
// All the elements of nums are unique.
// 1 <= target <= 1000
//  

// Follow up: What if negative numbers are allowed in the given array? 
// How does it change the problem? 
// What limitation we need to add to the question to allow negative numbers?
//=========================================================================================

int  Solution::combinationSum4(std::vector<int>& nums, int target)
{
    // ! 1. the definition of DP array and its index.
    // dp[i] means there are dp[i] kinds of combinations to fill the bag whose capacity is 
    // set to i
    // ! 2. recursive formula.
    // dp[j] += dp[j - nums[i]];
    // ! 1. initialize dp
    // dp[0] = 1
    std::vector<int> dp(target+1, 0);
    dp[0] = 1;
    for(int j = 0; j <= target; j++)
        for(std::size_t i = 0; i < nums.size() ; i++)
        {
            if(j >= nums[i] && dp[j] < (INT32_MAX - dp[j - nums[i]]))
                dp[j] += dp[j - nums[i]];
        }
    return dp[target];
}


//=========================================================================================
//? normal 322. Coin Change
// You are given an integer array coins representing coins of different denominations 
// and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. 
// If that amount of money cannot be made up by any combination of the coins, 
// return -1.

// You may assume that you have an infinite number of each kind of coin.
// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0
// Example 4:

// Input: coins = [1], amount = 1
// Output: 1
// Example 5:

// Input: coins = [1], amount = 2
// Output: 2
//=========================================================================================

int   Solution::coinChange(std::vector<int>& coins, int amount)
{
    //! 1. definition of dp
    // dp[j] means the minimum count of coins to match the amount j.
    //! 2. initialize dp
    // dp[0] = 0, rest of dp elements should be set to int_max.
    //! 3. recursive formula.
    // dp[j] = min(dp[j], dp[j - coins[i]] + 1)
    std::vector<int> dp(amount+1 , INT32_MAX);
    dp[0] = 0;
    // there is no limitation for the usage of coins, so we should not 
    // reverse traverse the bag.
    for(std::size_t i = 0; i < coins.size(); i++)
        for(int j = coins[i]; j <= amount; j++)
        {
            if(dp[j-coins[i]] != INT32_MAX)
                dp[j] = std::min(dp[j], dp[j-coins[i]] + 1);
        }
    if(dp[amount] == INT32_MAX) return -1;
    return dp[amount];
}

//=========================================================================================
//? 279. Perfect Squares
// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, 
// it is the product of some integer with itself. For example, 1, 4, 9,
//  and 16 are perfect squares while 3 and 11 are not.

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
//=========================================================================================

int  Solution::numSquares(int n)
{
    //! definition of dp
    // dp[j] means that there are minimum dp[j] ps(prefect square) which could add up to j
    //! initialize dp
    // dp[0] = 1
    //! recursive formula
    // dp[j] = min(dp[j], dp[j - square[i]] + 1)
    //! order of traversal
    // only require count of squares, Permutation and combination is not nesscessary.
    // traverse bag firstly or vise versa is either ok.
    std::vector<int> dp(n+1, INT32_MAX);
    dp[0] = 0;
    // for(int j = 0; j <= n; j++)
    //     for(int i = 0; i*i <= j; i++)
    //         if(dp[j-i*i] != INT32_MAX)
    //             dp[j] = std::min(dp[j], dp[j - i*i] + 1);
    for(int i = 1; i*i <=n; i++)
        for(int j = i*i; j <= n; j++)
            // if(dp[j-i*i] != INT32_MAX)
                dp[j] = std::min(dp[j], dp[j - i*i] + 1);
    return dp[n];
}

//=========================================================================================
//? 139. Word Break
// Given a string s and a dictionary of strings wordDict, 
// return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.
// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false
//=========================================================================================
bool Solution::wordBreak(std::string s, std::vector<std::string>& wordDict)
{
    //! defintion of dp
    // dp[j] stands for that whether the s could be split into words which are contained in wordDict.
    //! recursive fomula.
    // dp[j] = dp[j - wordDict[i].size()] == true && dp[j]
    std::vector<bool> dp(s.size() + 1, false);
    std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());
    dp[0] = 1;
    for(std::size_t j = 1; j <= s.size(); j++)
        for(std::size_t i = 0; i < j; i++){
            std::string word = s.substr(j, j-i);
            if(wordSet.find(word) != wordSet.end() && dp[i])
                dp[j] = true;
        }
    // for(std::size_t i = 0; i < s.size(); i++)
    //     for(std::size_t j = i; j <= s.size(); j++)
    //         // std::string word = s.substr(i, j-i);
    //     {
    //         if(dp[i] && wordSet.find(word) != wordSet.end())
    //             dp[j] = true;
    //     }
    return dp[s.size()];
}
//=========================================================================================
//? 198. House Robber
// You are a professional robber planning to rob houses along a street. 
// Each house has a certain amount of money stashed, 
// the only constraint stopping you from robbing each of them is that 
// adjacent houses have security systems connected and it will automatically contact the police
// if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, 
// return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

//=========================================================================================
int  Solution::rob(std::vector<int>& nums)
{
    //! defintion of dp
    // dp[j] stands for that there is no more than dp[j]$ the threaf could steal in the scope of j.
    //! recursive formula.
    //dp[j] = max(dp[j-1], dp[j-2] + nums[j])
    //! initialize dp
    //dp[0] = nums[0]
    //dp[1] = max(nums[1], nums[0])
    if(nums.size() == 0) return 0;
    if(nums.size() == 1) return nums[0];
    std::vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);
    // bag -> nums.size();
    // items -> nums[i]
    for(std::size_t i = 2; i < nums.size(); i++)
        dp[i] = std::max(dp[i-1], dp[i-2] + nums[i]);
    return dp[nums.size() - 1];
}


//=========================================================================================
// ? 213. House Robber II
// You are a professional robber planning to rob houses along a street. 
// Each house has a certain amount of money stashed. 
// All houses at this place are arranged in a circle. 
// That means the first house is the neighbor of the last one. 
// Meanwhile, adjacent houses have a security system connected, 
// and it will automatically contact the police 
// if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house,
//  return the maximum amount of money you can rob tonight without alerting the police.

//  

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3

//=========================================================================================
int  Solution::robII(std::vector<int>& nums)
{
    // as for a cycle structure.
    // there are only 2 situations we should consider.
    // such as nums -> [1, 2, 3, 4] where the nums[0] and nums[3] would be linked together.
    // 1. because of the cycle structure, if we choose 1, 2, 3, the 4-th item must be given up.
    // 2. like former statement, if we choose 2, 3, 4, the first item must be given up
    if(nums.size() == 0) return 0;
    if(nums.size() == 1) return nums[0];
    int resultA = robRange(nums, 0, nums.size() - 2);
    int resultB = robRange(nums, 1, nums.size() - 1);
    return std::max(resultA, resultB);
}

int  Solution::robRange(std::vector<int>& nums, int start, int end)
{
    if(start==end)
        return nums[start];
    std::vector<int> dp(nums.size(), 0);
    dp[start] = nums[start];
    dp[start+1] = std::max(nums[start], nums[start+1]);
    for(int i = start+2; i <= end; i++)
        dp[i] = std::max(dp[i-1], dp[i-2] + nums[i]);
    return dp[end];
}



//=========================================================================================
//? 337. House Robber III
// The thief has found himself a new place for his thievery again. 
// There is only one entrance to this area, called root.

// Besides the root, each house has one and only one parent house. 
// After a tour, the smart thief realized that all houses in this place form a binary tree.
// It will automatically contact the police 
// if two directly-linked houses were broken into on the same night.

// Given the root of the binary tree, 
// return the maximum amount of money the thief can rob without alerting the police.
//=========================================================================================
int  Solution::rob(TreeNode* root)
{
    //! dp[0] stands for that as for current node, the maximum value we could get without current value.
    //! dp[1] stands for that as for current node, the maximum value we could get with current value.

    // ! recursive fomula.
    // if we don't consider current node.
    // the max value = cur->node + left_dp[0] + right_dp[0]
    // left_dp[0] means the maximum value of left sub-tree  without considering current node.
    // right_dp[1] means the maximum value of right sub-tree without considering current node.
    // else
    // max value = max(left_dp[0], left_dp[1]) + max(right_dp[0], right_dp[1])
    // so the next_dp we should return is set to 
    //{cur->node + left_dp[0] + right_dp[0], max(left_dp[0], left_dp[1]) + max(right_dp[0], right_dp[1])}
    if(!root) return 0;
    // if(!root->right && !root->left)
    //     return root->val;
    std::vector<int> result = robTree(root);
    return std::max(result[0], result[1]);
}

std::vector<int>    Solution::robTree(TreeNode* root)
{
    if(!root) return std::vector<int>(2, 0);
    std::vector<int> left_dp = robTree(root->left);
    std::vector<int> right_dp = robTree(root->right);

    //calculate next_dp
    int val_left = root->val + left_dp[0] + right_dp[0];
    int val_right = std::max(left_dp[0], left_dp[1]) +
                    std::max(right_dp[0], right_dp[1]);
    return {val_right, val_left};
}