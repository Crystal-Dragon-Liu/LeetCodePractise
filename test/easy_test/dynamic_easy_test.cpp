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

TEST(DynamicEasyTest, Test5)
{
    Solution solu;
    std::vector<std::vector<int> > obstacle{{0,0,0},{0, 1, 0}, {0, 0, 0}};
    int result = solu.uniquePathsWithObstacles(obstacle);
    std::cout << result << std::endl;
}