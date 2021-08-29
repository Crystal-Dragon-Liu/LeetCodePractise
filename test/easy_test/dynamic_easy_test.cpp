#include "gtest/gtest.h"
#include "common/utils.h"
#include "common/solution.h"

TEST(DynamicEasyTest, DISABLED_Test1)
{
    Solution solu;
    int f = solu.fib(4);
    std::cout << f << std::endl;
}

TEST(DynamicEasyTest, DISABLED_Test2)
{
    Solution solu;
    solu.climbStairs(5);
}

TEST(DynamicEasyTest, DISABLED_Test3)
{
    Solution solu;
    std::vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int result = solu.minCostClimbingStairs(cost);
    std::cout << result << std::endl;
}

TEST(DynamicEasyTest, DISABLED_Test4)
{
    Solution solu;
    int result = solu.uniquePaths(3, 7);
    std::cout << result << std::endl;
}

TEST(DynamicEasyTest, DISABLED_Test5)
{
    Solution solu;
    std::vector<std::vector<int> > obstacle{{0,0,0},{0, 1, 0}, {0, 0, 0}};
    int result = solu.uniquePathsWithObstacles(obstacle);
    std::cout << result << std::endl;
}

void test_bag_2d()
{
    // bag test
    // weight vec
    std::vector<int> weight{1, 3, 4};
    std::vector<int> value{15, 20, 30};
    std::vector<std::vector<int> > dp(weight.size() + 1, std::vector<int>(weight.back() + 1, 0));
    for(int j = weight.back(); j >= weight[0]; j--)
        dp[0][j] = dp[0][j - weight[0]] + value[0];
    // traversal for dp
    for(std::size_t i = 1; i < weight.size(); i++)
        for(int j = 0; j <= weight.back(); j++)
            if(j < weight[i]) dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = std::max(dp[i-1][j- weight[i]] + value[i], dp[i-1][j]);
    std::cout << dp[weight.size() - 1][weight.back()] << std::endl;
}

void test_bag_1d()
{
    std::vector<int> weight{1, 3, 4};
    std::vector<int> value{15, 20, 30};
    std::vector<int> dp(weight.back() + 1, 0);
    // for(std::size_t i = 0; i < weight.size();i++){
    //     for(int j = weight.back(); j >= weight[i]; j--)
    //         {
    //             dp[j] = std::max(dp[j - weight[i]] + value[i], dp[j]);
    //         }
    // }
    for(int j = weight.back(); j >= weight[0]; j--)
        for(std::size_t i = 0; i < weight.size();i++){
            {
                dp[j] = std::max(dp[j - weight[0]] + value[i], dp[j]);
            }
    }
    std::cout << dp[weight.back()] << std::endl;
}

TEST(DynamicEasyTest, DISABLED_Test6)
{
    test_bag_2d();
    test_bag_1d();
}

TEST(DynamicEasyTest, DISABLED_Test7)
{
    std::vector<int> nums{1, 5, 11, 5};
    Solution so;
    bool result = so.canPartition(nums);
    EXPECT_EQ(true, result);
}

TEST(DynamicEasyTest, DISABLED_Test8)
{
    std::vector<int> nums{2,7,4,1,8,1};
    Solution so;
    int result = so.lastStoneWeightII(nums);
    EXPECT_EQ(1, result);
}

TEST(DynamicEasyTest, DISABLED_findTargetSumWaysTest)
{
    std::vector<int> nums{1, 1, 1, 1, 1};
    Solution so;
    int result = so.findTargetSumWays(nums, 3);
    EXPECT_EQ(5, result);
}

TEST(DynamicEasyTest, DISABLED_findMaxFormTest)
{
    std::vector<std::string> strs{"10","0001","111001","1","0"};
    Solution so;
    int result = so.findMaxForm(strs, 5, 3);
    EXPECT_EQ(4, result);
}

TEST(DynamicEasyTest, ChangeTest)
{
    std::vector<int> coins{1, 2, 5};
    Solution so;
    int result = so.change(5, coins);
    EXPECT_EQ(4, result);
}