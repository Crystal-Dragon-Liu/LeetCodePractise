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

TEST(DynamicEasyTest, DISABLED_ChangeTest)
{
    std::vector<int> coins{1, 2, 5};
    Solution so;
    int result = so.change(5, coins);
    EXPECT_EQ(4, result);
}

TEST(DynamicEasyTest, DISABLED_combinationSum4Test)
{
    Solution so;
    std::vector<int> nums
    {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,
    200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,
    370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,
    540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,
    710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,
    880,890,900,910,920,930,940,950,960,970,980,990,111};
    int target = 999;
    int result = so.combinationSum4(nums, target);
    EXPECT_EQ(result, 1);
    // EXPECT_EQ(7, so.combinationSum4(nums, target));
}

TEST(DynamicEasyTest, coinChangeTest)
{
    Solution so;
    std::vector<int> coins{1, 2, 5};
    int amount = 11;
    EXPECT_EQ(3, so.coinChange(coins, amount));
    // EXPECT_EQ(7, so.combinationSum4(nums, target));
}

TEST(DynamicEasyTest, numSquareTest)
{
    Solution so;

    EXPECT_EQ(3, so.numSquares(12));
    // EXPECT_EQ(7, so.combinationSum4(nums, target));
}

TEST(DynamicEasyTest, wordBreakTest)
{
    Solution so;
    std::vector<std::string> strVec{"cats", "dog", "sand", "and", "cat"};
    std::string str("catsandog");
    bool result = so.wordBreak(str, strVec);
    EXPECT_EQ(false, result);
    // EXPECT_EQ(7, so.combinationSum4(nums, target));
}